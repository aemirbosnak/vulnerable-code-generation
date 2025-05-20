//Code Llama-13B DATASET v1.0 Category: Building a HTTP Client ; Style: systematic
// A simple HTTP client program in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    char request[] = "GET / HTTP/1.1\r\nHost: ";
    strcat(request, hostname);
    strcat(request, "\r\nConnection: close\r\n\r\n");
    int request_len = strlen(request);

    if (send(sock, request, request_len, 0) != request_len) {
        printf("Error sending request\n");
        return 1;
    }

    char buffer[1024];
    int bytes_received = recv(sock, buffer, sizeof(buffer), 0);
    if (bytes_received < 0) {
        printf("Error receiving response\n");
        return 1;
    }

    printf("Response:\n%s\n", buffer);

    close(sock);

    return 0;
}