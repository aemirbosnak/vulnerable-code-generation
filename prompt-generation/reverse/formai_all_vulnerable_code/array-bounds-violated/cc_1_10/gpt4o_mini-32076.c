//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

// Define errors
#define ERROR -1
#define SUCCESS 0

// HTTP methods
typedef enum {
    GET,
    POST,
    PUT,
    DELETE
} HttpMethod;

// Function prototypes
int http_request(const char *host, const char *path, HttpMethod method, const char *data);
void print_response(const char *response);
char *build_http_request(const char *host, const char *path, HttpMethod method, const char *data);

// Main function
int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <url> <path> [data]\n", argv[0]);
        return ERROR;
    }

    char *url = argv[1];
    char *path = argv[2];
    char *data = (argc > 3) ? argv[3] : NULL;

    // Extracting host from URL
    char *host = strtok(url, "/"); // Get the host
    int result = http_request(host, path, GET, data);

    return result;
}

// Function to make an HTTP request
int http_request(const char *host, const char *path, HttpMethod method, const char *data) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char *request;
    char response[4096];

    // Get server by hostname
    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        return ERROR;
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return ERROR;
    }

    // Set up the server address structure
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(80);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR connecting");
        close(sockfd);
        return ERROR;
    }

    // Build HTTP request
    request = build_http_request(host, path, method, data);
    if (request == NULL) {
        close(sockfd);
        return ERROR;
    }

    // Send request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("ERROR sending request");
        free(request);
        close(sockfd);
        return ERROR;
    }

    // Receive response
    int n = recv(sockfd, response, sizeof(response) - 1, 0);
    if (n < 0) {
        perror("ERROR receiving response");
        free(request);
        close(sockfd);
        return ERROR;
    }

    response[n] = '\0'; // Null-terminate the response
    print_response(response);

    // Cleanup
    free(request);
    close(sockfd);

    return SUCCESS;
}

// Build HTTP request string
char *build_http_request(const char *host, const char *path, HttpMethod method, const char *data) {
    char *request = malloc(1024);
    if (request == NULL) {
        perror("ERROR allocating memory for request");
        return NULL;
    }

    const char *method_str;
    switch (method) {
        case GET:
            method_str = "GET";
            break;
        case POST:
            method_str = "POST";
            break;
        case PUT:
            method_str = "PUT";
            break;
        case DELETE:
            method_str = "DELETE";
            break;
        default:
            free(request);
            return NULL;
    }

    if (data) {
        sprintf(request, "%s %s HTTP/1.1\r\nHost: %s\r\nContent-Length: %lu\r\n\r\n%s",
                method_str, path, host, strlen(data), data);
    } else {
        sprintf(request, "%s %s HTTP/1.1\r\nHost: %s\r\n\r\n", method_str, path, host);
    }

    return request;
}

// Print HTTP response
void print_response(const char *response) {
    printf("HTTP Response:\n%s\n", response);
}