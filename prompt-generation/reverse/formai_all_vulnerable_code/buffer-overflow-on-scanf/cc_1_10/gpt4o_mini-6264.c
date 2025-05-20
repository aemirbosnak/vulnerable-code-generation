//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 110 // Standard port for POP3
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int connect_to_server(const char *server_ip) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        close(sockfd);
        error("ERROR connecting to server");
    }

    return sockfd;
}

void send_command(int sockfd, const char *command) {
    write(sockfd, command, strlen(command));
    write(sockfd, "\r\n", 2);
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n;

    memset(buffer, 0, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);
}

void list_emails(int sockfd) {
    send_command(sockfd, "LIST");
    read_response(sockfd);
}

void get_email(int sockfd, int email_number) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "RETR %d", email_number);
    send_command(sockfd, command);
    read_response(sockfd);
}

void delete_email(int sockfd, int email_number) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "DELE %d", email_number);
    send_command(sockfd, command);
    read_response(sockfd);
}

void quit_session(int sockfd) {
    send_command(sockfd, "QUIT");
    read_response(sockfd);
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <server_ip> <username>\n", argv[0]);
        return 1;
    }

    const char *server_ip = argv[1];
    const char *username = argv[2];
    char command[BUFFER_SIZE];
    int sockfd = connect_to_server(server_ip);
    read_response(sockfd); // Read server greeting

    // Send USER command
    snprintf(command, sizeof(command), "USER %s", username);
    send_command(sockfd, command);
    read_response(sockfd);

    // Send PASS command
    printf("Enter password: ");
    char password[BUFFER_SIZE];
    scanf("%s", password);
    snprintf(command, sizeof(command), "PASS %s", password);
    send_command(sockfd, command);
    read_response(sockfd);

    // List emails
    list_emails(sockfd);

    // Get the first email as an example
    printf("Retrieving email 1:\n");
    get_email(sockfd, 1);

    // Optionally delete the first email
    // printf("Deleting email 1:\n");
    // delete_email(sockfd, 1);

    // End the session
    quit_session(sockfd);
    return 0;
}