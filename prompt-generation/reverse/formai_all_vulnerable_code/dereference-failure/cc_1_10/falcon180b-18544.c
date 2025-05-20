//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

#define BUF_SIZE 1024

int main() {
    int sockfd = -1;
    struct sockaddr_in server_addr;
    char *host = "localhost";
    char *port = "8080";
    char buf[BUF_SIZE];
    int len;
    int ret;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));

    // Resolve hostname
    struct hostent *hostent = gethostbyname(host);
    if (hostent == NULL) {
        fprintf(stderr, "Host not found\n");
        exit(1);
    }

    // Fill in server address
    memcpy(&server_addr.sin_addr, hostent->h_addr, hostent->h_length);

    // Connect to server
    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        perror("connect");
        exit(1);
    }

    // Send HTTP request
    char *request = "GET / HTTP/1.0\r\nHost: localhost\r\nConnection: close\r\n\r\n";
    len = strlen(request);
    ret = send(sockfd, request, len, 0);
    if (ret == -1) {
        perror("send");
        exit(1);
    }

    // Receive HTTP response
    memset(buf, 0, BUF_SIZE);
    len = 0;
    while ((ret = recv(sockfd, buf + len, BUF_SIZE - len, 0)) > 0) {
        len += ret;
        if (len >= BUF_SIZE) {
            buf[BUF_SIZE - 1] = '\0';
            fprintf(stdout, "%.*s", len, buf);
            memset(buf, 0, BUF_SIZE);
            len = 0;
        }
    }
    if (ret == 0) {
        fprintf(stdout, "Connection closed by server\n");
    } else {
        perror("recv");
    }

    // Close socket
    close(sockfd);
    return 0;
}