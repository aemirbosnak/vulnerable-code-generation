//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 110
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sockfd, const char *cmd) {
    write(sockfd, cmd, strlen(cmd));
    write(sockfd, "\r\n", 2);
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received = read(sockfd, buffer, sizeof(buffer) - 1);
    if (bytes_received < 0) {
        error("Error reading from socket");
    }
    buffer[bytes_received] = '\0'; // Null-terminate the string
    printf("%s", buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }

    read_response(sockfd);

    char cmd[BUFFER_SIZE];

    // User authentication
    snprintf(cmd, sizeof(cmd), "USER %s", username);
    send_command(sockfd, cmd);
    read_response(sockfd);

    snprintf(cmd, sizeof(cmd), "PASS %s", password);
    send_command(sockfd, cmd);
    read_response(sockfd);

    // List messages
    send_command(sockfd, "LIST");
    read_response(sockfd);

    // Retrieving individual emails
    printf("Enter the number of an email to read: ");
    int email_no;
    scanf("%d", &email_no);
    snprintf(cmd, sizeof(cmd), "RETR %d", email_no);
    send_command(sockfd, cmd);
    read_response(sockfd);

    // Cleanup and disconnect
    send_command(sockfd, "QUIT");
    read_response(sockfd);

    close(sockfd);
    return 0;
}