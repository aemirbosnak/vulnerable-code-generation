//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define SERVER "localhost"
#define PORT 25

int main() {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char sendbuffer[BUFFER_SIZE];
    char recvbuffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, SERVER, &serv_addr.sin_addr);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while(1) {
        printf("Enter message to send: ");
        fgets(sendbuffer, BUFFER_SIZE, stdin);
        sendbuffer[strcspn(sendbuffer, "\n")] = '\0'; // remove newline character

        send(sockfd, sendbuffer, strlen(sendbuffer), 0); // send message to server

        memset(recvbuffer, 0, BUFFER_SIZE);
        n = recv(sockfd, recvbuffer, BUFFER_SIZE, 0); // receive response from server
        recvbuffer[n] = '\0'; // add null terminator

        printf("Received response: %s\n", recvbuffer);
    }

    close(sockfd);
    return 0;
}