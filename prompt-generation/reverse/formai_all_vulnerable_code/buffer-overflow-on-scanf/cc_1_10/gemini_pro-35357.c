//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    // Initialize variables
    char hostname[1024];
    int port = 80;
    int socket_fd;
    struct sockaddr_in server_addr;

    // Get the hostname from the user
    printf("Enter the hostname or IP address of the website: ");
    scanf("%s", hostname);

    // Resolve the hostname to an IP address
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Error resolving hostname: %s\n", hostname);
        return 1;
    }

    // Create a socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    // Set the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *(struct in_addr *)host->h_addr;

    // Connect to the server
    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    // Send a request to the server
    const char *request = "HEAD / HTTP/1.1\r\nHost: ";
    const char *end_of_request = "\r\n\r\n";
    char request_buffer[1024];
    strcpy(request_buffer, request);
    strcat(request_buffer, hostname);
    strcat(request_buffer, end_of_request);
    if (send(socket_fd, request_buffer, strlen(request_buffer), 0) == -1) {
        printf("Error sending request to server\n");
        return 1;
    }

    // Receive the response from the server
    char response_buffer[1024];
    int response_length = recv(socket_fd, response_buffer, 1024, 0);
    if (response_length == -1) {
        printf("Error receiving response from server\n");
        return 1;
    }

    // Check the status code
    char status_code_buffer[4];
    strncpy(status_code_buffer, response_buffer, 3);
    status_code_buffer[3] = '\0';
    int status_code = atoi(status_code_buffer);

    // Print the status code
    printf("Status code: %d\n", status_code);

    // Close the socket
    close(socket_fd);

    // Return 0 if the website is up, 1 otherwise
    return status_code == 200 ? 0 : 1;
}