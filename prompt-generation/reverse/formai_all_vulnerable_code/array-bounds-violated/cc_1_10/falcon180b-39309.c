//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define USERNAME "your_username"
#define PASSWORD "your_password"

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char sendbuf[BUFFER_SIZE], recvbuf[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(110);

    if (inet_pton(AF_INET, "localhost", &servaddr.sin_addr) <= 0) {
        printf("Error converting localhost to IP address\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    sprintf(sendbuf, "USER %s\r\n", USERNAME);
    send(sockfd, sendbuf, strlen(sendbuf), 0);

    while ((n = recv(sockfd, recvbuf, BUFFER_SIZE, 0)) > 0) {
        recvbuf[n] = '\0';
        printf("Received: %s", recvbuf);
    }

    sprintf(sendbuf, "PASS %s\r\n", PASSWORD);
    send(sockfd, sendbuf, strlen(sendbuf), 0);

    while ((n = recv(sockfd, recvbuf, BUFFER_SIZE, 0)) > 0) {
        recvbuf[n] = '\0';
        printf("Received: %s", recvbuf);
    }

    sprintf(sendbuf, "LIST\r\n");
    send(sockfd, sendbuf, strlen(sendbuf), 0);

    while ((n = recv(sockfd, recvbuf, BUFFER_SIZE, 0)) > 0) {
        recvbuf[n] = '\0';
        printf("Received: %s", recvbuf);
    }

    close(sockfd);

    return 0;
}