//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    // Initializing the necessary variables
    int sockfd, port, status;
    struct sockaddr_in server_addr;
    char request[BUFFER_SIZE], response[BUFFER_SIZE];

    // Creating a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed : ");
        exit(EXIT_FAILURE);
    }

    // Asking the user for the server port number
    printf("Enter server port number : ");
    scanf("%d", &port);

    // Setting up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connecting to the server
    status = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (status < 0) {
        perror("Connection Failed : ");
        exit(EXIT_FAILURE);
    }

    // Asking the user for the HTTP request
    printf("Enter HTTP Request : ");
    getchar();
    fgets(request, BUFFER_SIZE, stdin);

    // Sending the HTTP request to the server
    status = send(sockfd, request, strlen(request), 0);
    if (status < 0) {
        perror("Failed to send request : ");
        exit(EXIT_FAILURE);
    }

    // Receiving the response from the server
    status = recv(sockfd, response, BUFFER_SIZE, 0);
    if (status < 0) {
        perror("Failed to receive response : ");
        exit(EXIT_FAILURE);
    }

    // Printing the received response
    printf("\nReceived Response : \n%s", response);

    // Closing the socket
    close(sockfd);

    return 0;
}