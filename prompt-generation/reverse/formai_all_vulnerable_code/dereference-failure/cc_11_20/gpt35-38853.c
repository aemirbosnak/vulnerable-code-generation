//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10

int main(int argc, char* argv[]) {
    int server_socket, client_socket[MAX_CLIENTS], max_clients = MAX_CLIENTS, activity, i, valread, sd;
    struct sockaddr_in server_address;
    char client_message[1024], server_message[1024];
    fd_set readfds;

    // Creating server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Server socket creation error");
        exit(EXIT_FAILURE);
    }

    // Setting server address and port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8888);

    // Binding the socket to the server address and port
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Binding error");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("Listening error");
        exit(EXIT_FAILURE);
    }

    // Adding server socket to the set
    FD_ZERO(&readfds);
    FD_SET(server_socket, &readfds);

    while (1) {
        // Selecting sockets for a new activity
        activity = select(MAX_CLIENTS + 1, &readfds, NULL, NULL, NULL);

        if (activity < 0) {
            perror("Select error");
            exit(EXIT_FAILURE);
        }

        // Handling incoming connection
        if (FD_ISSET(server_socket, &readfds)) {
            int new_socket;
            if ((new_socket = accept(server_socket, (struct sockaddr *)&server_address, (socklen_t*)&server_address)) < 0) {
                perror("Accept error");
                exit(EXIT_FAILURE);
            }

            printf("New connection established: socket fd is %d, IP is : %s, port : %d\n", 
                new_socket, inet_ntoa(server_address.sin_addr), ntohs(server_address.sin_port));

            // Adding new socket to array of clients
            for (i = 0; i < max_clients; i++) {
                if (client_socket[i] == 0) {
                    client_socket[i] = new_socket;
                    printf("Added to list of sockets as %d\n", i);
                    break;
                }
            }
        }

        // Handling user input
        for (i = 0; i < max_clients; i++) {
            sd = client_socket[i];

            if (FD_ISSET(sd, &readfds)) {
                // Closing connection and removing from set if client disconnected
                if ((valread = read(sd, client_message, 1024)) == 0) {
                    printf("Client with socket fd %d disconnected\n", sd);
                    close(sd);
                    client_socket[i] = 0;
                }
                // Sending message to all clients if received from client
                else {
                    client_message[valread] = '\0';
                    printf("Received message from client with socket fd %d: %s", sd, client_message);
                    sprintf(server_message, "You sent: %s", client_message);
                    for (i = 0; i < max_clients; i++) {
                        if (client_socket[i] != 0 && client_socket[i] != sd) {
                            send(client_socket[i], server_message, strlen(server_message), 0);
                        }
                    }
                }
            }
        }
    }

    return 0;
}