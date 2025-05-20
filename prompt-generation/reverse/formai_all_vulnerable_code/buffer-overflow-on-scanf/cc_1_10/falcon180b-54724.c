//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main() {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char sendbuf[BUFFER_SIZE], recvbuf[BUFFER_SIZE];
    int len;

    printf("Enter the port number: ");
    scanf("%d", &portno);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error: Unable to create socket\n");
        exit(1);
    }

    printf("Connecting to remote server...\n");
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Unable to connect\n");
        exit(1);
    }

    printf("Connected to remote server\n");

    while (1) {
        memset(sendbuf, 0, BUFFER_SIZE);
        memset(recvbuf, 0, BUFFER_SIZE);

        printf("Enter command: ");
        fgets(sendbuf, BUFFER_SIZE, stdin);

        if (strcmp(sendbuf, "exit") == 0) {
            break;
        }

        len = strlen(sendbuf);
        send(sockfd, sendbuf, len, 0);
        recv(sockfd, recvbuf, BUFFER_SIZE, 0);
        printf("Received: %s\n", recvbuf);
    }

    close(sockfd);
    exit(0);
}