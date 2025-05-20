//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: visionary
// visionary_ping.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_HOSTNAME_LEN 256

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    char hostname[MAX_HOSTNAME_LEN];
    strncpy(hostname, argv[1], MAX_HOSTNAME_LEN);

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Error: unable to resolve hostname %s\n", hostname);
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr = *((struct in_addr *) host->h_addr);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error: unable to create socket\n");
        return 1;
    }

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("Error: unable to connect to server\n");
        return 1;
    }

    printf("Connection established\n");

    char request[] = "GET / HTTP/1.0\r\n\r\n";
    send(sock, request, strlen(request), 0);

    char response[1024];
    int n = recv(sock, response, sizeof(response), 0);
    if (n < 0) {
        printf("Error: unable to receive response\n");
        return 1;
    }

    printf("Received %d bytes\n", n);
    printf("Response: %s\n", response);

    close(sock);
    return 0;
}