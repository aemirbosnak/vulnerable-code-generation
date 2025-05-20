//FormAI DATASET v1.0 Category: Socket programming ; Style: cheerful
#include <stdio.h>     
#include <stdlib.h>    
#include <string.h>    
#include <unistd.h>    
#include <arpa/inet.h> 
#include <sys/socket.h>
#include <netinet/in.h> 

#define PORT 9000
#define MAX_CONNECTIONS 5

int main() {
    printf("Welcome to our cheerful Socket Programming example!\n\n");

    struct sockaddr_in server_address, client_address;
    int server_socket, new_socket, valread;
    char message[1024];

    // Create a socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Could not create socket. Exiting...\n");
        return EXIT_FAILURE;
    }

    // Set server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the specified IP and port
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Could not bind socket to IP and port. Exiting...\n");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CONNECTIONS) < 0) {
        printf("Could not listen for incoming connections. Exiting...\n");
        return EXIT_FAILURE;
    }

    printf("Server is listening on port %d...\n\n", PORT);

    socklen_t client_address_len = sizeof(client_address);

    // Accept incoming connections
    if ((new_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_len)) < 0) {
        printf("Could not accept incoming connection. Exiting...\n");
        return EXIT_FAILURE;
    }

    printf("Incoming connection accepted!\n\n");

    // Send a cheerful greeting to the client
    char *greeting = "Hello, client! Welcome to our cheerful Socket Programming example!\n";
    send(new_socket, greeting, strlen(greeting), 0);

    // Receive a message from the client and display it
    valread = read(new_socket, message, 1024);
    message[valread] = '\0';
    printf("Client: %s\n", message);

    // Send a cheerful response to the client
    char *response = "Great to hear from you, client! Have a cheerful day!\n";
    send(new_socket, response, strlen(response), 0);

    // Close the sockets and exit the program
    close(new_socket);
    close(server_socket);
    printf("Program complete. Exiting...\n");
    return EXIT_SUCCESS;
}