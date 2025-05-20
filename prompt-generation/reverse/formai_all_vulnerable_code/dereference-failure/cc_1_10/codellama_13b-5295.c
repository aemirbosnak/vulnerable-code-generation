//Code Llama-13B DATASET v1.0 Category: Networking ; Style: creative
// A unique C networking example program in a creative style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Structure for storing the address of the server
struct server_address {
    char hostname[100];
    char port[6];
};

// Function to create a socket and connect to the server
int connect_to_server(struct server_address *addr) {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket() error");
        return -1;
    }

    // Initialize the server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(addr->port));
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    // Get the server address
    server = gethostbyname(addr->hostname);
    if (server == NULL) {
        perror("gethostbyname() error");
        return -1;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect() error");
        return -1;
    }

    return sockfd;
}

// Function to send a message to the server
void send_message(int sockfd, char *message) {
    int n = write(sockfd, message, strlen(message));
    if (n < 0) {
        perror("write() error");
    }
}

// Function to receive a message from the server
void receive_message(int sockfd) {
    char buffer[1024];
    int n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("read() error");
    } else {
        printf("Received message: %s\n", buffer);
    }
}

int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        return 1;
    }

    // Create a server address structure
    struct server_address addr;
    strcpy(addr.hostname, argv[1]);
    strcpy(addr.port, argv[2]);

    // Connect to the server
    int sockfd = connect_to_server(&addr);
    if (sockfd < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    // Send a message to the server
    send_message(sockfd, "Hello, server!");

    // Receive a message from the server
    receive_message(sockfd);

    // Close the socket
    close(sockfd);

    return 0;
}