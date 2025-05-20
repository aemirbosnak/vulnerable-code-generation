//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

// Define the max size of the HTTP response message
#define MAX_RESPONSE_SIZE 4096

// Define the HTTP request message format
#define HTTP_REQUEST_FORMAT "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n"

// Define the HTTP response message format
#define HTTP_RESPONSE_FORMAT "HTTP/1.1 %d %s\r\n"

// Define the HTTP response status codes
#define HTTP_RESPONSE_STATUS_OK 200
#define HTTP_RESPONSE_STATUS_NOT_FOUND 404

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[MAX_RESPONSE_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Check for the required number of arguments
    if (argc < 3) {
        printf("Usage: %s [server_address] [file_path]\n", argv[0]);
        exit(1);
    }

    // Get the server's hostname from the command line arguments
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error: No such host found.\n");
        exit(1);
    }

    // Create a socket for the HTTP connection
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Failed to open a socket.\n");
        exit(1);
    }

    // Set the server's address and port number
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Failed to connect to the server.\n");
        exit(1);
    }

    // Build the HTTP request message
    char request_message[MAX_RESPONSE_SIZE];
    sprintf(request_message, HTTP_REQUEST_FORMAT, argv[2], argv[1]);

    // Send the HTTP request message
    if (write(sockfd, request_message, strlen(request_message)) < 0) {
        printf("Error: Failed to send the HTTP request to the server.\n");
        exit(1);
    }

    // Receive the HTTP response message
    char* response_status_message = NULL;
    int response_status_code = 0;
    while ((n = read(sockfd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[n] = '\0';

        // Parse the HTTP response status code and message
        if (response_status_code == 0 && response_status_message == NULL) {
            char* p = strtok(buffer, " \r\n");
            if (p != NULL && strcmp(p, "HTTP/1.1") == 0) {
                response_status_code = atoi(strtok(NULL, " \r\n"));
                response_status_message = strtok(NULL, " \r\n");
            }
        }

        printf("%s", buffer);
    }

    // Print the HTTP response status code and message
    printf("\nHTTP Response Status: ");
    if (response_status_code == HTTP_RESPONSE_STATUS_OK) {
        printf("OK (%s)\n", response_status_message);
    } else if (response_status_code == HTTP_RESPONSE_STATUS_NOT_FOUND) {
        printf("Not Found (%s)\n", response_status_message);
    } else {
        printf("Unknown Status Code (%d %s)\n", response_status_code, response_status_message);
    }

    // Close the socket
    close(sockfd);

    return 0;
}