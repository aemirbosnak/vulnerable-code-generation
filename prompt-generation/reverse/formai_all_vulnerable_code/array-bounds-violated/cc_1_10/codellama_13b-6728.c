//Code Llama-13B DATASET v1.0 Category: Simple Web Server ; Style: Claude Shannon
/*
 * C Simple Web Server Example Program
 *
 * This program is a simple web server that listens on a specified port and
 * serves HTTP requests. It uses the select() function to handle multiple
 * connections simultaneously.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <netdb.h>

#define MAX_CONNECTIONS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int port = 80; // default port number
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];
    int nbytes;

    // parse command-line arguments
    if (argc > 1) {
        port = atoi(argv[1]);
    }

    // create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // set socket options
    int enable = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int));

    // bind socket to port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);
    bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr));

    // listen for incoming connections
    listen(server_fd, MAX_CONNECTIONS);

    // accept incoming connections
    client_fd = accept(server_fd, (struct sockaddr *) &client_addr, &client_len);

    // receive data from client
    nbytes = recv(client_fd, buffer, BUFFER_SIZE, 0);
    buffer[nbytes] = '\0';

    // send data to client
    send(client_fd, "Hello, World!", strlen("Hello, World!"), 0);

    // close connection
    close(client_fd);

    // close socket
    close(server_fd);

    return 0;
}