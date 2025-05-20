//FormAI DATASET v1.0 Category: Chat server ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket, nread, i;
    char buffer[BUF_SIZE];
    struct sockaddr_in server, client;
    int client_sock[MAX_CLIENTS];
    int max_sd, sd;
    fd_set fds;

    // Create a socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(atoi(argv[1]));

    // Bind the socket to port
    if (bind(server_socket, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen error");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections and handle them
    puts("Waiting for incoming connections...");
    while (1) {
        // Clear the file descriptor set
        FD_ZERO(&fds);

        // Add the server socket to the set
        FD_SET(server_socket, &fds);
        max_sd = server_socket;

        // Add the active client sockets to the set
        for (i = 0; i < MAX_CLIENTS; i++) {
            sd = client_sock[i];
            if (sd > 0) {
                FD_SET(sd, &fds);
            }
            if (sd > max_sd) {
                max_sd = sd;
            }
        }

        // Wait for activity on one of the sockets
        if (select(max_sd + 1, &fds, NULL, NULL, NULL) < 0) {
            perror("Select error");
            exit(EXIT_FAILURE);
        }

        // If the server socket is ready, accept the incoming connection
        if (FD_ISSET(server_socket, &fds)) {
            socklen_t client_len = sizeof(client);
            if ((client_socket = accept(server_socket, (struct sockaddr *) &client, &client_len)) < 0) {
                perror("Accept error");
                exit(EXIT_FAILURE);
            }

            // Add the new client to the client_sock array
            for (i = 0; i < MAX_CLIENTS; i++) {
                if (client_sock[i] == 0) {
                    client_sock[i] = client_socket;
                    printf("New connection, socket fd is %d, ip is : %s, port : %d\n", client_socket, inet_ntoa(client.sin_addr), ntohs(client.sin_port));
                    break;
                }
            }
        }

        // Handle incoming data from a client socket
        for (i = 0; i < MAX_CLIENTS; i++) {
            sd = client_sock[i];
            if (FD_ISSET(sd, &fds)) {
                if ((nread = read(sd, buffer, BUF_SIZE)) == 0) {
                    // Client has disconnected
                    getpeername(sd, (struct sockaddr *) &client, (socklen_t *) &client);
                    printf("Host disconnected, ip %s, port %d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
                    close(sd);
                    client_sock[i] = 0;
                } else {
                    // Send the message to other clients
                    for (int j = 0; j < MAX_CLIENTS; j++) {
                        if (client_sock[j] != 0 && client_sock[j] != sd) {
                            write(client_sock[j], buffer, nread);
                        }
                    }
                }
            }
        }
    }

    return 0;
}