//Falcon2-11B DATASET v1.0 Category: Networking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buffer[256];

    // Initialize server address structure
    memset((char *)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5000);

    if (argc!= 2)
    {
        printf("Usage: %s <server_ip>\n", argv[0]);
        exit(1);
    }

    // Resolve server address
    server = gethostbyname(argv[1]);
    if (server == NULL)
    {
        fprintf(stderr, "Error: Invalid server address\n");
        exit(1);
    }

    server_addr.sin_addr.s_addr = *(unsigned long *)server->h_addr;

    // Create socket and connect to server
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    if (connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    // Create new socket for accepting connections
    new_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (new_socket < 0)
    {
        perror("Error creating new socket");
        exit(1);
    }

    int opt = 1;
    setsockopt(new_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int));

    // Bind new socket to local address
    memset((char *)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5000);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(new_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error binding new socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(new_socket, 5) < 0)
    {
        perror("Error listening for connections");
        exit(1);
    }

    // Accept new connections
    while (1)
    {
        new_socket = accept(new_socket, NULL, NULL);
        if (new_socket < 0)
        {
            perror("Error accepting connection");
            exit(1);
        }

        printf("New client connected\n");

        // Receive message from client
        while ((valread = recv(new_socket, buffer, sizeof(buffer), 0)) > 0)
        {
            printf("Received message: %s\n", buffer);

            // Send message back to client
            send(new_socket, buffer, valread, 0);
        }

        // Close client connection
        close(new_socket);
    }

    close(server_fd);
    close(new_socket);
    return 0;
}