//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void error_handler(char *error_msg)
{
    perror(error_msg);
    exit(EXIT_FAILURE);
}

int main()
{
    int socket_fd;
    struct sockaddr_in server_addr;
    char buffer[1024];
    int read_size;

    // create socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1)
    {
        error_handler("Failed to create socket");
    }

    // set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(12345);

    // connect to the server
    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        error_handler("Failed to connect to server");
    }

    // send message to server
    char *message = "Hello, server!";
    if (send(socket_fd, message, strlen(message), 0) == -1)
    {
        error_handler("Failed to send message");
    }

    // receive message from server
    while ((read_size = recv(socket_fd, buffer, sizeof(buffer), 0)) > 0)
    {
        buffer[read_size] = '\0';
        printf("Message from server: %s\n", buffer);
    }

    if (read_size == -1)
    {
        error_handler("Failed to receive message");
    }

    // close socket
    close(socket_fd);

    return 0;
}