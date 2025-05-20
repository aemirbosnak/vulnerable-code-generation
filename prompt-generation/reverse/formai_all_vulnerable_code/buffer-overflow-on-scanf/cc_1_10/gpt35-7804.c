//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: single-threaded
// A single-threaded FTP client example program in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXSIZE 1024

void downloadFile(int sockfd, char* filename) {
    char buffer[MAXSIZE];
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Couldn't create file!\n");
        return;
    }
    int bytesReceived;
    while((bytesReceived = recv(sockfd, buffer, MAXSIZE, 0)) > 0) {
        fwrite(buffer, 1, bytesReceived, fp);
    }
    fclose(fp);
    printf("File successfully downloaded!\n");
}

void uploadFile(int sockfd, char* filename) {
    char buffer[MAXSIZE];
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Couldn't open specified file for reading!\n");
        return;
    }
    int bytesRead;
    while((bytesRead = fread(buffer, 1, MAXSIZE, fp)) > 0) {
        send(sockfd, buffer, bytesRead, 0);
    }
    fclose(fp);
    printf("File successfully uploaded!\n");
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        return 1;
    }
    struct sockaddr_in server;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Couldn't create socket!\n");
        return 1;
    }
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    if (connect(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0) {
        printf("Error: Connection failed!\n");
        return 1;
    }
    printf("Connected to server!\n");
    while (1) {
        printf("Enter command (get, put, exit): ");
        char command[10];
        scanf("%s", command);
        if (strcmp(command, "get") == 0) {
            printf("Enter filename to download: ");
            char filename[50];
            scanf("%s", filename);
            send(sockfd, command, sizeof(command), 0);
            send(sockfd, filename, sizeof(filename), 0);
            downloadFile(sockfd, filename);
        } else if (strcmp(command, "put") == 0) {
            printf("Enter filename to upload: ");
            char filename[50];
            scanf("%s", filename);
            send(sockfd, command, sizeof(command), 0);
            send(sockfd, filename, sizeof(filename), 0);
            uploadFile(sockfd, filename);
        } else if (strcmp(command, "exit") == 0) {
            send(sockfd, command, sizeof(command), 0);
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid command!\n");
        }
    }
    close(sockfd);
    return 0;
}