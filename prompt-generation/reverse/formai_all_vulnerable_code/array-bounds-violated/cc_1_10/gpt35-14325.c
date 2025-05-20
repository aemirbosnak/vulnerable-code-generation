//FormAI DATASET v1.0 Category: Networking ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {

    struct sockaddr_in server_address;
    int socket_fd = 0, connection_fd = 0;
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error!\n");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    memset(&server_address, '0', sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported!\n");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if(connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed!\n");
        exit(EXIT_FAILURE);
    }

    // Declaration of variables
    int input_length;
    char input_buffer[BUFFER_SIZE];

    // Loop to ask user for input
    while(1) {

        printf("Enter your message: ");
        fgets(input_buffer, BUFFER_SIZE, stdin);

        // Get rid of newline in input
        input_length = strlen(input_buffer);
        if(input_buffer[input_length-1] == '\n')
            input_buffer[input_length-1] = '\0';

        // Send message to server
        send(socket_fd, input_buffer, strlen(input_buffer), 0);

        // End program if 'exit' is entered
        if(strcmp(input_buffer, "exit") == 0)
            break;

        // Receive message from server
        if(recv(socket_fd, buffer, BUFFER_SIZE, 0) <= 0) {
            printf("Server disconnected!\n");
            exit(EXIT_FAILURE);
        }

        // Print received message
        printf("Server: %s\n", buffer);

        // Clear buffer
        memset(buffer, 0, BUFFER_SIZE);
    }

    // Close socket and end program
    close(socket_fd);
    return 0;
}