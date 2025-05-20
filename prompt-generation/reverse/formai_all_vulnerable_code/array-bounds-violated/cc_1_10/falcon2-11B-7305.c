//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <sys/types.h>

#define SERVER_PORT 8080

int main() {
    int sockfd, client_num, new_socket, n;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;

    int buffer_size = 1024;
    char buffer[buffer_size];

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // Initialize server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    // Bind the socket to the port
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Start listening
    if (listen(sockfd, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    while (1) {
        // Accept a connection
        client_num = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_num < 0) {
            perror("accept failed");
            exit(1);
        }

        // Receive message from client
        printf("New client connected\n");
        while ((n = recv(client_num, buffer, buffer_size, 0)) > 0) {
            buffer[n] = '\0';
            printf("From client: %s\n", buffer);
            send(client_num, buffer, strlen(buffer), 0);
        }

        close(client_num);
    }

    close(sockfd);
    return 0;
}