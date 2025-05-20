//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, port;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s host port\n", argv[0]);
        return 1;
    }

    port = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
        return 1;
    }

    fprintf(stdout, "Connected to server.\n");

    char *request = "GET / HTTP/1.1\r\nHost: example.com\r\nConnection: close\r\n\r\n";
    send(sockfd, request, strlen(request), 0);

    while (1) {
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            fprintf(stdout, "Connection closed.\n");
            break;
        }

        buffer[bytes_received] = '\0';
        fprintf(stdout, "%s", buffer);
    }

    close(sockfd);
    return 0;
}