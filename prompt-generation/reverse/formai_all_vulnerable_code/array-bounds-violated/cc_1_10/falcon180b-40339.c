//Falcon-180B DATASET v1.0 Category: Chat server ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_CLIENTS 10
#define PORT 8080

int main(int argc, char *argv[]) {
    int server_socket, client_socket[MAX_CLIENTS], max_socket;
    int opt = 1;
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    char buffer[1024];
    int addrlen = sizeof(client_addr[0]);
    int i = 0;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set options on the socket
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to an address and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is running on port %d\n", PORT);

    while (1) {
        // Accept a new connection
        if ((client_socket[i] = accept(server_socket, (struct sockaddr *)&client_addr[i], (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        inet_ntop(AF_INET, &client_addr[i].sin_addr, buffer, sizeof(buffer));
        printf("New connection from %s\n", buffer);

        i++;

        if (i >= MAX_CLIENTS) {
            printf("Maximum number of clients reached\n");
            close(client_socket[i]);
            i--;
        }
    }

    return 0;
}