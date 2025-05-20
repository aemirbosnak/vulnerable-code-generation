//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_COMMAND_SIZE 50

void displayMenu() {
    printf("\n===============================================================\n");
    printf("=                       FTP Client Menu                        =\n");
    printf("===============================================================\n");
    printf("1. Connect to FTP Server\n");
    printf("2. List files on server\n");
    printf("3. Download file\n");
    printf("4. Disconnect from server\n");
    printf("5. Exit\n");
    printf("===============================================================\n\n");
}

int createSocket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("Failed to create socket.\n");
        exit(EXIT_FAILURE);
    }

    return sockfd; 
}

void connectToServer(int sockfd, char* server_address, int port_number) {
    struct sockaddr_in server;
    struct hostent *server_info;

    server_info = gethostbyname(server_address);

    if (server_info == NULL) {
        perror("Host not found.\n");
        exit(EXIT_FAILURE);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port_number);
    memcpy(&server.sin_addr.s_addr, server_info->h_addr, server_info->h_length);

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Failed to connect to server.\n");
        exit(EXIT_FAILURE);
    }
}

void sendCommand(int sockfd, char* buffer) {
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send command to server.\n");
        exit(EXIT_FAILURE);
    }
}

void receiveResponse(int sockfd, char* buffer) {
    if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive response from server.\n");
        exit(EXIT_FAILURE);
    }
}

void listDirectory(int sockfd) {
    char buffer[MAX_BUFFER_SIZE] = {0};

    sendCommand(sockfd, "LIST\r\n");
    receiveResponse(sockfd, buffer);

    printf("\nList of Files on Server:\n%s", buffer);
}

void downloadFile(int sockfd, char* filename) {
    char buffer[MAX_BUFFER_SIZE] = {0};
    char command[MAX_COMMAND_SIZE] = {0};
    FILE *file;

    sprintf(command, "RETR %s\r\n", filename);
    sendCommand(sockfd, command);

    file = fopen(filename, "w");
    if (file == NULL) {
        perror("Failed to open file for writing.\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        int bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);

        if(bytes_received == 0) {
            printf("\nFile download complete.\n");
            break;
        }

        if (bytes_received < 0) {
            perror("Failed to receive file from server.\n");
            exit(EXIT_FAILURE);
        }

        if (fwrite(buffer, sizeof(char), bytes_received, file) < bytes_received) {
            perror("Failed to write to file.\n");
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
}

void disconnectFromServer(int sockfd) {
    sendCommand(sockfd, "QUIT\r\n");
    close(sockfd);
}

int main(int argc, char *argv[]) {
    int sockfd, port_number, choice;
    char server_address[MAX_COMMAND_SIZE];
    char filename[MAX_COMMAND_SIZE];

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter server address: ");
                scanf("%s", server_address);
                printf("Enter port number: ");
                scanf("%d", &port_number);

                sockfd = createSocket();
                connectToServer(sockfd, server_address, port_number);
                char response[MAX_BUFFER_SIZE] = {0};
                receiveResponse(sockfd, response);

                if (strncmp(response, "220", 3) != 0) {
                    perror("Failed to connect to server.\n");
                    exit(EXIT_FAILURE);
                }

                printf("\nConnected to FTP Server successfully!\n");
                break;

            case 2:
                listDirectory(sockfd);
                break;

            case 3:
                printf("\nEnter filename to download: ");
                scanf("%s", filename);
                downloadFile(sockfd, filename);
                break;

            case 4:
                disconnectFromServer(sockfd);
                printf("\nDisconnected from FTP Server successfully!\n");
                break;

            case 5:
                disconnectFromServer(sockfd);
                printf("\nExiting program...\n");
                exit(EXIT_SUCCESS);
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}