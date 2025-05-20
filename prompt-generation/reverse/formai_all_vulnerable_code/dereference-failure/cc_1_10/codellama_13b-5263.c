//Code Llama-13B DATASET v1.0 Category: Networking ; Style: Sherlock Holmes
/*
 * A Sherlock Holmes-style networking example program in C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 10

int main(int argc, char **argv)
{
    int sockfd, new_fd;
    struct sockaddr_in address;
    struct sockaddr_in client_address;
    int client_len = sizeof(client_address);
    char buffer[256];

    // create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Error: cannot create socket");
        exit(1);
    }

    // set up address structure
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // bind the socket to the port
    if (bind(sockfd, (struct sockaddr *) &address, sizeof(address)) < 0)
    {
        perror("Error: cannot bind to port");
        exit(1);
    }

    // listen for incoming connections
    if (listen(sockfd, MAX_CLIENTS) < 0)
    {
        perror("Error: cannot listen for incoming connections");
        exit(1);
    }

    // accept incoming connections
    new_fd = accept(sockfd, (struct sockaddr *) &client_address, &client_len);
    if (new_fd < 0)
    {
        perror("Error: cannot accept incoming connection");
        exit(1);
    }

    // send a message to the client
    sprintf(buffer, "Hello, client! I am Sherlock Holmes, the greatest detective of all time.");
    send(new_fd, buffer, strlen(buffer), 0);

    // receive a message from the client
    recv(new_fd, buffer, sizeof(buffer), 0);

    // close the socket
    close(new_fd);

    return 0;
}