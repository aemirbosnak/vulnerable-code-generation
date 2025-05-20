//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define BUFF_SIZE 1024

int main(int argc, char **argv) {
    int sockfd, bytes_received;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buffer[BUFF_SIZE];
    clock_t start, end;
    double time_taken;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <server_address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Get the server's address
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "gethostbyname");
        exit(EXIT_FAILURE);
    }

    // Set up the server's address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Start the timer
    start = clock();

    // Send a message to the server
    if (send(sockfd, "Hello", 5, 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive a message from the server
    bytes_received = recv(sockfd, buffer, BUFF_SIZE, 0);
    if (bytes_received == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Stop the timer
    end = clock();

    // Calculate the time taken
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the results
    printf("The time taken to send and receive a message was %f seconds\n", time_taken);

    // Close the socket
    close(sockfd);

    return 0;
}