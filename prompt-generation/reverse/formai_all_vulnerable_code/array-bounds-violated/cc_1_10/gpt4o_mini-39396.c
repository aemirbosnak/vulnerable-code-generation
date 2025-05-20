//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_BUFFER 4096
#define PORT 80

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

char *get_request(const char *url) {
    char *request = malloc(MAX_BUFFER);
    if (request == NULL) die("Malloc failed");

    snprintf(request, MAX_BUFFER, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", url, url);
    return request;
}

void parse_url(const char *input_url, char *host, char *path) {
    char *url = strdup(input_url);
    char *pos = strstr(url, "://");
    
    if (pos) {
        pos += 3; // move past '://'
    } else {
        pos = url; // no scheme found
    }

    char *slash = strchr(pos, '/');
    if (slash) {
        *slash = '\0'; // Terminate host
        strcpy(path, slash + 1);
    } else {
        strcpy(path, ""); // No path, handle root
    }
    strcpy(host, pos);
    free(url);
}

void handle_response(int sockfd) {
    char response[MAX_BUFFER];
    ssize_t bytes = 0;

    while ((bytes = recv(sockfd, response, sizeof(response)-1, 0)) > 0) {
        response[bytes] = '\0'; // Null-terminate
        printf("%s", response); // Output the response
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <http://example.com/resource>\n", argv[0]);
        return 1;
    }

    char host[256], path[256];
    parse_url(argv[1], host, path);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) die("Failed to create socket");

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr)); // Clear structure

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("93.184.216.34"); // example.com IP

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
        die("Connection failed");

    char *request = get_request(path);
    send(sockfd, request, strlen(request), 0);
    free(request);

    handle_response(sockfd);
    
    close(sockfd);
    return 0;
}