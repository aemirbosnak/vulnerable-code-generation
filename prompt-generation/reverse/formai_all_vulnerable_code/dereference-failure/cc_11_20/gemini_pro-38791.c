//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_address> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Get the server address.
    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }

    // Create the server address structure.
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    memcpy(&server_addr.sin_addr, server->h_addr, server->h_length);

    // Connect to the server.
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the command to the server.
    char command[256];
    sprintf(command, "USER anonymous\r\n");
    if (send(sockfd, command, strlen(command), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the server.
    char response[256];
    if (recv(sockfd, response, sizeof(response), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the response to the screen.
    printf("%s", response);

    // Send the password to the server.
    sprintf(command, "PASS anonymous@example.com\r\n");
    if (send(sockfd, command, strlen(command), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the server.
    if (recv(sockfd, response, sizeof(response), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the response to the screen.
    printf("%s", response);

    // Send the command to list the files in the current directory.
    sprintf(command, "LIST\r\n");
    if (send(sockfd, command, strlen(command), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the server.
    while (1) {
        if (recv(sockfd, response, sizeof(response), 0) == -1) {
            perror("recv");
            return EXIT_FAILURE;
        }

        // Print the response to the screen.
        printf("%s", response);

        // Check if the response is the end of the list.
        if (strstr(response, "226 Transfer complete") != NULL) {
            break;
        }
    }

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}