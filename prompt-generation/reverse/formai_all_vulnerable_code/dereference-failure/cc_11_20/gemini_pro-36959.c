//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Check if the user has provided enough arguments.
    if (argc < 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    // Get the host and port from the arguments.
    char *host = argv[1];
    int port = atoi(argv[2]);

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Get the host's IP address.
    struct hostent *hostent = gethostbyname(host);
    if (hostent == NULL) {
        perror("gethostbyname");
        return 1;
    }

    // Create a sockaddr_in structure.
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, hostent->h_addr_list[0], hostent->h_length);

    // Connect to the server.
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return 1;
    }

    // Send a login command to the server.
    char *login_command = "USER anonymous\n";
    if (send(sockfd, login_command, strlen(login_command), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the server's response.
    char buffer[BUFFER_SIZE];
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        perror("recv");
        return 1;
    }

    // Check if the login was successful.
    if (strncmp(buffer, "230", 3) != 0) {
        printf("Login failed: %s", buffer);
        return 1;
    }

    // Send a password command to the server.
    char *password_command = "PASS anonymous@example.com\n";
    if (send(sockfd, password_command, strlen(password_command), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the server's response.
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        perror("recv");
        return 1;
    }

    // Check if the password was successful.
    if (strncmp(buffer, "230", 3) != 0) {
        printf("Password failed: %s", buffer);
        return 1;
    }

    // Send a list command to the server.
    char *list_command = "LIST\n";
    if (send(sockfd, list_command, strlen(list_command), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the server's response.
    while (1) {
        if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
            perror("recv");
            return 1;
        }

        // Check if the server has sent the end of the list.
        if (strncmp(buffer, "226", 3) == 0) {
            break;
        }

        // Print the list of files.
        printf("%s", buffer);
    }

    // Close the socket.
    close(sockfd);

    return 0;
}