//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>

#define TRUE    1
#define FALSE   0
#define PORT    7

#define MAXLINE 1024

int main(int argc, char *argv[]) {
    int sockfd, numbytes;
    char sendline[MAXLINE], recvline[MAXLINE];
    struct sockaddr_in servaddr;
    int opt = TRUE;
    int addrlen = sizeof(servaddr);

    printf("Welcome to the Network Ping Test program!\n");
    printf("Enter the IP address of the host you want to ping: ");
    scanf("%s", sendline);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    printf("Socket created successfully!\n");

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(sendline);
    servaddr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&servaddr, addrlen) < 0) {
        printf("Connection failed\n");
        exit(1);
    }

    printf("Connected to host successfully!\n");

    while (opt) {
        printf("Enter your message to send: ");
        scanf("%s", sendline);

        if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
            printf("Error sending message\n");
            exit(1);
        }

        printf("Message sent successfully!\n");

        numbytes = recv(sockfd, recvline, MAXLINE, 0);

        if (numbytes <= 0) {
            printf("Error receiving message\n");
            exit(1);
        }

        printf("Received message: %s\n", recvline);
    }

    close(sockfd);
    printf("Connection closed successfully!\n");

    return 0;
}