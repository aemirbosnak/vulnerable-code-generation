//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function to connect to FTP Server
int connectToFTP(char* server_address, int server_port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error in creating socket\n");
        return -1;
    }
    
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(server_address);
    server.sin_port = htons(server_port);
    
    if (connect(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0) {
        printf("Error in connection\n");
        return -1;
    }
    
    char receiveBuffer[BUFFER_SIZE];
    memset(receiveBuffer, 0, BUFFER_SIZE);
    
    if (recv(sockfd, receiveBuffer, BUFFER_SIZE, 0) < 0) {
        printf("Error in receiving server response\n");
        return -1;
    }
    
    printf("%s\n", receiveBuffer);
    
    return sockfd;
}

// Function to send commands to FTP Server
int sendCommand(int sockfd, char* command) {
    char sendBuffer[BUFFER_SIZE];
    memset(sendBuffer, 0, BUFFER_SIZE);
    strcpy(sendBuffer, command);
    
    if (send(sockfd, sendBuffer, strlen(sendBuffer), 0) < 0) {
        printf("Error in sending command to server\n");
        return -1;
    }
    
    char receiveBuffer[BUFFER_SIZE];
    memset(receiveBuffer, 0, BUFFER_SIZE);
    
    if (recv(sockfd, receiveBuffer, BUFFER_SIZE, 0) < 0) {
        printf("Error in receiving server response\n");
        return -1;
    }
    
    printf("%s\n", receiveBuffer);
    
    return 0;
}

// Function to download file from FTP Server
int downloadFile(int sockfd, char* filename) {
    char command[BUFFER_SIZE];
    memset(command, 0, BUFFER_SIZE);
    sprintf(command, "RETR %s\n", filename);
    
    if (sendCommand(sockfd, command) < 0) {
        printf("Error in sending download command\n");
        return -1;
    }
    
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error in creating new file\n");
        return -1;
    }
    
    char buffer[BUFFER_SIZE];
    int receiveCount;
    
    while ((receiveCount = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, receiveCount, fp);
    }
    
    fclose(fp);
    
    if (receiveCount < 0) {
        printf("Error in receiving file from server\n");
        return -1;
    }
    
    return 0;
}

int main() {
    char server_address[20];
    int server_port;
    char filename[100];
    
    printf("Enter FTP Server Address: ");
    scanf("%s", server_address);
    
    printf("Enter FTP Server Port: ");
    scanf("%d", &server_port);
    
    int sockfd = connectToFTP(server_address, server_port);
    if (sockfd < 0) {
        printf("Error in connecting to FTP Server\n");
        return -1;
    }
    
    char username[20];
    char password[20];
    
    printf("Enter Username: ");
    scanf("%s", username);
    
    printf("Enter Password: ");
    scanf("%s", password);
    
    char command[BUFFER_SIZE];
    memset(command, 0, BUFFER_SIZE);
    sprintf(command, "USER %s\n", username);
    
    if (sendCommand(sockfd, command) < 0) {
        printf("Error in sending username\n");
        return -1;
    }
    
    memset(command, 0, BUFFER_SIZE);
    sprintf(command, "PASS %s\n", password);
    
    if (sendCommand(sockfd, command) < 0) {
        printf("Error in sending password\n");
        return -1;
    }
    
    printf("Enter File Name to Download: ");
    scanf("%s", filename);
    
    if (downloadFile(sockfd, filename) < 0) {
        printf("Error in downloading file\n");
        return -1;
    }
    
    printf("File Downloaded Successfully!\n");
    
    close(sockfd);
    
    return 0;
}