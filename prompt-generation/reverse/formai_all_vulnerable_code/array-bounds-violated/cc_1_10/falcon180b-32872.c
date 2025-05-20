//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char *server_ip = "192.168.1.1";
    int server_port = 80;
    char buffer[BUF_SIZE];
    int bytes_received;
    char *http_request = "GET / HTTP/1.1\r\nHost: 192.168.1.1\r\nConnection: close\r\n\r\n";
    int http_request_len = strlen(http_request);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Socket creation failed\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection failed\n");
        exit(1);
    }

    send(sockfd, http_request, http_request_len, 0);

    while (TRUE) {
        bytes_received = recv(sockfd, buffer, BUF_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}