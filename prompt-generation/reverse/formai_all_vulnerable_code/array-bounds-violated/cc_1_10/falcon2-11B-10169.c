//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int server_fd, conn_fd, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024] = {0};

    // Create socket file descriptor
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8080);

    // Bind to the port
    if (bind(server_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    listen(server_fd, 3);

    while (1) {
        // Accept a connection
        conn_fd = accept(server_fd, (struct sockaddr *)&cli_addr, (socklen_t*)&n);
        if (conn_fd < 0) {
            perror("accept failed");
            continue;
        }

        // Receive data from client
        bzero(buffer, sizeof(buffer));
        n = recv(conn_fd, buffer, sizeof(buffer) - 1, 0);
        if (n < 0) {
            perror("recv failed");
            close(conn_fd);
            continue;
        }
        buffer[n] = '\0';

        // Send data back to client
        send(conn_fd, buffer, strlen(buffer), 0);

        // Close connection
        close(conn_fd);
    }

    // Close socket file descriptor
    close(server_fd);

    return 0;
}