//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXSIZE 1024

// Function to create a socket descriptor
int create_socket_descriptor(char* url) {
    struct addrinfo hints, *res;
    int sockfd;

    // Initialize hints
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // Get address info using getaddrinfo function
    int status = getaddrinfo(url, "http", &hints, &res);
    if (status != 0) {
        printf("Failed to retrieve address info: %s\n", gai_strerror(status));
        exit(1);
    }

    // Create the socket descriptor
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        printf("Failed to create socket descriptor\n");
        exit(1);
    }

    // Connect the socket to the address
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        close(sockfd);
        printf("Failed to connect to address\n");
        exit(1);
    }

    freeaddrinfo(res);
    return sockfd;
}

// Function to send the GET request to the server
void send_request(int sockfd, char* url) {
    char buffer[MAXSIZE];
    sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", url);
    int len = strlen(buffer);

    // Send the request to the server
    if (send(sockfd, buffer, len, 0) == -1) {
        printf("Failed to send request\n");
        exit(1);
    }
}

// Main function to execute the program
int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./httpclient <url>\n");
        exit(1);
    }

    // Get the url from the command line arguments
    char* url = argv[1];

    // Create the socket descriptor and send the request to the server
    int sockfd = create_socket_descriptor(url);
    send_request(sockfd, url);

    // Receive the response from the server and print it to the console
    char response[MAXSIZE];
    int bytes_received = recv(sockfd, response, MAXSIZE-1, 0);
    while (bytes_received > 0) {
        response[bytes_received] = '\0';
        printf("%s", response);
        bytes_received = recv(sockfd, response, MAXSIZE-1, 0);
    }

    // Close the socket descriptor and exit the program
    close(sockfd);
    return 0;
}