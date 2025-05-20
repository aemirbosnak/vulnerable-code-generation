//FormAI DATASET v1.0 Category: Networking ; Style: relaxed
/*
 * This is a unique C Networking example program that demonstrates how to download a webpage 
   using TCP/IP sockets.
 *
 * The program connects to a remote server and requests a webpage. The server responds by 
   sending the webpage back as an HTTP response. The program reads the response and prints 
   it to the console.
 *
 * This program uses the "socket" and "connect" system calls to establish a TCP/IP connection, 
   and the "send" and "recv" system calls to send and receive data.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) 
{
    int sockfd, num_bytes;
    char buffer[MAX_BUFFER_SIZE];
    struct addrinfo *result;

    if(argc != 2) 
    {
        fprintf(stderr, "usage: %s <url>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Get server info */
    getaddrinfo(argv[1], "http", NULL, &result);

    /* Create socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    /* Connect to server */
    connect(sockfd, result->ai_addr, result->ai_addrlen);

    /* Send HTTP request */
    sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
    send(sockfd, buffer, strlen(buffer), 0);

    /* Read HTTP response */
    while((num_bytes = recv(sockfd, buffer, MAX_BUFFER_SIZE-1, 0)) > 0) 
    {
        buffer[num_bytes] = '\0';
        printf("%s", buffer);
    }

    /* Cleanup */
    freeaddrinfo(result);
    close(sockfd);

    return 0;
}