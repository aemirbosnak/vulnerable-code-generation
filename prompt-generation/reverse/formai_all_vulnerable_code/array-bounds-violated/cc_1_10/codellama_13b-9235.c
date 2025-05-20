//Code Llama-13B DATASET v1.0 Category: Website Uptime Monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define PORT 80
#define MAX_BUFFER 1024
#define MAX_URL_LENGTH 100

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <website_url>\n", argv[0]);
        return 1;
    }

    char *url = argv[1];
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        return 1;
    }

    struct hostent *host = gethostbyname(url);
    if (host == NULL) {
        fprintf(stderr, "Error getting host information\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr, host->h_addr_list[0], host->h_length);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    char request[MAX_BUFFER];
    snprintf(request, sizeof(request), "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", url);
    send(sock, request, strlen(request), 0);

    char response[MAX_BUFFER];
    int bytes_read = recv(sock, response, sizeof(response), 0);
    if (bytes_read <= 0) {
        perror("Error reading response");
        return 1;
    }

    response[bytes_read] = '\0';
    printf("Response: %s\n", response);

    close(sock);
    return 0;
}