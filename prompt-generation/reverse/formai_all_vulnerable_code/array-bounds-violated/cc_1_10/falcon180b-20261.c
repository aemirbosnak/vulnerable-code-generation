//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    char sendbuffer[BUFFER_SIZE];
    char recvbuffer[BUFFER_SIZE];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Could not create socket\n");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("Error: Could not connect to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    strcpy(sendbuffer, "USER test\r\n");
    send(sockfd, sendbuffer, strlen(sendbuffer), 0);

    strcpy(sendbuffer, "PASS test\r\n");
    send(sockfd, sendbuffer, strlen(sendbuffer), 0);

    strcpy(sendbuffer, "LIST\r\n");
    send(sockfd, sendbuffer, strlen(sendbuffer), 0);

    while (1) {
        bzero(recvbuffer, BUFFER_SIZE);
        n = recv(sockfd, recvbuffer, BUFFER_SIZE, 0);
        if (n <= 0) {
            printf("Error: Could not receive data\n");
            exit(1);
        }
        recvbuffer[n] = '\0';
        printf("%s", recvbuffer);
    }

    close(sockfd);

    return 0;
}