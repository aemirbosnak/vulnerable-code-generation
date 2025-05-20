//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 1024
#define DEFAULT_PORT 993

void error_exit(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void connect_to_imap(const char *server_ip, int port, int *sockfd) {
    struct sockaddr_in server_addr;

    *sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sockfd < 0) {
        error_exit("Socket creation failed");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(*sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        close(*sockfd);
        error_exit("Connection to server failed");
    }

    printf("Connected to IMAP server: %s:%d\n", server_ip, port);
}

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    send(sockfd, "\r\n", 2, 0);
}

void receive_response(int sockfd) {
    char buffer[MAX_BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, "OK") || strstr(buffer, "NO") || strstr(buffer, "BAD")) {
            break;
        }
    }

    if (bytes_received < 0) {
        error_exit("Failed to receive response");
    }
}

void login(int sockfd, const char *username, const char *password) {
    char command[MAX_BUFFER_SIZE];

    snprintf(command, sizeof(command), "A001 LOGIN %s %s", username, password);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void list_mailboxes(int sockfd) {
    send_command(sockfd, "A002 LIST \"\" \"*\"");
    receive_response(sockfd);
}

void fetch_mail(int sockfd, const char *mailbox) {
    char command[MAX_BUFFER_SIZE];

    snprintf(command, sizeof(command), "A003 SELECT %s", mailbox);
    send_command(sockfd, command);
    receive_response(sockfd);

    send_command(sockfd, "A004 FETCH 1:* BODY[]");
    receive_response(sockfd);
}

void logout(int sockfd) {
    send_command(sockfd, "A005 LOGOUT");
    receive_response(sockfd);
    close(sockfd);
    printf("Disconnected from IMAP server\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IMAP_SERVER_IP> <USERNAME> <PASSWORD>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *server_ip = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];
    int sockfd;

    connect_to_imap(server_ip, DEFAULT_PORT, &sockfd);
    login(sockfd, username, password);
    list_mailboxes(sockfd);
    fetch_mail(sockfd, "INBOX");
    logout(sockfd);

    return 0;
}