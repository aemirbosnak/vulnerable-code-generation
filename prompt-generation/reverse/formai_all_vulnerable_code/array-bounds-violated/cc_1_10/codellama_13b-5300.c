//Code Llama-13B DATASET v1.0 Category: Building a HTTP Client ; Style: thoughtful
/*
 * Building a HTTP Client example program in C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 80
#define MAX_BUF 1024

int main(int argc, char *argv[]) {
    // Check arguments
    if (argc < 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    // Parse URL
    char *url = argv[1];
    char *host = strtok(url, "/");
    char *path = strtok(NULL, "");

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    // Set up socket address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    inet_pton(AF_INET, host, &addr.sin_addr);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        return 1;
    }

    // Build request
    char buf[MAX_BUF];
    sprintf(buf, "GET %s HTTP/1.1\r\n", path);
    sprintf(buf + strlen(buf), "Host: %s\r\n", host);
    sprintf(buf + strlen(buf), "Connection: close\r\n");
    sprintf(buf + strlen(buf), "\r\n");

    // Send request
    if (send(sock, buf, strlen(buf), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive response
    char response[MAX_BUF];
    int bytes_read = recv(sock, response, MAX_BUF, 0);
    if (bytes_read == -1) {
        perror("recv");
        return 1;
    }
    response[bytes_read] = '\0';

    // Print response
    printf("%s\n", response);

    // Close socket
    close(sock);

    return 0;
}