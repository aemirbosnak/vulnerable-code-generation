//Code Llama-13B DATASET v1.0 Category: Building a IMAP Client ; Style: complex
// Building a IMAP Client example program in a complex style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ctype.h>
#include <errno.h>

#define BUFSIZE 1024
#define MAXLINE 1024

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <host>\n", argv[0]);
        return 1;
    }

    // Parse the hostname and port from the argument
    char *host = argv[1];
    char *port = "143";

    // Create a socket for the connection
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("socket");
        return 1;
    }

    // Set up the server address structure
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(port));
    if (inet_pton(AF_INET, host, &server.sin_addr) <= 0)
    {
        perror("inet_pton");
        return 1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("connect");
        return 1;
    }

    // Read data from the server
    char buf[BUFSIZE];
    ssize_t n;
    while ((n = recv(sock, buf, BUFSIZE, 0)) > 0)
    {
        buf[n] = '\0';
        printf("%s", buf);
    }

    // Close the connection
    close(sock);

    return 0;
}