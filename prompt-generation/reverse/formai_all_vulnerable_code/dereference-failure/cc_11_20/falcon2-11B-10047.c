//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <netinet/tcp.h>

#define PORT 8080

int main(int argc, char *argv[])
{
    int sockfd, n;
    struct sockaddr_in serverAddr;
    struct sockaddr_in clientAddr;
    struct hostent *server;
    char buffer[1024];
    int content_length;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <server-ip> <server-port>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error opening socket\n");
        exit(1);
    }

    memset((char *)&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(atoi(argv[2]));
    memcpy((char *)&serverAddr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        fprintf(stderr, "Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server on %s:%s\n", inet_ntoa(serverAddr.sin_addr), ntohs(serverAddr.sin_port));

    while (1) {
        n = read(sockfd, buffer, sizeof(buffer));
        if (n <= 0) {
            fprintf(stderr, "Error reading from socket\n");
            exit(1);
        }

        printf("Received: %s\n", buffer);

        content_length = strtol(buffer, NULL, 16);
        if (content_length == 0) {
            break;
        }

        printf("Content-Length: %d\n", content_length);

        memset(buffer, 0, sizeof(buffer));

        n = write(sockfd, "GET / HTTP/1.1\r\n", 27);
        if (n < 0) {
            fprintf(stderr, "Error writing to socket\n");
            exit(1);
        }

        n = write(sockfd, "Host: ", 6);
        if (n < 0) {
            fprintf(stderr, "Error writing to socket\n");
            exit(1);
        }

        memcpy(buffer, argv[2], strlen(argv[2]));
        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) {
            fprintf(stderr, "Error writing to socket\n");
            exit(1);
        }

        n = write(sockfd, "\r\n", 2);
        if (n < 0) {
            fprintf(stderr, "Error writing to socket\n");
            exit(1);
        }

        n = write(sockfd, "\r\n", 2);
        if (n < 0) {
            fprintf(stderr, "Error writing to socket\n");
            exit(1);
        }

        n = read(sockfd, buffer, sizeof(buffer));
        if (n <= 0) {
            fprintf(stderr, "Error reading from socket\n");
            exit(1);
        }

        printf("Sent: %s\n", buffer);

        n = write(sockfd, "\r\n", 2);
        if (n < 0) {
            fprintf(stderr, "Error writing to socket\n");
            exit(1);
        }

        n = write(sockfd, "\r\n", 2);
        if (n < 0) {
            fprintf(stderr, "Error writing to socket\n");
            exit(1);
        }

        n = read(sockfd, buffer, sizeof(buffer));
        if (n <= 0) {
            fprintf(stderr, "Error reading from socket\n");
            exit(1);
        }

        printf("Received: %s\n", buffer);
    }

    return 0;
}