//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int n;

    if (argc!= 3) {
        printf("Usage: %s <IP address> <message>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: socket() failed: %s\n", strerror(errno));
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    server_addr.sin_port = htons(SERVER_PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: connect() failed: %s\n", strerror(errno));
        exit(1);
    }

    printf("Connected to server\n");

    if (send(sockfd, argv[2], strlen(argv[2]), 0) == -1) {
        printf("Error: send() failed: %s\n", strerror(errno));
        exit(1);
    }

    while ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[n] = '\0';
        printf("Received message: %s\n", buffer);
    }

    if (n == -1) {
        printf("Error: recv() failed: %s\n", strerror(errno));
        exit(1);
    }

    close(sockfd);
    return 0;
}