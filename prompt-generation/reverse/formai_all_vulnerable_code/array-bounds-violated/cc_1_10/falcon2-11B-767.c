//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_BUFFER_SIZE];
    char command[MAX_BUFFER_SIZE];
    char response[MAX_BUFFER_SIZE];

    // Check for correct usage
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    // Resolve the hostname
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error resolving hostname\n");
        exit(1);
    }

    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    // Connect to the server
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error connecting to server\n");
        exit(1);
    }

    // Send the command
    printf("Enter the command: ");
    fgets(command, MAX_BUFFER_SIZE, stdin);
    n = strlen(command);
    if (send(sockfd, command, n, 0) < 0) {
        fprintf(stderr, "Error sending command\n");
        exit(1);
    }

    // Read the response
    bzero(response, MAX_BUFFER_SIZE);
    n = recv(sockfd, response, MAX_BUFFER_SIZE, 0);
    if (n <= 0) {
        fprintf(stderr, "Error receiving response\n");
        exit(1);
    }
    response[n-1] = '\0';
    printf("Response: %s\n", response);

    // Close the socket
    close(sockfd);

    return 0;
}