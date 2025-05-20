//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define IMAP_PORT 993 // IMAP over SSL
#define BUFFER_SIZE 2048

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void ssl_init() {
    // Initialize SSL library (pseudo-code).
    // In practice, use OpenSSL library functions here.
}

int connect_to_imap_server(const char *hostname) {
    int sockfd;
    struct sockaddr_in server_addr;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Failed to create socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        error("Invalid address or address not supported");
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }

    return sockfd;
}

void send_command(int sockfd, const char *command) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "%s\r\n", command);
    send(sockfd, buffer, strlen(buffer), 0);
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null terminate buffer
        printf("%s", buffer);
        if (strstr(buffer, "OK")) {
            break; // Break if we see "OK" response.
        }
    }
}

void login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A001 LOGIN %s %s", username, password);
    send_command(sockfd, command);
    read_response(sockfd);
}

void list_mailboxes(int sockfd) {
    send_command(sockfd, "A002 LIST \"\" \"*\"");
    read_response(sockfd);
}

void fetch_mail(int sockfd, const char *mailbox) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A003 SELECT \"%s\"", mailbox);
    send_command(sockfd, command);
    read_response(sockfd);

    snprintf(command, sizeof(command), "A004 FETCH 1:* (ENVELOPE)");
    send_command(sockfd, command);
    read_response(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    ssl_init(); // To be implemented

    int sockfd = connect_to_imap_server(hostname);
    read_response(sockfd);

    login(sockfd, username, password);
    list_mailboxes(sockfd);
    
    char mailbox[100];
    snprintf(mailbox, sizeof(mailbox), "INBOX");
    fetch_mail(sockfd, mailbox);

    close(sockfd);
    return 0;
}