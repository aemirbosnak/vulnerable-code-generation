//Falcon-180B DATASET v1.0 Category: Networking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUF_SIZE 1024
#define PORT 8080

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;
    char send_buffer[BUF_SIZE];
    char recv_buffer[BUF_SIZE];
    int len, n;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Send data to server
    sprintf(send_buffer, "Hello from client %d", getpid());
    len = strlen(send_buffer);
    if (send(sockfd, send_buffer, len, 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // Receive data from server
    if ((n = recv(sockfd, recv_buffer, BUF_SIZE, 0)) < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    recv_buffer[n] = '\0';
    printf("Server response: %s\n", recv_buffer);

    // Close socket
    close(sockfd);

    return 0;
}