//FormAI DATASET v1.0 Category: Image Editor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ctype.h>
#include <unistd.h>

#include <errno.h>
#include <fcntl.h>

#include <netinet/in.h>
#include <netinet/tcp.h>

#define BUFFER_LENGTH 1024

#define ERROR_VALUE (-1)

#define SAVE_COMMAND "save"

void lowercase(char* inputString){
    int i;
    for(i = 0; i < strlen(inputString); i++){
        inputString[i] = tolower(inputString[i]);
    }
}

void swap(unsigned char* a, unsigned char* b){
    unsigned char temp = *a;
    *a = *b;
    *b = temp;
}

int readFromClient(int fd, char* buffer, size_t bufferSize){
    memset(buffer, 0, bufferSize);
    ssize_t bytesRead = read(fd, buffer, bufferSize);

    if(bytesRead == ERROR_VALUE){
        fprintf(stderr, "Error: %s\n", strerror(errno));
    }

    return bytesRead;
}

int writeToClient(int fd, const char* buffer, size_t bufferSize){
    ssize_t bytesSent;

    bytesSent = write(fd, buffer, bufferSize);

    if(bytesSent < 0){
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return ERROR_VALUE;
    }

    return bytesSent;
}

void grayscale(unsigned char* pixel){
    int intensity = (pixel[0] + pixel[1] + pixel[2]) / 3;
    pixel[0] = intensity;
    pixel[1] = intensity;
    pixel[2] = intensity;
}

void flipHorizontal(unsigned char* buffer, int width, int height){
    int rowLength = width * 3;

    int i, j;
    for(i = 0; i < height; i++){
        for(j = 0; j < rowLength/2; j += 3){
            swap(buffer + (i * rowLength) + j, buffer + (i * rowLength) + (rowLength - j - 3));
            swap(buffer + (i * rowLength) + j + 1, buffer + (i * rowLength) + (rowLength - j - 3) + 1);
            swap(buffer + (i * rowLength) + j + 2, buffer + (i * rowLength) + (rowLength - j - 3) + 2);
        }
    }
}

void handleClientCommand(int clientSocket, unsigned char* buffer, int width, int height, char* command){
    lowercase(command);

    if(strcmp(command, "grayscale") == 0){
        int i, j;
        for(i = 0; i < height; i++){
            for(j = 0; j < width * 3; j += 3){
                grayscale(&buffer[i * width * 3 + j]);
            }
        }
    } else if(strcmp(command, "fliph") == 0){
        flipHorizontal(buffer, width, height);
    } else if(strcmp(command, SAVE_COMMAND) == 0){
        char fileName[BUFFER_LENGTH];
        printf("Enter file name: ");
        scanf("%s", fileName);

        int fd = open(fileName, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

        if(fd == ERROR_VALUE){
            printf("Could not open file for writing: %s\n", strerror(errno));
            return;
        }

        ssize_t bytesWritten = write(fd, buffer, width * height * 3);

        if(bytesWritten < 0){
            printf("Error while writing: %s\n", strerror(errno));
            close(fd);
            return;
        }

        printf("%zd bytes written to file.\n", bytesWritten);
        close(fd);
    }
}

void editImage(int clientSocket, unsigned char* buffer, int width, int height){
    char command[BUFFER_LENGTH];
    char commandBuffer[BUFFER_LENGTH];

    while(1){
        printf("Enter command: ");
        scanf("%s", command);

        if(strcmp(command, SAVE_COMMAND) == 0){
            handleClientCommand(clientSocket, buffer, width, height, command);
            break;
        }

        sprintf(commandBuffer, "image %d %d\n", width, height);
        writeToClient(clientSocket, commandBuffer, strlen(commandBuffer));

        handleClientCommand(clientSocket, buffer, width, height, command);

        writeToClient(clientSocket, (char*)buffer, width*height*3);
    }
}

int main(int argc, char** argv){
    /* Create image buffer */
    int width = 640;
    int height = 480;
    unsigned char buffer[width * height * 3];

    int sockfd, newsockfd, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0){
        fprintf(stderr, "Error opening socket: %s\n", strerror(errno));
        return ERROR_VALUE;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    portno = 42001;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
        fprintf(stderr, "Error binding socket: %s\n", strerror(errno));
        return ERROR_VALUE;
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

    if(newsockfd < 0){
        fprintf(stderr, "Error accepting client: %s\n", strerror(errno));
        return ERROR_VALUE;
    }

    printf("Connected to client!\n");

    editImage(newsockfd, buffer, width, height);

    close(newsockfd);
    close(sockfd);

    return 0;
}