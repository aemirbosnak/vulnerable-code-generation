//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAX_BUFFER_SIZE 1024

typedef struct http_response {
    char *status_code;
    char *body;
    int content_length;
} http_response;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    char *url = argv[1];
    char http_method[] = "GET";

    // Parse host and path from URL
    char *host = url;
    char *path = strstr(url, "/");
    if (path == NULL) {
        path = "/";
    } else {
        *path = '\0';
        path++;
    }

    // Get host information
    struct hostent *hostinfo = gethostbyname(host);
    if (hostinfo == NULL) {
        printf("Error: Unable to resolve host '%s'\n", host);
        return 1;
    }

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error: Unable to create socket\n");
        return 1;
    }

    // Create server address
    struct sockaddr_in serveraddr;
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr = *(struct in_addr *) hostinfo->h_addr;
    serveraddr.sin_port = htons(80);

    // Connect to server
    if (connect(sock, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) {
        printf("Error: Unable to connect to server\n");
        return 1;
    }

    // Send HTTP request
    char http_request[MAX_BUFFER_SIZE];
    snprintf(http_request, sizeof(http_request), "%s %s HTTP/1.1\r\n"
            "Host: %s\r\n"
            "Connection: close\r\n\r\n", http_method, path, host);

    if (send(sock, http_request, strlen(http_request), 0) < 0) {
        printf("Error: Unable to send HTTP request\n");
        return 1;
    }

    // Receive HTTP response
    char http_response_buffer[MAX_BUFFER_SIZE];
    bool content_length_found = false;
    http_response response;
    response.body = malloc(0);
    int response_size = 0;
    while (true) {
        int bytes_received = recv(sock, http_response_buffer, MAX_BUFFER_SIZE, 0);
        if (bytes_received < 0) {
            printf("Error: Unable to receive HTTP response\n");
            return 1;
        } else if (bytes_received == 0) {
            break;
        }

        // Find status code
        if (response.status_code == NULL) {
            response.status_code = malloc(4);
            strncpy(response.status_code, http_response_buffer+9, 3);
            response.status_code[3] = '\0';
        }

        // Find content length
        if (!content_length_found) {
            char *content_length_start = strstr(http_response_buffer, "Content-Length:");
            if (content_length_start != NULL) {
                char *content_length_end = strstr(content_length_start, "\r\n");
                char content_length_str[10];
                strncpy(content_length_str, content_length_start+16, content_length_end-content_length_start-16);
                content_length_found = true;
                response.content_length = atoi(content_length_str);
                response.body = realloc(response.body, response.content_length);
            }
        }

        // Copy data to response buffer
        memcpy(response.body+response_size, http_response_buffer, bytes_received);
        response_size += bytes_received;

        // Resize body buffer if necessary
        if (content_length_found && response_size >= response.content_length) {
            response.body = realloc(response.body, response.content_length+1);
            response.body[response.content_length] = '\0';
            break;
        }

        // Clear buffer
        memset(http_response_buffer, 0, MAX_BUFFER_SIZE);
    }

    close(sock);

    // Print HTTP response
    printf("%s\n\n", response.status_code);
    printf("%s\n", response.body);

    return 0;
}