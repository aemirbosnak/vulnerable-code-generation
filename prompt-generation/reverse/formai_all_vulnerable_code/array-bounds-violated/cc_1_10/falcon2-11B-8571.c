//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

// Define constants
#define MAX_MESSAGE_SIZE 512
#define SERVER_PORT 1234

// Define structures
struct sockaddr_in server;

// Define functions
void* receiveMessage(int sockfd, char *msg, int maxSize) {
    int n = 0;
    char buffer[MAX_MESSAGE_SIZE];
    while (1) {
        n = read(sockfd, buffer, maxSize);
        if (n <= 0)
            break;
        memcpy(msg, buffer, n);
        msg[n] = '\0'; // Null terminate the string
        printf("Received: %s\n", msg);
    }
    return NULL;
}

void* sendMessage(int sockfd, char *msg) {
    int n = 0;
    while (1) {
        n = write(sockfd, msg, strlen(msg));
        if (n <= 0)
            break;
        printf("Sent: %s\n", msg);
    }
    return NULL;
}

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Create a server socket
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(SERVER_PORT);
    int result = bind(sockfd, (struct sockaddr*)&server, sizeof(server));
    if (result < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // Start listening for connections
    listen(sockfd, 5);

    // Accept connections
    int client_sockfd;
    while ((client_sockfd = accept(sockfd, NULL, NULL))!= -1) {
        printf("Accepted a connection from client\n");

        // Receive message from client
        char msg[MAX_MESSAGE_SIZE];
        int size = recv(client_sockfd, msg, MAX_MESSAGE_SIZE - 1, 0);
        if (size <= 0) {
            printf("ERROR receiving message from client\n");
            continue;
        }
        msg[size] = '\0'; // Null terminate the string
        printf("Received message from client: %s\n", msg);

        // Send message to client
        sendMessage(client_sockfd, "Hello from server");

        // Close connection
        close(client_sockfd);
    }

    // Clean up
    close(sockfd);

    return 0;
}