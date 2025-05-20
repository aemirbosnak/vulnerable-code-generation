//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define SMTP_PORT 587
#define BUFFER_SIZE 1024
#define MAX_EMAIL_LENGTH 256
#define MAX_SUBJECT_LENGTH 128
#define MAX_BODY_LENGTH 1024

void error_exit(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int create_socket(const char *hostname, int port) {
    struct sockaddr_in server_addr;
    struct hostent *host;
    int sockfd;

    if (!(host = gethostbyname(hostname))) {
        fprintf(stderr, "Error: could not resolve hostname %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error_exit("Socket creation failed");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_exit("Connection to the SMTP server failed");
    }

    return sockfd;
}

void send_command(int sockfd, const char *command) {
    char buffer[BUFFER_SIZE];
    int n;

    snprintf(buffer, sizeof(buffer), "%s\r\n", command);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        error_exit("Sending command failed");
    }

    // Read the server response
    n = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (n < 0) {
        error_exit("Receiving response failed");
    }
    buffer[n] = '\0';

    printf("SMTP Response: %s", buffer);
}

void authenticate(int sockfd, const char *username, const char *password) {
    // Sending AUTH LOGIN command
    send_command(sockfd, "EHLO localhost");
    
    // Base64 encoding
    char encoded_user[BUFFER_SIZE];
    char encoded_pass[BUFFER_SIZE];
    sprintf(encoded_user, "%s", username);
    sprintf(encoded_pass, "%s", password);
    
    send_command(sockfd, "AUTH LOGIN");
    send_command(sockfd, encoded_user); // In real code, you would need to base64-encode
    send_command(sockfd, encoded_pass); // In real code, you would need to base64-encode
}

void send_email(const char *smtp_server, const char *username, const char *password, const char *to, const char *subject, const char *body) {
    int sockfd = create_socket(smtp_server, SMTP_PORT);

    authenticate(sockfd, username, password);

    // Formulate SMTP commands
    send_command(sockfd, "MAIL FROM: <sender@example.com>");
    send_command(sockfd, "RCPT TO: <recipient@example.com>");
    send_command(sockfd, "DATA");

    // Sending the email body
    char email[BUFFER_SIZE];
    snprintf(email, sizeof(email),
             "Subject: %s\r\n"
             "To: %s\r\n"
             "\r\n"
             "%s\r\n"
             ".\r\n", subject, to, body);

    send_command(sockfd, email);

    // Quit the connection
    send_command(sockfd, "QUIT");
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 6) {
        fprintf(stderr, "Usage: %s <smtp_server> <username> <password> <to_email> <subject> <body>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *smtp_server = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];
    const char *to_email = argv[4];
    const char *subject = argv[5];
    char *body = argv[6];

    if (strlen(to_email) > MAX_EMAIL_LENGTH) {
        fprintf(stderr, "Error: Email address too long\n");
        return EXIT_FAILURE;
    }

    if (strlen(subject) > MAX_SUBJECT_LENGTH) {
        fprintf(stderr, "Error: Subject too long\n");
        return EXIT_FAILURE;
    }

    if (strlen(body) > MAX_BODY_LENGTH) {
        fprintf(stderr, "Error: Body too long\n");
        return EXIT_FAILURE;
    }

    send_email(smtp_server, username, password, to_email, subject, body);
    return EXIT_SUCCESS;
}