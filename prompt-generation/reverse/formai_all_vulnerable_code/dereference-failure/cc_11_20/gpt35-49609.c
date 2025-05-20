//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char const *argv[])
{
    if (argc != 4)
    {
        fprintf(stderr, "Usage: %s <proxy_port> <target_ip> <target_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int proxy_port = atoi(argv[1]);
    char *target_ip = (char *)argv[2];
    int target_port = atoi(argv[3]);

    int server_socket, client_socket, target_socket;
    struct sockaddr_in server_address, client_address, target_address;
    socklen_t client_address_len = sizeof(client_address);

    // Create the proxy server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Bind the proxy server socket to the given port
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(proxy_port);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, SOMAXCONN) == -1)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Proxy server listening on port %d...\n", proxy_port);

    while (1)
    {
        // Accept a new client connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);

        if (client_socket == -1)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Accepted connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Create a new socket to connect to the target server
        target_socket = socket(AF_INET, SOCK_STREAM, 0);

        if (target_socket == -1)
        {
            perror("socket");
            exit(EXIT_FAILURE);
        }

        // Connect to the target server
        memset(&target_address, 0, sizeof(target_address));
        target_address.sin_family = AF_INET;
        target_address.sin_addr.s_addr = inet_addr(target_ip);
        target_address.sin_port = htons(target_port);

        if (connect(target_socket, (struct sockaddr *)&target_address, sizeof(target_address)) == -1)
        {
            perror("connect");
            exit(EXIT_FAILURE);
        }

        printf("Connected to target server at %s:%d\n", target_ip, target_port);

        // Forward data between the client and target server
        fd_set read_fds;

        while (1)
        {
            FD_ZERO(&read_fds);
            FD_SET(client_socket, &read_fds);
            FD_SET(target_socket, &read_fds);

            if (select(FD_SETSIZE, &read_fds, NULL, NULL, NULL) == -1)
            {
                perror("select");
                exit(EXIT_FAILURE);
            }

            char buffer[BUFFER_SIZE];
            int num_bytes;

            if (FD_ISSET(client_socket, &read_fds))
            {
                num_bytes = recv(client_socket, buffer, BUFFER_SIZE, 0);

                if (num_bytes == -1)
                {
                    perror("recv");
                    exit(EXIT_FAILURE);
                }
                else if (num_bytes == 0)
                {
                    break;
                }

                printf("Received %d bytes from client\n", num_bytes);

                if (send(target_socket, buffer, num_bytes, 0) == -1)
                {
                    perror("send");
                    exit(EXIT_FAILURE);
                }

                printf("Sent %d bytes to target server\n", num_bytes);
            }

            if (FD_ISSET(target_socket, &read_fds))
            {
                num_bytes = recv(target_socket, buffer, BUFFER_SIZE, 0);

                if (num_bytes == -1)
                {
                    perror("recv");
                    exit(EXIT_FAILURE);
                }
                else if (num_bytes == 0)
                {
                    break;
                }

                printf("Received %d bytes from target server\n", num_bytes);

                if (send(client_socket, buffer, num_bytes, 0) == -1)
                {
                    perror("send");
                    exit(EXIT_FAILURE);
                }

                printf("Sent %d bytes to client\n", num_bytes);
            }
        }

        printf("Closing connection to client\n");
        close(client_socket);

        printf("Closing connection to target server\n");
        close(target_socket);
    }

    // Close the proxy server socket
    close(server_socket);

    return 0;
}