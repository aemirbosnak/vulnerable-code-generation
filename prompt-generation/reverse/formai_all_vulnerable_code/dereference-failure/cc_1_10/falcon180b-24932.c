//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define MAX_LINE_SIZE 512

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char *line = NULL;
    size_t line_size = 0;
    ssize_t bytes_received;
    int status;

    // Connect to server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    inet_pton(AF_INET, "localhost", &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Authenticate with server
    char username[MAX_LINE_SIZE];
    char password[MAX_LINE_SIZE];
    printf("Enter username: ");
    fgets(username, MAX_LINE_SIZE, stdin);
    printf("Enter password: ");
    fgets(password, MAX_LINE_SIZE, stdin);

    char *login_message = "USER ";
    strcat(login_message, username);
    strcat(login_message, "\r\n");
    send(sockfd, login_message, strlen(login_message), 0);

    char *pass_message = "PASS ";
    strcat(pass_message, password);
    strcat(pass_message, "\r\n");
    send(sockfd, pass_message, strlen(pass_message), 0);

    // Retrieve messages from server
    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Received message: %s\n", buffer);
    }

    close(sockfd);

    return 0;
}