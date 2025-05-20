//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[BUFFER_SIZE];
    char *message = NULL;
    int n;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set server address
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(110);
    inet_pton(AF_INET, "localhost", &servaddr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Authenticate with server
    char *username = "username";
    char *password = "password";
    char *auth = NULL;
    asprintf(&auth, "LOGIN %s %s\r\n", username, password);
    send(sockfd, auth, strlen(auth), 0);
    free(auth);

    // Receive server response
    memset(buffer, 0, BUFFER_SIZE);
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n <= 0) {
        printf("Error receiving server response\n");
        exit(1);
    }
    printf("Server response: %s", buffer);

    // Send email list command
    char *email_list = "LIST\r\n";
    send(sockfd, email_list, strlen(email_list), 0);

    // Receive email list from server
    memset(buffer, 0, BUFFER_SIZE);
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n <= 0) {
        printf("Error receiving email list\n");
        exit(1);
    }
    printf("Email list: %s", buffer);

    // Close connection
    close(sockfd);

    return 0;
}