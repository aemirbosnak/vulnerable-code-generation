//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX 100

int main() {
    int sockfd, n;
    char sendData[MAX];
    char recvData[MAX];
    struct sockaddr_in servAddr;

    printf("Enter IP address: ");
    scanf("%s", sendData);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error: socket failed\n");
        exit(0);
    }

    servAddr.sin_family = AF_INET;
    inet_pton(AF_INET, sendData, &servAddr.sin_addr);
    servAddr.sin_port = htons(7);

    if (connect(sockfd, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0) {
        printf("Error: connect failed\n");
        exit(0);
    }

    printf("Connected to server\n");

    while (1) {
        printf("Enter message to send: ");
        scanf("%s", sendData);

        if (send(sockfd, sendData, strlen(sendData), 0) < 0) {
            printf("Error: send failed\n");
            exit(0);
        }

        if (recv(sockfd, recvData, MAX, 0) < 0) {
            printf("Error: recv failed\n");
            exit(0);
        }

        printf("Received message: %s\n", recvData);
    }

    close(sockfd);

    return 0;
}