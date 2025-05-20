//Code Llama-13B DATASET v1.0 Category: Building a HTTP Client ; Style: active
// Building a HTTP Client example program in an active style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_BUF 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char *url = argv[1];
    char *host, *path;
    int port;

    // Parse the URL
    if (sscanf(url, "http://%[^:]:%d/%s", host, &port, path) != 3) {
        printf("Invalid URL\n");
        return 1;
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Set the address and port number
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);

    // Get the IP address of the host
    struct hostent *host_info = gethostbyname(host);
    if (!host_info) {
        printf("Failed to get IP address of %s\n", host);
        return 1;
    }
    addr.sin_addr.s_addr = *(unsigned long *)host_info->h_addr_list[0];

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send the HTTP request
    char buf[MAX_BUF];
    sprintf(buf, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);
    if (write(sock, buf, strlen(buf)) < 0) {
        perror("write");
        return 1;
    }

    // Read the HTTP response
    int n = read(sock, buf, MAX_BUF);
    if (n < 0) {
        perror("read");
        return 1;
    }
    buf[n] = '\0';
    printf("%s\n", buf);

    // Close the socket
    close(sock);

    return 0;
}