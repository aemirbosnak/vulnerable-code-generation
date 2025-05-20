//FormAI DATASET v1.0 Category: Networking ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
    printf("Welcome to the Happy Networking Program!\n");
    printf("We're going to create a server and a client that send happy messages to each other!\n");

    // create server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        printf("Oops! Something went wrong while creating the server socket :(\n");
        exit(EXIT_FAILURE);
    }
    printf("Server socket successfully created!\n");

    // set server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9000);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // bind socket to address
    if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        printf("Oops! Something went wrong while binding the server socket to the address :(\n");
        exit(EXIT_FAILURE);
    }
    printf("Server socket successfully bound to address!\n");

    // listen for client connections
    if (listen(server_socket, 5) < 0) {
        printf("Oops! Something went wrong while starting to listen for client connections :(\n");
        exit(EXIT_FAILURE);
    }
    printf("Server is now listening for client connections!\n");

    // accept incoming client connection
    struct sockaddr_in client_address;
    socklen_t client_address_size = sizeof(client_address);
    int client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_address_size);
    if (client_socket < 0) {
        printf("Oops! Something went wrong while accepting the client connection :(\n");
        exit(EXIT_FAILURE);
    }
    printf("Client successfully connected to the server!\n");

    // send happy message to client
    char* happy_message = "Hello client! I am sending you happy vibes!";
    send(client_socket, happy_message, strlen(happy_message), 0);
    printf("Happy message successfully sent to client!\n");

    // receive message from client
    char buffer[1024];
    int message_size = read(client_socket, buffer, 1024);
    buffer[message_size] = '\0';
    printf("Client has sent a message: %s\n", buffer);

    // close sockets
    close(client_socket);
    close(server_socket);

    printf("Thanks for using the Happy Networking Program! Have a great day :)\n");

    return 0;
}