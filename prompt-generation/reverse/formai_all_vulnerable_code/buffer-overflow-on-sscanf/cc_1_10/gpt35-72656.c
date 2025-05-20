//FormAI DATASET v1.0 Category: Simple Web Server ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    // Create socket for incoming requests
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
         printf("Error opening socket");
         return -1;
    }

    // Set socket options to reuse address and port
    int yes = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &yes, sizeof(yes));

    // Bind socket to address/port
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error binding socket");
        return -1;
    }

    // Listen for incoming connections
    if (listen(server_socket, SOMAXCONN) < 0) {
        printf("Error listening");
        return -1;
    }

    printf("Listening on port 8080...\n");

    // Accept new connections and handle requests
    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
        if (client_socket < 0) {
            printf("Error accepting connection");
            break;
        }

        // Read incoming request
        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);
        ssize_t bytes_received = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
        if (bytes_received < 0) {
            printf("Error receiving data");
            close(client_socket);
            continue;
        }

        // Parse incoming request
        char method[10], path[1024], protocol[10];
        sscanf(buffer, "%s %s %s", method, path, protocol);

        // Print incoming request
        printf("%s %s %s\n", method, path, protocol);

        // Send response
        const char *response_header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
        const char *response_body = "<!DOCTYPE html>\n<html>\n<body>\n<h1>Hello, world!</h1>\n<p>This is my web server.</p>\n</body>\n</html>\n";
        send(client_socket, response_header, strlen(response_header), 0);
        send(client_socket, response_body, strlen(response_body), 0);

        // Close connection
        close(client_socket);
    }

    // Clean up resources
    close(server_socket);

    return 0;
}