//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <errno.h>

// define constants for maximum message length and buffer size
#define MAX_MSG_LENGTH 1024
#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    int server_socket, client_socket, bytes_sent, bytes_received, optval = 1;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_size = sizeof(client_address);

    // create a TCP socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // set socket options to allow reuse of address and port
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &optval, sizeof(optval)) == -1) {
        perror("Error setting socket options");
        exit(EXIT_FAILURE);
    }

    // set up server address and port
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(8080);

    // bind the socket to the specified address and port
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(server_socket, 1) == -1) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    printf("Server started and listening on port %d...\n", ntohs(server_address.sin_port));

    while (1) {
        // accept a new connection
        if ((client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_size)) == -1) {
            perror("Error accepting incoming connection");
            exit(EXIT_FAILURE);
        }

        // get the client's IP address and port
        char client_address_string[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(client_address.sin_addr), client_address_string, INET_ADDRSTRLEN);
        int client_port = ntohs(client_address.sin_port);
        printf("Incoming connection from %s:%d\n", client_address_string, client_port);

        // receive data from the client
        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);

        int total_bytes_received = 0;
        while ((bytes_received = recv(client_socket, buffer + total_bytes_received, BUFFER_SIZE - total_bytes_received, 0)) > 0) {
            total_bytes_received += bytes_received;

            if (buffer[total_bytes_received - 1] == '\n') {
                // end of message detected, process and respond
                buffer[total_bytes_received - 1] = '\0';
                printf("Message received from %s:%d: %s\n", client_address_string, client_port, buffer);

                // reverse the message and send it back to the client
                char reversed[MAX_MSG_LENGTH];
                int length = strlen(buffer);
                for (int i = 0; i < length; i++) {
                    reversed[i] = buffer[length - i - 1];
                }
                reversed[length] = '\n';

                bytes_sent = send(client_socket, reversed, strlen(reversed), 0);
                if (bytes_sent == -1) {
                    perror("Error sending message");
                    close(client_socket);
                    exit(EXIT_FAILURE);
                }

                memset(buffer, 0, BUFFER_SIZE);
                total_bytes_received = 0;
            }
        }
        if (bytes_received == -1) {
            perror("Error receiving message");
        }
        else if (bytes_received == 0) {
            printf("Client %s:%d disconnected\n", client_address_string, client_port);
        }

        close(client_socket);
    }

    close(server_socket);
    return 0;
}