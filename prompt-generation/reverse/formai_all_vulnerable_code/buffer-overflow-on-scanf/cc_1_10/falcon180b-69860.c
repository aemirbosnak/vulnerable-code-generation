//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void main() {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char sendbuffer[BUFFER_SIZE];
    char recvbuffer[BUFFER_SIZE];
    int n;

    printf("Enter SMTP Server IP Address: ");
    scanf("%s", &serv_addr.sin_addr.s_addr);

    printf("Enter SMTP Server Port Number: ");
    scanf("%d", &portno);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(0);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(0);
    }

    printf("Connected to SMTP server\n");

    while (1) {
        printf("\nEnter message to send: ");
        fgets(sendbuffer, BUFFER_SIZE, stdin);
        sendbuffer[strcspn(sendbuffer, "\r")] = '\0';
        send(sockfd, sendbuffer, strlen(sendbuffer), 0);

        memset(recvbuffer, 0, BUFFER_SIZE);
        n = recv(sockfd, recvbuffer, BUFFER_SIZE, 0);

        if (n <= 0) {
            printf("Connection closed by server\n");
            exit(0);
        }

        printf("Received response: %s", recvbuffer);
    }

    close(sockfd);
}