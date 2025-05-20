//FormAI DATASET v1.0 Category: Simple Web Server ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define DEFAULT_PORT 8888
#define MAX_CONNECTIONS 10

int main(int argc, char *argv[]) {

    int server_socket, new_socket, address_len, read_size;
    struct sockaddr_in server_address, client_address;
    char client_message[2000];

    // Configurable options
    int port = DEFAULT_PORT;
    char root_directory[200] = "/var/www/html";

    // Parse command line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-p") == 0) {
            if (i + 1 < argc) {
                port = atoi(argv[i + 1]);
            } else {
                printf("Error: invalid command line arguments\n");
                return 1;
            }
        } else if (strcmp(argv[i], "-r") == 0) {
            if (i + 1 < argc) {
                strncpy(root_directory, argv[i + 1], 200);
            } else {
                printf("Error: invalid command line arguments\n");
                return 1;
            }
        }
    }

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error: could not create socket\n");
        return 1;
    }

    // Prepare server address struct
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    // Bind the socket to address and port
    if (bind(server_socket,(struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error: could not bind socket\n");
        return 1;
    }

    // Listen for incoming connections
    listen(server_socket, MAX_CONNECTIONS);

    printf("Server started on port %d, serving directory: %s\n", port, root_directory);

    // Main server loop
    while (1) {

        address_len = sizeof(struct sockaddr_in);

        // Accept incoming connection
        new_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t*)&address_len);           
        if (new_socket < 0) {
            printf("Error: could not accept incoming connection\n");
            return 1;               
        }

        // Read client request
        read_size = recv(new_socket, client_message, 2000, 0);
        client_message[read_size] = '\0';

        // Handle client request
        printf("Client request received: %s\n", client_message);
        char file_path[250];
        sprintf(file_path, "%s%s", root_directory, client_message);
        FILE *requested_file = fopen(file_path, "r");
        char response[2000];
        if (requested_file == NULL) {
            // File not found error
            sprintf(response, "HTTP/1.1 404 Not Found\r\n\r\n");
            write(new_socket, response, strlen(response)); 
        } else {
            // File found, send contents
            sprintf(response, "HTTP/1.1 200 OK\r\n\r\n");
            write(new_socket, response, strlen(response)); 
            while (fgets(response, 1999, requested_file) != NULL) {
                write(new_socket, response, strlen(response));
            }
            fclose(requested_file);
        }

        // Close connection and return to listening
        close(new_socket);
    }

    return 0;
}