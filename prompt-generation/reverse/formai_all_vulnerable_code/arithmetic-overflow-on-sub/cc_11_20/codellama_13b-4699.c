//Code Llama-13B DATASET v1.0 Category: Robot movement control ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 8080
#define MAX_CLIENTS 10

struct robot_state {
    int x;
    int y;
    int z;
    int angle;
};

struct robot_cmd {
    int cmd;
    int arg1;
    int arg2;
    int arg3;
};

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    struct robot_state state;
    struct robot_cmd cmd;

    // Create socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("socket");
        exit(1);
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_sock, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(1);
    }

    printf("Server started on port %d\n", PORT);

    // Accept incoming connections
    while (1) {
        client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("accept");
            continue;
        }

        // Read robot state from client
        if (read(client_sock, &state, sizeof(state)) < 0) {
            perror("read");
            continue;
        }

        // Read robot command from client
        if (read(client_sock, &cmd, sizeof(cmd)) < 0) {
            perror("read");
            continue;
        }

        // Update robot state based on command
        switch (cmd.cmd) {
            case 1: // Move forward
                state.x += cmd.arg1;
                state.y += cmd.arg2;
                break;
            case 2: // Turn left
                state.angle += cmd.arg1;
                break;
            case 3: // Turn right
                state.angle -= cmd.arg1;
                break;
            default:
                printf("Invalid command\n");
                continue;
        }

        // Write updated robot state back to client
        if (write(client_sock, &state, sizeof(state)) < 0) {
            perror("write");
            continue;
        }

        // Close connection
        close(client_sock);
    }

    // Close server socket
    close(server_sock);

    return 0;
}