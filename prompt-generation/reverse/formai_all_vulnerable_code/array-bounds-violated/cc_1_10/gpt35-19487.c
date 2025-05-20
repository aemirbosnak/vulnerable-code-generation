//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: introspective
/* This HTTP client example program is designed to demonstrate the use of sockets in C. 
It establishes a connection to a specified server and sends a GET request asking for a particular resource.
The response is then printed to the console. */

#include <stdio.h>      // standard input and output
#include <stdlib.h>     // standard library functions (e.g. atoi())
#include <string.h>     // string manipulation functions
#include <sys/socket.h> // socket functions
#include <arpa/inet.h>  // internet address functions
#include <unistd.h>     // close() function

#define DEFAULT_PORT 80  // default HTTP port
#define MAX_REQUEST_SIZE 2048  // maximum size of HTTP request


int main(int argc, char* argv[]) {

    char* server_ip = "127.0.0.1";  // default local IP address
    int server_port = DEFAULT_PORT; // default HTTP port

    // If server address and/or port are specified as command-line arguments, override defaults
    if (argc > 1) server_ip = argv[1];
    if (argc > 2) server_port = atoi(argv[2]);

    // Create a socket for communication with the server
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Specify the server address and port number to connect to
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));  // zero out the structure
    server_address.sin_family = AF_INET;  // IPv4
    server_address.sin_port = htons(server_port);  // convert port number to network byte order
    if (inet_pton(AF_INET, server_ip, &server_address.sin_addr) <= 0) {
        perror("Invalid server address");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }

    // Prepare HTTP request string
    char request[MAX_REQUEST_SIZE];
    memset(request, 0, MAX_REQUEST_SIZE);  // zero out request buffer
    sprintf(request, "GET / HTTP/1.1\r\n"
                      "Host: %s\r\n"
                      "Connection: close\r\n"
                      "\r\n", server_ip);

    // Send HTTP request to server
    if (send(client_socket, request, strlen(request), 0) < 0) {
        perror("Failed to send request");
        exit(EXIT_FAILURE);
    }

    // Receive response from server
    char response[MAX_REQUEST_SIZE];
    memset(response, 0, MAX_REQUEST_SIZE);  // zero out response buffer
    int num_bytes_received = 0;
    while ((num_bytes_received = recv(client_socket, response, MAX_REQUEST_SIZE-1, 0)) > 0) {
        response[num_bytes_received] = '\0';  // null-terminate the response
        printf("%s", response);  // print the response to the console
        memset(response, 0, MAX_REQUEST_SIZE);  // zero out response buffer
    }

    // Close the socket
    close(client_socket);

    return 0;
}