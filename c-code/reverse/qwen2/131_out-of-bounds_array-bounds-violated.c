#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFSIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFSIZE] = {0};
    const char *commands[] = {"takeoff", "land", "forward", "backward", "left", "right", "flip front", "flip back"};
    int num_commands = sizeof(commands) / sizeof(commands[0]);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Setting up the address struct
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        // Accepting a new connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            continue;
        }

        // Reading data from the client
        read(new_socket, buffer, BUFSIZE);
        printf("Received command: %s\n", buffer);

        // Simulating sending command to drone
        int found = 0;
        for (int i = 0; i < num_commands; i++) {
            if (strcmp(buffer, commands[i]) == 0) {
                printf("Sending command to drone: %s\n", buffer);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Unknown command received: %s\n", buffer);
        }

        // Closing the connection
        close(new_socket);
    }

    return 0;
}
