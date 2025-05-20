//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT_NUM 8080

int main()
{
    int input_socket_fd, proxy_socket_fd, client_socket_fd, max_socket_fd;
    struct sockaddr_in server_address, client_address, proxy_address;
    char buffer[BUFFER_SIZE];
    fd_set file_descriptor_set;

    // Create input socket
    input_socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (input_socket_fd == -1)
    {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set server socket address parameters
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(PORT_NUM);

    // Bind input socket to server address and port
    if (bind(input_socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1)
    {
        perror("Error binding input socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(input_socket_fd, 10) == -1)
    {
        perror("Error listening on input socket");
        exit(EXIT_FAILURE);
    }

    printf("Proxy running on port %d...\n", PORT_NUM);

    while (1)
    {
        // Clear file descriptor set and add input socket file descriptor
        FD_ZERO(&file_descriptor_set);
        FD_SET(input_socket_fd, &file_descriptor_set);
        max_socket_fd = input_socket_fd;

        // Add client and proxy socket file descriptors
        for (int i = 0; i < 2; i++)
        {
            int socket_fd = i == 0 ? client_socket_fd : proxy_socket_fd;

            if (socket_fd != 0)
            {
                FD_SET(socket_fd, &file_descriptor_set);

                if (socket_fd > max_socket_fd)
                {
                    max_socket_fd = socket_fd;
                }
            }
        }

        // Wait for activity on file descriptors
        if (select(max_socket_fd + 1, &file_descriptor_set, NULL, NULL, NULL) == -1)
        {
            perror("Error selecting file descriptors");
            exit(EXIT_FAILURE);
        }

        // Check for incoming connections on input socket
        if (FD_ISSET(input_socket_fd, &file_descriptor_set))
        {
            // Accept incoming client connection
            socklen_t client_address_length = sizeof(client_address);
            client_socket_fd = accept(input_socket_fd, (struct sockaddr *)&client_address, &client_address_length);

            if (client_socket_fd == -1)
            {
                perror("Error accepting client connection");
                exit(EXIT_FAILURE);
            }

            // Connect to destination server
            proxy_socket_fd = socket(AF_INET, SOCK_STREAM, 0);

            if (proxy_socket_fd == -1)
            {
                perror("Error creating proxy socket");
                exit(EXIT_FAILURE);
            }

            char *destination_host = "www.example.com";
            struct hostent *destination = gethostbyname(destination_host);

            if (destination == NULL)
            {
                perror("Error getting destination host");
                exit(EXIT_FAILURE);
            }

            memset(&proxy_address, 0, sizeof(proxy_address));
            proxy_address.sin_family = AF_INET;
            proxy_address.sin_addr = *((struct in_addr *)destination->h_addr_list[0]);
            proxy_address.sin_port = htons(80);

            if (connect(proxy_socket_fd, (struct sockaddr *)&proxy_address, sizeof(proxy_address)) == -1)
            {
                perror("Error connecting to destination host");
                exit(EXIT_FAILURE);
            }

            printf("Connected to destination host %s\n", destination_host);
        }

        // Check for activity on client or proxy sockets
        for (int i = 0; i < 2; i++)
        {
            int socket_fd = i == 0 ? client_socket_fd : proxy_socket_fd;

            if (FD_ISSET(socket_fd, &file_descriptor_set))
            {
                int bytes_read = read(socket_fd, buffer, BUFFER_SIZE);
                if (bytes_read == -1)
                {
                    perror("Error reading from socket");
                    exit(EXIT_FAILURE);
                }
                else if (bytes_read == 0)
                {
                    close(socket_fd);
                    if (socket_fd == client_socket_fd)
                    {
                        close(proxy_socket_fd);
                        printf("Closed client and proxy connections\n");
                    }
                    else
                    {
                        close(client_socket_fd);
                        printf("Closed proxy and client connections\n");
                    }
                    break;
                }
                else
                {
                    int write_socket_fd = socket_fd == client_socket_fd ? proxy_socket_fd : client_socket_fd;
                    write(write_socket_fd, buffer, bytes_read);
                }
            }
        }
    }

    return 0;
}