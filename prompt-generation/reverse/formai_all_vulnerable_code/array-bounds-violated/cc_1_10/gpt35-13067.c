//FormAI DATASET v1.0 Category: Socket programming ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_DATA_SIZE 100

int main() {
    int sockfd, newfd, rc;
    struct sockaddr_in server, client;
    char data[MAX_DATA_SIZE];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind the socket to localhost port 8080
    rc = bind(sockfd, (struct sockaddr *)&server, sizeof(server));
    if (rc == -1) {
        perror("Socket binding failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    rc = listen(sockfd, 5);
    if (rc == -1) {
        perror("Socket listening failed");
        exit(EXIT_FAILURE);
    }
    puts("Waiting for incoming connections...");

    // Accept incoming connections
    int c = sizeof(struct sockaddr_in);
    newfd = accept(sockfd, (struct sockaddr *)&client, (socklen_t *)&c);
    if (newfd == -1) {
        perror("Socket accept failed");
        exit(EXIT_FAILURE);
    }

    // Get client's IP address and port number
    char *cli_addr = inet_ntoa(client.sin_addr);
    int cli_port = ntohs(client.sin_port);
    printf("Connection accepted from %s:%d\n", cli_addr, cli_port);

    while (1) {
        // Receive data from client
        rc = recv(newfd, data, MAX_DATA_SIZE, 0);
        if (rc == -1) {
            perror("Data receiving failed");
            exit(EXIT_FAILURE);
        }
        if (rc == 0) {
            printf("Connection closed by client %s:%d\n", cli_addr, cli_port);
            break;
        }

        // Process data and send response to client
        data[rc] = '\0';
        printf("Data received from %s:%d: %s", cli_addr, cli_port, data);
        char *response = "Server received your message";
        rc = send(newfd, response, strlen(response), 0);
        if (rc == -1) {
            perror("Response sending failed");
            exit(EXIT_FAILURE);
        }
        printf("Response sent to %s:%d: %s\n", cli_addr, cli_port, response);
    }

    // Close the sockets
    close(newfd);
    close(sockfd);
    return 0;
}