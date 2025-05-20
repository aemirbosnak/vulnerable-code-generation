//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    int sockfd;
    struct sockaddr_in serveraddr;
    char buffer[BUFFER_SIZE];

    if (argc!= 4) {
        printf("Usage:./ftp_client <IP_Address> <Username> <Password>\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &serveraddr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to server\n");

    char username[50];
    strcpy(username, argv[2]);
    char password[50];
    strcpy(password, argv[3]);

    send(sockfd, username, strlen(username), 0);
    send(sockfd, password, strlen(password), 0);

    char response[BUFFER_SIZE];
    memset(response, 0, BUFFER_SIZE);
    recv(sockfd, response, BUFFER_SIZE, 0);
    printf("Server response: %s\n", response);

    close(sockfd);

    return 0;
}