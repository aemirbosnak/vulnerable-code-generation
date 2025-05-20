//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Create a server address structure
    struct sockaddr_in serv_addr;
    memset((char*)&serv_addr, '\0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(5000);

    // Bind the socket to the address
    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening on the socket
    listen(sockfd, 3);

    while (1) {
        // Accept the connection
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_fd = accept(sockfd, (struct sockaddr*)&client_addr, &client_len);
        if (client_fd < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Allocate memory for the message
        char message[256];
        int len = recv(client_fd, message, sizeof(message) - 1, 0);
        if (len <= 0) {
            perror("recv failed");
            exit(EXIT_FAILURE);
        }
        message[len] = '\0';

        // Print the message
        printf("Received message: %s\n", message);

        // Send a response
        sprintf(message, "Hello, %s!", message);
        send(client_fd, message, strlen(message), 0);

        // Close the connection
        close(client_fd);
    }

    close(sockfd);
    return 0;
}