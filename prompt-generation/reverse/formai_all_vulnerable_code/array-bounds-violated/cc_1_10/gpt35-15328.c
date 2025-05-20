//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 8888

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int client_addr_len = sizeof(client_addr);
    char buffer[1024];
    int bytes_received;

    // create the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        printf("Error creating server socket\n");
        exit(1);
    }

    // bind the server socket to a port and IP address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding server socket to port\n");
        exit(1);
    }

    // listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        printf("Error listening for incoming connections\n");
        exit(1);
    }

    printf("Server waiting for incoming connections...\n");

    // accept incoming connections
    client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_socket < 0) {
        printf("Error accepting incoming connection\n");
        exit(1);
    }

    printf("Incoming connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // receive data from client and send response
    while (1) {
        // receive data from client
        bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes_received < 0) {
            printf("Error receiving data from client\n");
            exit(1);
        } else if (bytes_received == 0) { // connection closed by client
            break;
        } else { // data received
            buffer[bytes_received] = '\0';
            printf("Received message from client: %s\n", buffer);

            // send response to client
            if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
                printf("Error sending response to client\n");
                exit(1);
            }
        }
    }

    // close the client socket
    close(client_socket);

    // close the server socket
    close(server_socket);

    return 0;
}