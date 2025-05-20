//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_CONNECTIONS 10
#define PORT 8000

typedef struct {
    int sock_fd;
    int player_id;
} Connection;

Connection connections[MAX_CONNECTIONS];
int num_connections = 0;

void monitor_packet(Connection conn, char *packet) {
    // Your packet monitoring code goes here
    printf("Player %d sent packet: %s\n", conn.player_id, packet);
}

void handle_connection(int sock_fd) {
    if (num_connections >= MAX_CONNECTIONS) {
        printf("Maximum number of connections reached!\n");
        return;
    }

    Connection conn;
    conn.sock_fd = sock_fd;
    conn.player_id = num_connections + 1;

    connections[num_connections] = conn;
    num_connections++;

    printf("Player %d has connected!\n", conn.player_id);

    char buffer[1024];
    ssize_t num_bytes;

    while ((num_bytes = recv(sock_fd, buffer, 1024, 0)) > 0) {
        buffer[num_bytes] = '\0';
        monitor_packet(conn, buffer);
        send(sock_fd, "ACK", 3, 0);
    }

    printf("Player %d has disconnected!\n", conn.player_id);

    for (int i = 0; i < num_connections; i++) {
        if (connections[i].sock_fd == sock_fd) {
            // Remove connection from array
            for (int j = i; j < num_connections - 1; j++) {
                connections[j] = connections[j+1];
            }
            num_connections--;
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(server_addr);

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, addrlen);

    // Bind server socket to port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&server_addr, addrlen) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CONNECTIONS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d...\n", PORT);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        handle_connection(new_socket);
    }

    return 0;
}