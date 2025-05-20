//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, len;
    struct sockaddr_in address;
    char buffer[BUFFER_SIZE];
    char *username = "anonymous";
    char *password = "anonymous@example.com";

    if (argc!= 2) {
        printf("Usage:./ftp_client <IP address>\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &address.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&address, sizeof(address)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    send(sockfd, username, strlen(username), 0);
    send(sockfd, password, strlen(password), 0);

    while (1) {
        len = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (len <= 0) {
            printf("Error receiving data\n");
            exit(1);
        }
        buffer[len] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}