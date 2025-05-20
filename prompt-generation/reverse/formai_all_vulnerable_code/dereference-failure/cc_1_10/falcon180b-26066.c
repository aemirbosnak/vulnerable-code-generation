//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    char send_buffer[BUFFER_SIZE], recv_buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error_handling("socket failed");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error_handling("connect failed");
    }

    printf("Connected to server\n");

    while (1) {
        printf("Enter message to send: ");
        fgets(send_buffer, BUFFER_SIZE, stdin);
        send(sockfd, send_buffer, strlen(send_buffer), 0);

        memset(recv_buffer, 0, BUFFER_SIZE);
        if (recv(sockfd, recv_buffer, BUFFER_SIZE, 0) <= 0) {
            error_handling("recv failed");
        }
        printf("Received message: %s\n", recv_buffer);
    }

    close(sockfd);
    return 0;
}

void error_handling(char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}