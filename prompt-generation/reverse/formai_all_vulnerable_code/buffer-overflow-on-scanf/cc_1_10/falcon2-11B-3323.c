//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_LENGTH 1024

int main() {
    // Creating a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Assigning server address and port number
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(1234);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connecting to server
    if(connect(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Receiving data from the server
    char buffer[MAX_LENGTH];
    int bytes_received = recv(sockfd, buffer, MAX_LENGTH, 0);
    if(bytes_received <= 0) {
        perror("Error receiving data");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0';

    // Sending data to the server
    char message[MAX_LENGTH];
    printf("Enter message to send: ");
    scanf("%s", message);
    if(send(sockfd, message, strlen(message), 0) < 0) {
        perror("Error sending data");
        exit(EXIT_FAILURE);
    }

    // Closing socket
    close(sockfd);

    return 0;
}