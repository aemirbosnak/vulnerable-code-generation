//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

// IMAP Constants
#define IMAP_PORT 143
#define BUFFER_SIZE 4096

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sockfd, const char *command) {
    if (send(sockfd, command, strlen(command), 0) < 0) {
        error("Send failed");
    }
    send(sockfd, "\r\n", 2, 0); // IMAP commands require CRLF
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the string 
        printf("%s", buffer);
        if (strstr(buffer, "OK") || strstr(buffer, "NO") || strstr(buffer, "BAD")) {
            break; // We can exit on server acknowledgment.
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IMAP server> <email>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *server = argv[1];
    const char *email = argv[2];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(IMAP_PORT);
    if (inet_pton(AF_INET, server, &serv_addr.sin_addr) <= 0) {
        close(sockfd);
        error("Invalid address / Address not supported");
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        close(sockfd);
        error("Connection failed");
    }

    // Receive IMAP greeting
    receive_response(sockfd);

    // Authenticate (using plain auth in this simplified example)
    char command[BUFFER_SIZE];
    sprintf(command, "a001 LOGIN %s password", email); // Replace "password" with actual password.
    send_command(sockfd, command);
    receive_response(sockfd);

    // List mailboxes
    send_command(sockfd, "a002 LIST \"\" \"*\"");
    receive_response(sockfd);

    // Select INBOX
    send_command(sockfd, "a003 SELECT INBOX");
    receive_response(sockfd);

    // Fetch message count
    send_command(sockfd, "a004 COUNT");
    receive_response(sockfd);

    // Fetch the first message
    send_command(sockfd, "a005 FETCH 1 BODY[]");
    receive_response(sockfd);

    // Logout
    send_command(sockfd, "a006 LOGOUT");
    receive_response(sockfd);

    close(sockfd);
    return EXIT_SUCCESS;
}