//FormAI DATASET v1.0 Category: Client Server Application ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <time.h>

// function to generate a random port number
int get_random_port() {
    return (rand() % 65535) + 10000; // port range from 10000 to 75535
}

int main() {
    // get the hostname
    struct hostent* host;
    char host_name[50];
    gethostname(host_name, sizeof host_name);
    host = gethostbyname(host_name);

    // generate a random port number for the server
    srand(time(NULL));
    int port = get_random_port();

    // create the server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("ERROR: failed to create server socket");
        return EXIT_FAILURE;
    }

    // bind the socket to a port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(server_socket, (struct sockaddr*) &server_address, sizeof server_address) == -1) {
        perror("ERROR: failed to bind server socket");
        return EXIT_FAILURE;
    }

    // listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("ERROR: failed to listen for connections");
        return EXIT_FAILURE;
    }

    printf("Server listening on port %d...\n", port);

    // loop continuously to handle incoming connections
    while (1) {
        // accept the incoming connection
        struct sockaddr_in client_address;
        socklen_t client_address_length = sizeof client_address;
        int client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_address_length);
        if (client_socket == -1) {
            perror("ERROR: failed to accept connection");
            return EXIT_FAILURE;
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // receive data from the client
        char buffer[256];
        int bytes_received = recv(client_socket, buffer, sizeof buffer, 0);
        if (bytes_received == -1) {
            perror("ERROR: failed to receive data from client");
            return EXIT_FAILURE;
        }

        // display the received data and send a response back to the client
        buffer[bytes_received] = '\0';
        printf("Received data: %s\n", buffer);
        char response[] = "Server received your message";
        if (send(client_socket, response, sizeof response, 0) == -1) {
            perror("ERROR: failed to send data to client");
            return EXIT_FAILURE;
        }

        // close the client socket
        close(client_socket);

        printf("Client disconnected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
    }

    // close the server socket
    close(server_socket);

    return EXIT_SUCCESS;
}