//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_BUF 1024

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    // Get the hostname and port number from the command line arguments.
    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Create a socket for the FTP connection.
    int sockfd = socket(PF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Get the IP address of the FTP server.
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        return 1;
    }

    // Connect to the FTP server.
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *(struct in_addr *)host->h_addr;
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return 1;
    }

    // Send the FTP command to the server.
    char command[MAX_BUF];
    printf("Enter the FTP command: ");
    scanf("%s", command);
    if (send(sockfd, command, strlen(command), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the response from the FTP server.
    char response[MAX_BUF];
    if (recv(sockfd, response, MAX_BUF, 0) == -1) {
        perror("recv");
        return 1;
    }

    // Print the response from the FTP server.
    printf("%s", response);

    // Close the FTP connection.
    close(sockfd);

    return 0;
}