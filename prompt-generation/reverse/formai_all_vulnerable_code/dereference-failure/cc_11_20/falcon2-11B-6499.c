//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    // Check for invalid command line arguments
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <host> <port> <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Initialize the variables
    int sockfd;
    struct hostent *server;
    struct sockaddr_in server_address;
    int n;

    // Connect to the server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: host not found\n");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send the command to the server
    char command[256] = "TYPE I\r\n";
    n = write(sockfd, command, strlen(command));
    if (n < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Receive the response from the server
    char response[256];
    bzero(response, sizeof(response));
    n = read(sockfd, response, sizeof(response));
    if (n < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    // Check the response and handle accordingly
    if (strcmp(response, "200 TYPE set\r\n")!= 0) {
        fprintf(stderr, "Error: invalid response from the server\n");
        exit(EXIT_FAILURE);
    }

    // Send the filename to the server
    sprintf(command, "STOR %s\r\n", argv[3]);
    n = write(sockfd, command, strlen(command));
    if (n < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Receive the response from the server
    bzero(response, sizeof(response));
    n = read(sockfd, response, sizeof(response));
    if (n < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    // Check the response and handle accordingly
    if (strcmp(response, "150 Opening data connection\r\n")!= 0) {
        fprintf(stderr, "Error: invalid response from the server\n");
        exit(EXIT_FAILURE);
    }

    // Receive the file from the server
    FILE *file = fopen(argv[3], "w");
    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    int nread;
    while ((nread = read(sockfd, buffer, sizeof(buffer))) > 0) {
        fwrite(buffer, 1, nread, file);
    }
    fclose(file);

    // Send the EOF marker to the server
    sprintf(command, "EOF\r\n");
    n = write(sockfd, command, strlen(command));
    if (n < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Receive the response from the server
    bzero(response, sizeof(response));
    n = read(sockfd, response, sizeof(response));
    if (n < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    // Check the response and handle accordingly
    if (strcmp(response, "226 Transfer complete\r\n")!= 0) {
        fprintf(stderr, "Error: invalid response from the server\n");
        exit(EXIT_FAILURE);
    }

    // Close the connection to the server
    close(sockfd);

    return 0;
}