//Falcon2-11B DATASET v1.0 Category: Networking ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define SERVER_PORT 8080

void send_message(int sockfd) {
    char message[] = "Hello World!";
    send(sockfd, message, strlen(message), 0);
}

void receive_message(int sockfd) {
    char buffer[1024];
    int bytes_read = recv(sockfd, buffer, sizeof(buffer), 0);
    buffer[bytes_read] = '\0';
    printf("Received: %s\n", buffer);
}

int main() {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char message[] = "Hello World!";
    int n;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Prepare server address struct
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(SERVER_PORT);

    // Bind to the port
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    listen(sockfd, 5);

    printf("Waiting for a connection...\n");

    // Accept connection and receive message
    while ((n = accept(sockfd, NULL, NULL))!= -1) {
        int client_sockfd = n;
        char buffer[1024];
        int bytes_read = recv(client_sockfd, buffer, sizeof(buffer), 0);
        buffer[bytes_read] = '\0';
        printf("Received: %s\n", buffer);
        send_message(client_sockfd);
        close(client_sockfd);
    }

    // Clean up
    close(sockfd);
    return 0;
}