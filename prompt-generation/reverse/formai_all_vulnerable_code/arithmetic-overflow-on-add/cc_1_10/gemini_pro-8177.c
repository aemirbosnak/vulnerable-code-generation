//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

// Function to create a socket and connect to a server
int create_socket_and_connect(char *hostname, int port)
{
    struct sockaddr_in server_addr;
    int sockfd;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    return sockfd;
}

// Function to send a message to a server
void send_message(int sockfd, char *message)
{
    int len = strlen(message);

    // Send the message length
    if (send(sockfd, &len, sizeof(len), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Send the message
    if (send(sockfd, message, len, 0) < 0) {
        perror("send");
        exit(1);
    }
}

// Function to receive a message from a server
char *receive_message(int sockfd)
{
    int len;
    char *message;

    // Receive the message length
    if (recv(sockfd, &len, sizeof(len), 0) < 0) {
        perror("recv");
        exit(1);
    }

    // Allocate memory for the message
    message = malloc(len + 1);
    if (message == NULL) {
        perror("malloc");
        exit(1);
    }

    // Receive the message
    if (recv(sockfd, message, len, 0) < 0) {
        perror("recv");
        exit(1);
    }

    // Null-terminate the message
    message[len] = '\0';

    return message;
}

// Function to close a socket
void close_socket(int sockfd)
{
    close(sockfd);
}

// Main function
int main(int argc, char **argv)
{
    int sockfd;
    char *hostname;
    int port;
    char *message;
    char *response;
    time_t start, end;
    double rtt;

    // Parse the command line arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s hostname port message\n", argv[0]);
        exit(1);
    }
    hostname = argv[1];
    port = atoi(argv[2]);
    message = argv[3];

    // Create a socket and connect to the server
    sockfd = create_socket_and_connect(hostname, port);

    // Send the message to the server
    start = time(NULL);
    send_message(sockfd, message);

    // Receive the response from the server
    response = receive_message(sockfd);
    end = time(NULL);

    // Calculate the round-trip time
    rtt = difftime(end, start);

    // Print the response and the round-trip time
    printf("Response: %s\n", response);
    printf("Round-trip time: %lf seconds\n", rtt);

    // Close the socket
    close_socket(sockfd);

    return 0;
}