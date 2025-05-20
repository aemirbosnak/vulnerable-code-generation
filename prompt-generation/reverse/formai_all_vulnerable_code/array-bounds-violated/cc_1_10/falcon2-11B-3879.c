//Falcon2-11B DATASET v1.0 Category: Networking ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int server_fd, new_fd, addrlen;
    struct sockaddr_in server_addr, client_addr;

    // Create a socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Prepare the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    // Bind the socket to the server address
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Listening for incoming connections...\n");

    // Accept incoming connections
    while (1) {
        // Accept a connection
        if ((new_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addrlen)) == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Create a new thread for the accepted connection
        if (fork() == 0) {
            close(server_fd);

            // Handle the accepted connection
            char buf[1024];
            int bytes_read;
            while ((bytes_read = recv(new_fd, buf, sizeof(buf), 0)) > 0) {
                buf[bytes_read] = '\0';
                printf("%s\n", buf);
                bytes_read = send(new_fd, "ACK\n", sizeof("ACK\n") - 1, 0);
                if (bytes_read == -1) {
                    perror("send");
                    exit(EXIT_FAILURE);
                }
            }

            // Close the accepted connection
            close(new_fd);
            exit(EXIT_SUCCESS);
        }
    }

    return 0;
}