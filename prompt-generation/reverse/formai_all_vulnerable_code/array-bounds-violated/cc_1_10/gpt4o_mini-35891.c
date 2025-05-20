//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

#define PORT 993
#define SERVER "imap.cybernetix.com"
#define BUFFER_SIZE 1024
#define USERNAME "neon_rider"
#define PASSWORD "cyberpunk_secret"

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *command) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "%s\r\n", command);
    
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        error("Send Command Failed");
    }
}

void recv_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n;

    while ((n = recv(sockfd, buffer, sizeof(buffer)-1, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, "OK") != NULL) break; // end on OK response
    }
    if (n < 0) {
        error("Receive Error");
    }
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Could not open socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, SERVER, &server_addr.sin_addr) <= 0) {
        error("Invalid address / Address not supported");
    }

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }

    // Sending Login Command
    char login_command[BUFFER_SIZE];
    snprintf(login_command, sizeof(login_command), "A001 LOGIN \"%s\" \"%s\"", USERNAME, PASSWORD);
    send_command(sockfd, login_command);
    recv_response(sockfd);

    // Sending Select Mailbox Command
    send_command(sockfd, "A002 SELECT INBOX");
    recv_response(sockfd);

    // Sending Fetch Command
    send_command(sockfd, "A003 FETCH 1 BODY[]");
    recv_response(sockfd);

    // Sending Logout Command
    send_command(sockfd, "A004 LOGOUT");
    recv_response(sockfd);

    printf("\nCaught in the web of data, Neon Rider has logged out.\n");

    close(sockfd);
    return 0;
}