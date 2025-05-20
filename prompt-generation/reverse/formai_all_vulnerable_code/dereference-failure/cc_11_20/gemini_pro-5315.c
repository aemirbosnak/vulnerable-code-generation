//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <time.h>
#include <unistd.h>

#define MAX_URL_LENGTH 256
#define MAX_RESPONSE_LENGTH 1024
#define DEFAULT_PORT 80
#define DEFAULT_INTERVAL 60

int main(int argc, char **argv) {
    // Parse command-line arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <URL> [<port>] [<interval>]\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *url = argv[1];
    int port = DEFAULT_PORT;
    if (argc >= 3) {
        port = atoi(argv[2]);
    }

    int interval = DEFAULT_INTERVAL;
    if (argc >= 4) {
        interval = atoi(argv[3]);
    }

    // Parse URL
    char *host = NULL;
    char *path = NULL;

    char *colon = strchr(url, ':');
    if (colon != NULL) {
        *colon = '\0';
        host = url;
        path = colon + 1;
    } else {
        host = url;
        path = "/";
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to server
    struct sockaddr_in sockaddr;
    memset(&sockaddr, 0, sizeof(sockaddr));
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &sockaddr.sin_addr) != 1) {
        fprintf(stderr, "Invalid host: %s\n", host);
        return EXIT_FAILURE;
    }
    if (connect(sockfd, (struct sockaddr *)&sockaddr, sizeof(sockaddr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send HTTP request
    char request[MAX_URL_LENGTH + 16];
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive HTTP response
    char response[MAX_RESPONSE_LENGTH];
    int response_length = recv(sockfd, response, sizeof(response), 0);
    if (response_length == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check HTTP response status
    char *status_line = strtok(response, "\r\n");
    if (status_line == NULL || strncmp(status_line, "HTTP/1.1 200 OK", 15) != 0) {
        fprintf(stderr, "Non-200 HTTP response: %s\n", status_line);
        return EXIT_FAILURE;
    }

    // Print uptime
    time_t current_time = time(NULL);
    printf("Uptime at %s: OK\n", ctime(&current_time));

    // Close socket
    close(sockfd);

    return EXIT_SUCCESS;
}