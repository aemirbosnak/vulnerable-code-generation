//FormAI DATASET v1.0 Category: Socket programming ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Server's IP address and port number
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080

int main()
{
    int client_socket;
    struct sockaddr_in server_address;

    // Create a socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0)
    {
        fprintf(stderr, "Error while creating socket!\n");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_IP, &server_address.sin_addr) <= 0)
    {
        fprintf(stderr, "Invalid address or address not supported!\n");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        fprintf(stderr, "Error while connecting to the server!\n");
        exit(EXIT_FAILURE);
    }

    // Send a message to the server
    char message[] = "Hello, Server!";
    int message_size = strlen(message);
    if (send(client_socket, message, message_size, 0) != message_size)
    {
        fprintf(stderr, "Error while sending message to the server!\n");
        exit(EXIT_FAILURE);
    }

    // Receive a message from the server
    char response[1024];
    int recv_size = recv(client_socket, response, sizeof(response), 0);
    if (recv_size < 0)
    {
        fprintf(stderr, "Error while receiving message from the server!\n");
        exit(EXIT_FAILURE);
    }
    else if (recv_size == 0)
    {
        fprintf(stderr, "Connection closed by the server!\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        response[recv_size] = '\0';
        printf("Server response: %s\n", response);
    }

    // Close the socket and exit
    close(client_socket);
    return 0;
}