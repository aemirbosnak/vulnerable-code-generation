//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <port> <username>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the hostname, port, and username from the command line.
    char *hostname = argv[1];
    uint16_t port = (uint16_t) atoi(argv[2]);
    char *username = argv[3];

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the server.
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    int status = inet_pton(AF_INET, hostname, &server_addr.sin_addr);
    if (status < 0) {
        perror("inet_pton");
        return EXIT_FAILURE;
    } else if (status == 0) {
        fprintf(stderr, "Invalid hostname: %s\n", hostname);
        return EXIT_FAILURE;
    }
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the HELO command.
    char *helo_command = "HELO localhost\r\n";
    status = send(sockfd, helo_command, strlen(helo_command), 0);
    if (status == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the HELO response.
    char helo_response[1024];
    status = recv(sockfd, helo_response, sizeof(helo_response) - 1, 0);
    if (status == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    helo_response[status] = '\0';
    printf("%s\n", helo_response);

    // Send the AUTHENTICATE PLAIN command.
    char *auth_command = "AUTHENTICATE PLAIN\r\n";
    status = send(sockfd, auth_command, strlen(auth_command), 0);
    if (status == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the AUTHENTICATE PLAIN response.
    char auth_response[1024];
    status = recv(sockfd, auth_response, sizeof(auth_response) - 1, 0);
    if (status == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    auth_response[status] = '\0';
    printf("%s\n", auth_response);

    // Send the username and password.
    char *auth_data = "\000username\000password\r\n";
    status = send(sockfd, auth_data, strlen(auth_data), 0);
    if (status == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the authentication response.
    char auth_result[1024];
    status = recv(sockfd, auth_result, sizeof(auth_result) - 1, 0);
    if (status == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    auth_result[status] = '\0';
    printf("%s\n", auth_result);

    // Send the LIST command.
    char *list_command = "LIST \"\"\r\n";
    status = send(sockfd, list_command, strlen(list_command), 0);
    if (status == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the LIST response.
    char list_response[1024];
    status = recv(sockfd, list_response, sizeof(list_response) - 1, 0);
    if (status == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    list_response[status] = '\0';
    printf("%s\n", list_response);

    // Send the QUIT command.
    char *quit_command = "QUIT\r\n";
    status = send(sockfd, quit_command, strlen(quit_command), 0);
    if (status == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}