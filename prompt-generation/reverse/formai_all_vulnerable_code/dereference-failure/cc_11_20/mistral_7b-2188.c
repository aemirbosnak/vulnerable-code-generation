//MISTRAL-7B DATASET v1.0 Category: Firewall ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define ALLOWED_PORTS "80,443"

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char *hello = "Welcome to the C Firewall!\n";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,
                   sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("%s", hello);

    while (1) {
        // Accepting new connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                                 (socklen_t *)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("New connection from %s:%d\n",
               inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // Receiving data from client
        valread = recv(new_socket, buffer, BUFFER_SIZE, 0);
        printf("Received: %s", buffer);

        // Checking if the connection is allowed based on the port number
        char *port_str = strtok(inet_ntoa(address.sin_addr), ":");
        int port = atoi(strtok(NULL, ":"));
        int is_allowed = 0;
        for (int i = 0; i < strlen(ALLOWED_PORTS); i++) {
            if (ALLOWED_PORTS[i] == ',' || ALLOWED_PORTS[i] == port + '0') {
                is_allowed = 1;
                break;
            }
        }

        // Sending response to the client
        if (is_allowed) {
            char *response = "Access granted!\n";
            send(new_socket, response, strlen(response), 0);
        } else {
            char *response = "Access denied!\n";
            send(new_socket, response, strlen(response), 0);
        }

        // Closing the connection
        close(new_socket);
    }

    return 0;
}