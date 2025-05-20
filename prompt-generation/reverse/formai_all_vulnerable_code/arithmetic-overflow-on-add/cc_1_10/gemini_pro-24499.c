//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

// Cyberpunk Socket Variables
#define MATRIX_PORT 7777
#define CONSTRUCT_ADDR "127.0.0.1"

int main(int argc, char *argv[])
{
    // Create a Matrix Socket
    int matrix_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (matrix_socket == -1)
    {
        perror("Failed to establish Matrix Connection");
        exit(EXIT_FAILURE);
    }

    // Construct Server Address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(MATRIX_PORT);
    inet_pton(AF_INET, CONSTRUCT_ADDR, &server_address.sin_addr);

    // Connect to the Matrix Construct
    if (connect(matrix_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1)
    {
        perror("Connection to Matrix Construct Failed");
        exit(EXIT_FAILURE);
    }

    // Hackerspace Greeting
    printf("Greetings, Hacker. You have hacked into the Matrix.\n");

    // Command Interface Loop
    char command[1024];
    while (1)
    {
        printf("Command: ");
        scanf("%s", command);

        // Send Command to Matrix Construct
        int command_length = strlen(command);
        send(matrix_socket, &command_length, sizeof(int), 0);
        send(matrix_socket, command, command_length, 0);

        // Receive Response from Construct
        int response_length;
        recv(matrix_socket, &response_length, sizeof(int), 0);
        char response[response_length + 1];
        recv(matrix_socket, response, response_length, 0);
        response[response_length] = '\0';

        // Display Response
        printf("Response: %s\n", response);
    }

    // Close Matrix Connection
    close(matrix_socket);
    return 0;
}