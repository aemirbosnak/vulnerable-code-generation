//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define CHECK_INTERVAL 5

void check_website(const char *hostname) {
    struct hostent *host;
    struct sockaddr_in server_addr;
    int sock;
    char request[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    int bytes_received;

    // Resolve the hostname
    if ((host = gethostbyname(hostname)) == NULL) {
        perror("gethostbyname");
        return;
    }

    // Creating a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return;
    }

    // Set up the server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    // Connect to the server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "[%ld] %s is down or unreachable.\n", time(NULL), hostname);
        close(sock);
        return;
    }

    // Sending a basic HTTP GET request
    snprintf(request, sizeof(request), "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", hostname);
    send(sock, request, strlen(request), 0);

    // Reading the response
    bytes_received = recv(sock, response, sizeof(response) - 1, 0);
    if (bytes_received < 0) {
        perror("recv");
        close(sock);
        return;
    }

    response[bytes_received] = '\0'; // Null terminate the response
    fprintf(stdout, "[%ld] %s is up. Response received:\n%s\n", time(NULL), hostname, response);

    // Clean up
    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];

    while (1) {
        check_website(hostname);
        sleep(CHECK_INTERVAL); // wait for the specified interval before checking again
    }

    return 0;
}