//FormAI DATASET v1.0 Category: Client Server Application ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
       
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
       
    // Setting socket options to reuse address and port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Setting server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
       
    // Binding socket to the server address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
     
    // Listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    while(1) {
        // Accepting incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("New client connected with IP address: %s\n", inet_ntoa(address.sin_addr));

        char buffer[MAX_BUFFER_SIZE];
        int bytes_read;

        // Receiving data from client
        while ((bytes_read = recv(new_socket, buffer, MAX_BUFFER_SIZE, 0)) != 0) {
            buffer[bytes_read] = '\0';
            printf("Received message from client: %s\n", buffer);

            // Echoing data back to client
            send(new_socket, buffer, strlen(buffer), 0);
            printf("Echoed message back to client\n\n");
        }

        // Closing socket
        printf("Client disconnected with IP address: %s\n", inet_ntoa(address.sin_addr));
        close(new_socket);
    }

    return 0;
}