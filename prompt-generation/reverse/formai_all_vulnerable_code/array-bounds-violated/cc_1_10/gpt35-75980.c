//FormAI DATASET v1.0 Category: Networking ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 6666

void handle_client(int client_socket);

int main() {
    int server_socket, client_socket, address_size;
    struct sockaddr_in server_address, client_address;

    // Creating the socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error: could not create socket");
        return 1;
    }

    // Setting the server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(PORT);

    // Binding the socket to the address
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        printf("Error: could not bind");
        return 1;
    }

    // Listening for incoming connections
    if (listen(server_socket, 5) == -1) {
        printf("Error: could not listen");
        return 1;
    }

    printf("Waiting for incoming connections...\n");

    // Accepting incoming connections
    while (1) {
        address_size = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *) &client_address, &address_size);
        if (client_socket == -1) {
            printf("Error: could not accept incoming connection");
            return 1;
        }

        printf("New connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        pid_t pid = fork();

        if (pid == 0) {
            close(server_socket);
            handle_client(client_socket);
            exit(0);
        } else if (pid > 0) {
            close(client_socket);
        } else {
            printf("Error: could not fork");
            return 1;
        }
    }

    return 0;
}

void handle_client(int client_socket) {
    char buffer[1024];
    int bytes_received;

    while (1) {
        // Receiving data from the client
        bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes_received == -1) {
            printf("Error: could not receive data from client");
            break;
        }

        if (bytes_received == 0) {
            printf("Connection closed by client\n");
            break;
        }

        buffer[bytes_received] = '\0';
        printf("Received: %s", buffer);

        // Sending data back to the client
        if (send(client_socket, buffer, bytes_received, 0) == -1) {
            printf("Error: could not send data to client");
            break;
        }
    }

    close(client_socket);
}