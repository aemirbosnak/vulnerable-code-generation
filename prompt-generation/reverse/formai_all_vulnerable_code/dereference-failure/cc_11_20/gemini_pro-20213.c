//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_DATA_SIZE 1024

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the hostname and port number from the command line arguments.
    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Resolve the hostname to an IP address.
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    // Create a sockaddr_in structure.
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr = *(struct in_addr *)host->h_addr;

    // Connect to the FTP server.
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send the USER command.
    char *user = "USER anonymous\n";
    if (send(sockfd, user, strlen(user), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the response from the FTP server.
    char response[MAX_DATA_SIZE];
    if (recv(sockfd, response, MAX_DATA_SIZE, 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Print the response to the console.
    printf("%s", response);

    // Send the PASS command.
    char *pass = "PASS anonymous@example.com\n";
    if (send(sockfd, pass, strlen(pass), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the response from the FTP server.
    if (recv(sockfd, response, MAX_DATA_SIZE, 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Print the response to the console.
    printf("%s", response);

    // Send the LIST command.
    char *list = "LIST\n";
    if (send(sockfd, list, strlen(list), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the response from the FTP server.
    while (1) {
        if (recv(sockfd, response, MAX_DATA_SIZE, 0) == -1) {
            perror("recv");
            exit(EXIT_FAILURE);
        }

        // Print the response to the console.
        printf("%s", response);

        // Check if the response is the end of the list.
        if (strstr(response, "226 Transfer complete.") != NULL) {
            break;
        }
    }

    // Close the socket.
    close(sockfd);

    return 0;
}