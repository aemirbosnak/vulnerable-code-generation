//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 80
#define MAX_BUF_SIZE 512

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[MAX_BUF_SIZE];
    char host[MAX_BUF_SIZE];

    printf("Enter a hostname: ");
    scanf("%s", host);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("ERROR opening socket\n");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, host, &serv_addr.sin_addr) <= 0) {
        printf("ERROR, invalid address/dotted-decimal\n");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("ERROR connecting\n");
        return 1;
    }

    printf("Successfully connected to %s:%d\n", host, PORT);

    n = read(sockfd, buffer, MAX_BUF_SIZE);
    if (n < 0) {
        printf("ERROR reading from socket\n");
        return 1;
    }
    buffer[n] = '\0';
    printf("Received: %s\n", buffer);

    close(sockfd);

    return 0;
}