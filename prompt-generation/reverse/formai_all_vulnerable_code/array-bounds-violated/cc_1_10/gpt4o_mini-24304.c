//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

void handle_error(const char *msg) {
    perror(msg);
    exit(1);
}

void write_to_socket(int sockfd, const char *msg) {
    if (send(sockfd, msg, strlen(msg), 0) == -1) {
        handle_error("send");
    }
}

void read_from_socket(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_recvd = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_recvd < 0) {
        handle_error("recv");
    }
    buffer[bytes_recvd] = '\0'; // Null terminate the string
    printf("%s", buffer);
}

void smtp_client(const char *server, const char *from, const char *to, const char *subject, const char *body) {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) handle_error("socket");

    // Define server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr(server);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("connect");
    }

    read_from_socket(sockfd); // Read greeting

    // HELO command
    write_to_socket(sockfd, "HELO test.com\r\n");
    read_from_socket(sockfd);

    // MAIL FROM command
    char mail_from_cmd[BUFFER_SIZE];
    snprintf(mail_from_cmd, sizeof(mail_from_cmd), "MAIL FROM: <%s>\r\n", from);
    write_to_socket(sockfd, mail_from_cmd);
    read_from_socket(sockfd);

    // RCPT TO command
    char rcpt_to_cmd[BUFFER_SIZE];
    snprintf(rcpt_to_cmd, sizeof(rcpt_to_cmd), "RCPT TO: <%s>\r\n", to);
    write_to_socket(sockfd, rcpt_to_cmd);
    read_from_socket(sockfd);

    // DATA command
    write_to_socket(sockfd, "DATA\r\n");
    read_from_socket(sockfd);

    // Email headers
    char email[BUFFER_SIZE];
    snprintf(email, sizeof(email),
             "From: %s\r\n"
             "To: %s\r\n"
             "Subject: %s\r\n"
             "\r\n"
             "%s\r\n"
             ".\r\n", from, to, subject, body);
    
    write_to_socket(sockfd, email);
    read_from_socket(sockfd);

    // QUIT command
    write_to_socket(sockfd, "QUIT\r\n");
    read_from_socket(sockfd);

    // Close socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 6) {
        fprintf(stderr, "Usage: %s <SMTP server> <from> <to> <subject> <body>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *smtp_server = argv[1];
    const char *from_email = argv[2];
    const char *to_email = argv[3];
    const char *email_subject = argv[4];
    const char *email_body = argv[5];

    smtp_client(smtp_server, from_email, to_email, email_subject, email_body);

    return EXIT_SUCCESS;
}