//FormAI DATASET v1.0 Category: Networking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT "8080" // the port used for the connection

int main()
{
    int sockfd; // socket file descriptor
    struct addrinfo hints, *servinfo, *p;
    int status;
    int bytes_sent, bytes_received;
    char send_buffer[1024], receive_buffer[1024];

    memset(&hints, 0, sizeof hints); // make sure the struct is empty
    hints.ai_family = AF_UNSPEC; // don't care if IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM; // TCP stream sockets

    // get the server's IP address and port number
    if ((status = getaddrinfo("localhost", PORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(1);
    }

    // loop through all the results and connect to the first we can
    for (p = servinfo; p != NULL; p = p->ai_next) {
        // create the socket
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("client: socket");
            continue;
        }

        // connect to the server
        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("client: connect");
            continue;
        }

        break; // if we get here, we have successfully connected
    }

    if (p == NULL) {
        fprintf(stderr, "client: failed to connect\n");
        exit(2);
    }

    freeaddrinfo(servinfo); // cleanup

    printf("Enter a message to send to the server: ");
    fgets(send_buffer, 1024, stdin);

    bytes_sent = send(sockfd, send_buffer, strlen(send_buffer), 0); // send the message to the server
    if (bytes_sent == -1) {
        perror("client: send");
        exit(3);
    }

    printf("Waiting for response from the server...\n");

    bytes_received = recv(sockfd, receive_buffer, 1023, 0); // receive the response from the server
    if (bytes_received == -1) {
        perror("client: receive");
        exit(4);
    }

    receive_buffer[bytes_received] = '\0';

    printf("Server response: %s\n", receive_buffer);

    close(sockfd); // close the socket

    return 0;
}