//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    int port;
    char ip[16];
    char *host;
    char *request;
    char *url;
    int len;
    char buffer[BUFFER_SIZE];
    int bytes_read;
    int ret;

    if (argc!= 3) {
        printf("Usage: %s <host> <url>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    url = argv[2];

    ret = inet_pton(AF_INET, host, &server_addr.sin_addr);

    if (ret == 0) {
        printf("Invalid host address\n");
        exit(1);
    }

    port = 80;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_ntop(AF_INET, &server_addr.sin_addr, ip, sizeof(ip));

    printf("Connecting to %s:%d\n", ip, port);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", url, host);

    send(sockfd, request, strlen(request), 0);

    while (1) {
        bytes_read = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (bytes_read <= 0) {
            break;
        }

        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);

    return 0;
}