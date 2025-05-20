//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 80

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char sendbuf[BUFFER_SIZE], recvbuf[BUFFER_SIZE];
    int len;
    char *host;
    int port;

    if (argc < 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    port = atoi(argv[2]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(1);
    }

    printf("Connecting to %s:%d\n", host, port);

    // Connect to server
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    inet_pton(AF_INET, host, &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    printf("Connected to %s:%d\n", host, port);

    // Send HTTP GET request
    sprintf(sendbuf, "GET / HTTP/1.0\r\nHost: %s\r\n\r\n", host);
    send(sockfd, sendbuf, strlen(sendbuf), 0);

    // Receive response
    len = 0;
    while ((n = recv(sockfd, recvbuf + len, BUFFER_SIZE - len, 0)) > 0) {
        len += n;
    }
    recvbuf[len] = '\0';

    printf("Received response:\n%s", recvbuf);

    // Close socket
    close(sockfd);

    return 0;
}