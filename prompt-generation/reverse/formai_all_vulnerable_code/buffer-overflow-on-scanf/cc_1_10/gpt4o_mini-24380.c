//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_EMAIL_LENGTH 256
#define MAX_BUFFER_SIZE 1024

void send_command(int sockfd, const char *cmd) {
    write(sockfd, cmd, strlen(cmd));
}

void read_response(int sockfd, char *buffer) {
    read(sockfd, buffer, MAX_BUFFER_SIZE);
    printf("%s", buffer);
}

int main() {
    char server_address[100];
    char email_from[MAX_EMAIL_LENGTH];
    char email_to[MAX_EMAIL_LENGTH];
    char subject[MAX_EMAIL_LENGTH];
    char body[MAX_BUFFER_SIZE];
    int port;

    printf("Welcome to the C Email Client!\n");

    printf("Enter SMTP Server Address: ");
    scanf("%s", server_address);
    printf("Enter Port (usually 25 or 587): ");
    scanf("%d", &port);
    
    // Creating socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return -1;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(server_address);

    // Connecting to SMTP Server
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connection to the server failed");
        close(sockfd);
        return -1;
    }

    // Reading server response
    char buffer[MAX_BUFFER_SIZE];
    read_response(sockfd, buffer);

    // HELO Command
    send_command(sockfd, "HELO localhost\r\n");
    read_response(sockfd, buffer);

    // Sending FROM
    printf("Enter your email address: ");
    scanf("%s", email_from);
    char from_cmd[MAX_BUFFER_SIZE];
    snprintf(from_cmd, sizeof(from_cmd), "MAIL FROM:<%s>\r\n", email_from);
    send_command(sockfd, from_cmd);
    read_response(sockfd, buffer);

    // Sending TO
    printf("Enter recipient's email address: ");
    scanf("%s", email_to);
    char to_cmd[MAX_BUFFER_SIZE];
    snprintf(to_cmd, sizeof(to_cmd), "RCPT TO:<%s>\r\n", email_to);
    send_command(sockfd, to_cmd);
    read_response(sockfd, buffer);

    // DATA Command
    send_command(sockfd, "DATA\r\n");
    read_response(sockfd, buffer);

    // Email Subject and Body
    printf("Enter Subject: ");
    scanf(" %[^\n]", subject);
    printf("Enter Body (end with a single dot on a new line):\n");

    // Reading Body
    int index = 0;
    while(1) {
        char line[MAX_BUFFER_SIZE];
        fgets(line, sizeof(line), stdin);
        if (strcmp(line, ".\n") == 0) break;
        snprintf(body + index, sizeof(body) - index, "%s\r\n", line);
        index += strlen(line);
    }

    // Sending Email
    char email_content[MAX_BUFFER_SIZE];
    snprintf(email_content, sizeof(email_content), "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    send_command(sockfd, email_content);
    read_response(sockfd, buffer);

    // QUIT Command
    send_command(sockfd, "QUIT\r\n");
    read_response(sockfd, buffer);

    // Closing socket
    close(sockfd);
    printf("Email sent successfully!\n");
    
    return 0;
}