//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: thoughtful
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <signal.h>

#define PORT 8080
#define MAX_CONNECTIONS 10
#define BUFFER_SIZE 1024

typedef struct {
    int socket;
    struct sockaddr_in addr;
} connection_t;

connection_t connections[MAX_CONNECTIONS];
int num_connections = 0;

void sigint_handler(int signum) {
    for (int i = 0; i < num_connections; i++) {
        close(connections[i].socket);
    }
    exit(0);
}

int main() {
    int server_socket;
    struct sockaddr_in server_addr;

    // Create the server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    // Set the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CONNECTIONS) == -1) {
        perror("listen");
        exit(1);
    }

    // Set up the signal handler
    signal(SIGINT, sigint_handler);

    // Main loop
    while (1) {
        // Accept an incoming connection
        int client_socket;
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        if ((client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_addr_len)) == -1) {
            perror("accept");
            continue;
        }

        // Add the connection to the list of connections
        connections[num_connections].socket = client_socket;
        connections[num_connections].addr = client_addr;
        num_connections++;

        // Handle the connection in a separate thread
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            close(client_socket);
            continue;
        } else if (pid == 0) {
            // Child process
            close(server_socket);

            // Receive data from the client
            char buffer[BUFFER_SIZE];
            while (1) {
                int bytes_received = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
                if (bytes_received == -1) {
                    perror("recv");
                    break;
                } else if (bytes_received == 0) {
                    // Client closed the connection
                    break;
                }

                // Process the data
                buffer[bytes_received] = '\0';
                printf("Received from client: %s\n", buffer);

                // Send data back to the client
                if (send(client_socket, buffer, bytes_received, 0) == -1) {
                    perror("send");
                    break;
                }
            }

            // Close the client socket
            close(client_socket);

            exit(0);
        } else {
            // Parent process
            close(client_socket);
        }
    }

    // Close the server socket
    close(server_socket);

    return 0;
}