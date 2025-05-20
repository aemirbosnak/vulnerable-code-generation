//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_BUF_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;
    char send_buf[MAX_BUF_SIZE];
    char recv_buf[MAX_BUF_SIZE];
    int len;
    FILE *fp;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Send data to server
    strcpy(send_buf, "Hello, World!");
    len = strlen(send_buf);
    if (send(sockfd, send_buf, len, 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // Receive data from server
    len = recv(sockfd, recv_buf, MAX_BUF_SIZE, 0);
    if (len < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    recv_buf[len] = '\0';
    printf("Received data: %s\n", recv_buf);

    // Close socket
    close(sockfd);

    return 0;
}