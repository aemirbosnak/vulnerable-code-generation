//FormAI DATASET v1.0 Category: Firewall ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

#define PORT 8080
#define MAX_CONNECTIONS 5

int main()
{
    int master_socket, new_socket;
    struct sockaddr_in server_address, client_address;
    int client_address_len = sizeof(client_address);
    char buffer[1024] = {0};

    // Create master socket
    if ((master_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Master socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set to non-blocking mode
    if (fcntl(master_socket, F_SETFL, O_NONBLOCK) < 0) {
        perror("Failed to set socket to non-blocking mode");
        exit(EXIT_FAILURE);
    }

    // Allow reuse of address and port
    int option_value = 1;
    if (setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &option_value, sizeof(option_value)) < 0)
    {
        perror("Unable to set socket options");
        exit(EXIT_FAILURE);
    }

    // Bind socket to port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(master_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(master_socket, MAX_CONNECTIONS) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Event loop
    while (1)
    {
        // Accept incoming connections
        if ((new_socket = accept(master_socket, (struct sockaddr *)&client_address, (socklen_t *)&client_address_len)) < 0)
        {
            if (errno == EWOULDBLOCK || errno == EAGAIN)
            {
                // No new connections, continue waiting
                continue;
            }
            else
            {
                // Accept error
                perror("Accept failed");
                exit(EXIT_FAILURE);
            }
        }

        // Set new socket to non-blocking mode
        if (fcntl(new_socket, F_SETFL, O_NONBLOCK) < 0)
        {
            perror("Failed to set new socket to non-blocking mode");
            exit(EXIT_FAILURE);
        }

        // Check IP address against blacklist
        char *blacklist[] = {"192.168.0.1", "192.168.0.2", "192.168.0.3"};
        for (int i = 0; i < sizeof(blacklist) / sizeof(blacklist[0]); i++)
        {
            if (strcmp(inet_ntoa(client_address.sin_addr), blacklist[i]) == 0)
            {
                printf("Connection from blacklisted IP address %s blocked\n", inet_ntoa(client_address.sin_addr));
                close(new_socket);
                continue;
            }
        }

        // Read data from client
        int num_bytes = read(new_socket, buffer, 1024);

        if (num_bytes == 0)
        {
            // Connection closed by client
            close(new_socket);
            continue;
        }
        else if (num_bytes < 0)
        {
            if (errno != EWOULDBLOCK && errno != EAGAIN)
            {
                // Error reading from socket
                perror("Read error");
                close(new_socket);
                continue;
            }
            else
            {
                // No data available, continue waiting
                continue;
            }
        }

        printf("Received message from client: %s\n", buffer);

        // Echo message back to client
        if (send(new_socket, buffer, strlen(buffer), 0) < 0)
        {
            perror("Send failed");
            close(new_socket);
            continue;
        }
    }
    return 0;
}