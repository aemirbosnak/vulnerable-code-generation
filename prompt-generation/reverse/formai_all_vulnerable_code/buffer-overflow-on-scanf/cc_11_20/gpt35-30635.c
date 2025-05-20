//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAXSIZE 1024    //Maximum buffer size

int main(int argc, char *argv[]) {
    
    if(argc < 3) {
        printf("Usage: ./ftpclient hostname port\n");
        exit(1);
    }

    char* serverName = argv[1];
    int port = atoi(argv[2]);

    struct hostent* host = gethostbyname(serverName);   //Get host by name

    if(!host) {
        printf("Error: Could not find host %s\n", serverName);
        exit(1);
    }

    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));    //Clear server address

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr = *((struct in_addr*) host->h_addr);  //Set server address

    int sock = socket(AF_INET, SOCK_STREAM, 0);    //Create socket

    if(sock < 0) {
        printf("Error: Failed to create socket!\n");
        exit(1);
    }

    //Connect to FTP Server
    if(connect(sock, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        printf("Connection Failed!\n");
        exit(1);
    }

    printf("Connected to FTP Server!\n");

    char buffer[MAXSIZE];
    int data_socket;
    int option;
    int bytesReceived;
    FILE* file;

    while(1) {

        printf("Enter command (get/put/quit): ");
        scanf("%s", buffer);    //Get command from user

        //Handle get command
        if(strcmp(buffer, "get") == 0) {

            char fileName[100];
            printf("Enter File Name: ");
            scanf("%s", fileName);

            //Send GET Command to Server
            send(sock, buffer, strlen(buffer), 0);
            send(sock, fileName, strlen(fileName), 0);

            //Create Data Socket
            data_socket = socket(AF_INET, SOCK_STREAM, 0);
            connect(data_socket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

            //Receive File
            file = fopen(fileName, "wb");
            if(file == NULL) {
                printf("Error: Could not open file!\n");
                continue;
            }

            while((bytesReceived = recv(data_socket, buffer, MAXSIZE, 0)) > 0) {
                fwrite(buffer, 1, bytesReceived, file);
            }
            fclose(file);

            printf("File Downloaded Successfully!\n");
            close(data_socket);
        }

        //Handle put command
        else if(strcmp(buffer, "put") == 0) {

            char fileName[100];
            printf("Enter File Name: ");
            scanf("%s", fileName);

            //Send PUT Command to Server
            send(sock, buffer, strlen(buffer), 0);
            send(sock, fileName, strlen(fileName), 0);

            //Create Data Socket
            data_socket = socket(AF_INET, SOCK_STREAM, 0);
            connect(data_socket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

            //Send File
            file = fopen(fileName, "rb");
            if(file == NULL) {
                printf("Error: Could not open file!\n");
                continue;
            }

            while((bytesReceived = fread(buffer, 1, MAXSIZE, file)) > 0) {
                send(data_socket, buffer, bytesReceived, 0);
            }
            fclose(file);

            printf("File Uploaded Successfully!\n");
            close(data_socket);
        }

        //Handle quit command
        else if(strcmp(buffer, "quit") == 0) {
            printf("Quitting FTP Client...\n");
            send(sock, buffer, strlen(buffer), 0);
            break;
        }

        //Invalid command
        else {
            printf("Error: Invalid Command!\n");
        }
    }

    close(sock);
    return 0;
}