//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int server_socket, client_socket, port;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_size = sizeof(client_address);
    char buffer[BUFFER_SIZE];

    if(argc != 2)
    {
        printf("Usage: %s <port>\n", argv[0]);
        exit(0);
    }

    port = atoi(argv[1]);

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == -1)
    {
        printf("Failed to create socket.\n");
        exit(0);
    }

    // Set server address structure
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    // Bind socket to address
    if(bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1)
    {
        printf("Failed to bind socket.\n");
        exit(0);
    }

    // Listen for incoming connections
    if(listen(server_socket, MAX_CLIENTS) == -1)
    {
        printf("Failed to listen for connections.\n");
        exit(0);
    }

    while(1)
    {
        // Accept incoming connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_size);
        if(client_socket == -1)
        {
            printf("Failed to accept incoming connection.\n");
            continue;
        }

        // Create child process to handle client request
        if(fork() == 0)
        {
            close(server_socket);

            // Read client request
            memset(buffer, 0, BUFFER_SIZE);
            if(read(client_socket, buffer, BUFFER_SIZE) == -1)
            {
                printf("Failed to read client request.\n");
                exit(0);
            }

            // Extract host and port from request
            char *host_start = strstr(buffer, "Host: ") + 6;
            char *host_end = strstr(host_start, "\r\n");
            char *port_start = strstr(host_start, ":") + 1;
            char *port_end = strstr(port_start, "\r\n");
            char host[100], port[10];
            strncpy(host, host_start, host_end - host_start);
            strncpy(port, port_start, port_end - port_start);

            // Create socket to remote server
            int remote_socket = socket(AF_INET, SOCK_STREAM, 0);
            if(remote_socket == -1)
            {
                printf("Failed to create socket to remote server.\n");
                exit(0);
            }

            // Set remote server address structure
            struct sockaddr_in remote_address;
            remote_address.sin_family = AF_INET;
            remote_address.sin_addr.s_addr = inet_addr(host);
            remote_address.sin_port = htons(atoi(port));

            // Connect to remote server
            if(connect(remote_socket, (struct sockaddr *)&remote_address, sizeof(remote_address)) == -1)
            {
                printf("Failed to connect to remote server.\n");
                exit(0);
            }

            // Forward client request to remote server
            if(write(remote_socket, buffer, strlen(buffer)) == -1)
            {
                printf("Failed to forward client request to remote server.\n");
                exit(0);
            }

            // Forward remote server response to client
            memset(buffer, 0, BUFFER_SIZE);
            int bytes_received;
            while((bytes_received = read(remote_socket, buffer, BUFFER_SIZE)) > 0)
            {
                if(write(client_socket, buffer, bytes_received) == -1)
                {
                    printf("Failed to forward remote server response to client.\n");
                    exit(0);
                }
                memset(buffer, 0, BUFFER_SIZE);
            }

            // Close sockets
            close(client_socket);
            close(remote_socket);

            // Exit child process
            exit(0);
        }

        close(client_socket);
    }

    // Close server socket
    close(server_socket);

    return 0;
}