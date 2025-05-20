//Falcon-180B DATASET v1.0 Category: Firewall ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define BUF_SIZE 1024
#define MAX_CONNECTIONS 10
#define PORT 8080

int main() {
    int master_socket, client_socket[MAX_CONNECTIONS], addrlen;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    char buffer[BUF_SIZE];
    int max_clients = 0;
    int i;

    // Create socket
    if ((master_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set options on the socket
    if (setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Bind the socket
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(master_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(master_socket, MAX_CONNECTIONS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Firewall is active.\n");

    while (1) {
        // Accept a new connection
        addrlen = sizeof(client_addr);
        if ((client_socket[max_clients] = accept(master_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        for (i = 0; i < max_clients; i++) {
            if (client_socket[i] == 0) {
                client_socket[i] = client_socket[max_clients];
                break;
            }
        }

        max_clients++;
    }

    return 0;
}