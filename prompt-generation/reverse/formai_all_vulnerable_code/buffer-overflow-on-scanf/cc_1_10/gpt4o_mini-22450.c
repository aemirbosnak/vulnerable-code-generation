//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 110 // Default port for POP3
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void pop3_connect(int *sockfd, const char *hostname) {
    struct sockaddr_in server_addr;
    struct hostent *host;

    host = gethostbyname(hostname);
    if (host == NULL) {
        error("Could not resolve hostname");
    }

    *sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sockfd < 0) {
        error("Could not create socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);
    server_addr.sin_port = htons(PORT);

    if (connect(*sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Could not connect to server");
    }

    char buffer[BUFFER_SIZE];
    recv(*sockfd, buffer, BUFFER_SIZE, 0); // Get the server response
    printf("Server: %s", buffer);
}

void pop3_send_command(int sockfd, const char *command) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "%s\r\n", command);
    send(sockfd, buffer, strlen(buffer), 0);

    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Server Response: %s", buffer);
}

void pop3_quit(int sockfd) {
    pop3_send_command(sockfd, "QUIT");
}

void pop3_login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "USER %s", username);
    pop3_send_command(sockfd, command);

    snprintf(command, sizeof(command), "PASS %s", password);
    pop3_send_command(sockfd, command);
}

void pop3_list(int sockfd) {
    pop3_send_command(sockfd, "LIST");
}

void pop3_retrieve(int sockfd, const char *msg_number) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "RETR %s", msg_number);
    pop3_send_command(sockfd, command);
}

void pop3_delete(int sockfd, const char *msg_number) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "DELE %s", msg_number);
    pop3_send_command(sockfd, command);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd;
    pop3_connect(&sockfd, hostname);
    pop3_login(sockfd, username, password);

    pop3_list(sockfd);

    char msg_number[5];
    printf("Enter message number to retrieve: ");
    scanf("%s", msg_number);
    pop3_retrieve(sockfd, msg_number);

    printf("Do you want to delete this message? (y/n): ");
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        pop3_delete(sockfd, msg_number);
    }

    pop3_quit(sockfd);
    close(sockfd);
    return 0;
}