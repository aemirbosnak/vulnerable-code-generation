//FormAI DATASET v1.0 Category: Networking ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 1024
#define PORT_NUMBER 8080

int main()
{
    int server_fd, new_socket, error;
    struct sockaddr_in address;
    int opt = 1;
    socklen_t client_addr_len;
    char address_buffer[MAX_BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
    {
        perror("Error while creating socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("Error while setting socket options");
        exit(EXIT_FAILURE);
    }

    // Assign IP, PORT
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT_NUMBER);

    // Bind socket to IP and PORT
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("Error while binding socket to IP and PORT");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0)
    {
        perror("Error while listening for incoming connections");
        exit(EXIT_FAILURE);
    }

    // Set the socket to non-blocking mode
    int flags = fcntl(server_fd, F_GETFL, 0);
    fcntl(server_fd, F_SETFL, flags | O_NONBLOCK);

    fd_set read_fds, write_fds;
    int max_fd;

    while (1)
    {
        FD_ZERO(&read_fds);
        FD_ZERO(&write_fds);
        FD_SET(server_fd, &read_fds);
        max_fd = server_fd;

        error = select(max_fd + 1, &read_fds, &write_fds, NULL, NULL);
        if (error == -1)
        {
            perror("Error while selecting");
            exit(EXIT_FAILURE);
        }

        // Get client socket file descriptor
        new_socket = accept(server_fd, (struct sockaddr *)&address, &client_addr_len);
        if (new_socket < 0)
        {
            if (errno == EWOULDBLOCK || errno == EAGAIN)
            {
                continue;
            }
            else
            {
                perror("Error while accepting new connection");
                exit(EXIT_FAILURE);
            }
        }

        // Set the socket to non-blocking mode
        int flags = fcntl(new_socket, F_GETFL, 0);
        fcntl(new_socket, F_SETFL, flags | O_NONBLOCK);

        printf("New client connected. IP: %s PORT: %d\n",
               inet_ntop(AF_INET, &address.sin_addr, address_buffer, sizeof(address_buffer)),
               ntohs(address.sin_port));

        char buffer[MAX_BUFFER_SIZE] = {0};

        error = recv(new_socket, buffer, MAX_BUFFER_SIZE, 0);
        if (error == -1)
        {
            if (errno == EWOULDBLOCK || errno == EAGAIN)
            {
                continue;
            }
            else
            {
                perror("Error while receiving data from client");
                exit(EXIT_FAILURE);
            }
        }
        else if (error == 0)
        {
            printf("Connection closed by client. IP: %s PORT: %d\n",
                   inet_ntop(AF_INET, &address.sin_addr, address_buffer, sizeof(address_buffer)),
                   ntohs(address.sin_port));
            close(new_socket);
            continue;
        }

        printf("Received message from client: %s\n", buffer);

        error = send(new_socket, "Got your message!", strlen("Got your message!"), 0);
        if (error == -1)
        {
            if (errno == EWOULDBLOCK || errno == EAGAIN)
            {
                continue;
            }
            else
            {
                perror("Error while sending data to client");
                exit(EXIT_FAILURE);
            }
        }

        printf("Sent reply to client\n");

        close(new_socket);
    }

    close(server_fd);
    return 0;
}