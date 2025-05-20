//Code Llama-13B DATASET v1.0 Category: Network Packet Monitoring ; Style: cheerful
/*
 * A cheerful C Network Packet Monitoring program
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>

// Global variables
int sockfd, new_sockfd, portno, n, pid, sock_len;
struct sockaddr_in server_addr, client_addr;
struct hostent *server, *client;
char buffer[BUFSIZ];

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void signal_handler(int signal) {
    printf("Received signal: %d\n", signal);
    close(sockfd);
    exit(0);
}

int main(int argc, char *argv[]) {
    // Set up the signal handler
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);

    // Check for valid arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    // Get the port number
    portno = atoi(argv[1]);

    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("Error creating socket");

    // Set up the server address
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(portno);

    // Bind the socket to the address
    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
        error("Error binding socket");

    // Listen for incoming connections
    listen(sockfd, 5);
    sock_len = sizeof(client_addr);

    // Accept incoming connections
    new_sockfd = accept(sockfd, (struct sockaddr *) &client_addr, &sock_len);
    if (new_sockfd < 0)
        error("Error accepting connection");

    // Create a new process to handle the connection
    pid = fork();
    if (pid < 0)
        error("Error forking process");
    else if (pid == 0) {
        // Child process: handle the connection
        close(sockfd);
        while (1) {
            // Read from the client
            n = read(new_sockfd, buffer, BUFSIZ);
            if (n < 0)
                error("Error reading from socket");
            if (n == 0)
                break;

            // Print the received data
            printf("Received: %s\n", buffer);

            // Send a response to the client
            n = write(new_sockfd, "Hello, client!", strlen("Hello, client!") + 1);
            if (n < 0)
                error("Error writing to socket");
        }

        // Close the socket and exit
        close(new_sockfd);
        exit(0);
    } else {
        // Parent process: close the socket and wait for the child to exit
        close(new_sockfd);
        wait(NULL);
    }

    // Close the socket and exit
    close(sockfd);
    return 0;
}