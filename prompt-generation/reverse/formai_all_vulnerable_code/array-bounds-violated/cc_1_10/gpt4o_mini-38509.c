//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define PORT 80

void check_website(const char *hostname);
void log_status(const char *hostname, const char *status);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <interval_in_seconds>\n", argv[0]);
        return 1;
    }

    const char *hostname = argv[1];
    int interval = atoi(argv[2]);

    while (1) {
        check_website(hostname);
        sleep(interval);
    }

    return 0;
}

void check_website(const char *hostname) {
    int sock;
    struct sockaddr_in server;
    char request[BUFFER_SIZE], response[BUFFER_SIZE];
    int bytes_read;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr(hostname);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        log_status(hostname, "OFFLINE");
        close(sock);
        return;
    }

    // Create HTTP GET request
    snprintf(request, sizeof(request), "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", hostname);
    
    // Send request
    send(sock, request, strlen(request), 0);

    // Read response
    bytes_read = recv(sock, response, sizeof(response) - 1, 0);
    response[bytes_read] = '\0';

    // Check response
    if (strstr(response, "200 OK") != NULL) {
        log_status(hostname, "ONLINE");
    } else {
        log_status(hostname, "OFFLINE");
    }

    // Close the socket
    close(sock);
}

void log_status(const char *hostname, const char *status) {
    time_t now;
    time(&now);
    struct tm *timeinfo = localtime(&now);
    
    char formatted_time[100];
    strftime(formatted_time, sizeof(formatted_time), "%Y-%m-%d %H:%M:%S", timeinfo);

    printf("[%s] %s is %s\n", formatted_time, hostname, status);
}