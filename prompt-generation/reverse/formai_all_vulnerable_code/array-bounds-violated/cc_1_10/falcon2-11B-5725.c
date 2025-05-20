//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    // Open a socket connection to the remote server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    // Connect to the server using its IP address and port number
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0)
    {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Send a request to the server
    char request[100];
    sprintf(request, "GET / HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n");
    send(sockfd, request, strlen(request), 0);

    // Receive the response from the server
    char response[1000];
    int num_bytes = recv(sockfd, response, sizeof(response) - 1, 0);
    if (num_bytes < 0)
    {
        perror("Error receiving response");
        exit(EXIT_FAILURE);
    }
    response[num_bytes] = '\0';

    // Print the response from the server
    printf("%s\n", response);

    // Close the socket connection
    close(sockfd);

    return 0;
}