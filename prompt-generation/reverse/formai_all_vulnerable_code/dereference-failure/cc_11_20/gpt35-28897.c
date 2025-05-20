//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s smtp_server recipient_email\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *smtp_server = argv[1];
    char *recipient_email = argv[2];

    /* Get MX records for recipient's email */
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_CANONNAME | AI_NUMERICSERV;
    int getaddrinfo_status = getaddrinfo(recipient_email, "smtp", &hints, &res);
    if (getaddrinfo_status != 0) {
        fprintf(stderr, "Failed to get MX records for %s: %s\n", recipient_email, gai_strerror(getaddrinfo_status));
        exit(EXIT_FAILURE);
    }
    char mx_host[BUF_SIZE];
    strcpy(mx_host, res->ai_canonname);
    freeaddrinfo(res);

    /* Create socket and connect to SMTP server */
    int smtp_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (smtp_socket == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }
    struct hostent *mx_info = gethostbyname(mx_host);
    if (mx_info == NULL) {
        fprintf(stderr, "Failed to get host info for %s\n", mx_host);
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(25); // 25 is the default SMTP port
    memcpy(&server_addr.sin_addr.s_addr, mx_info->h_addr_list[0], mx_info->h_length);
    if (connect(smtp_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Failed to connect");
        exit(EXIT_FAILURE);
    }

    /* Send SMTP HELO message */
    char helo_message[BUF_SIZE];
    snprintf(helo_message, BUF_SIZE, "HELO %s\r\n", smtp_server);
    if (send(smtp_socket, helo_message, strlen(helo_message), 0) == -1) {
        perror("Failed to send HELO message");
        exit(EXIT_FAILURE);
    }
    char response[BUF_SIZE];
    if (recv(smtp_socket, response, BUF_SIZE, 0) == -1) {
        perror("Failed to receive response for HELO message");
        exit(EXIT_FAILURE);
    }
    printf("HELO response: %s", response);

    /* Send SMTP MAIL FROM message */
    char mail_from_message[BUF_SIZE];
    snprintf(mail_from_message, BUF_SIZE, "MAIL FROM:<%s>\r\n", "sender@example.com");
    if (send(smtp_socket, mail_from_message, strlen(mail_from_message), 0) == -1) {
        perror("Failed to send MAIL FROM message");
        exit(EXIT_FAILURE);
    }
    if (recv(smtp_socket, response, BUF_SIZE, 0) == -1) {
        perror("Failed to receive response for MAIL FROM message");
        exit(EXIT_FAILURE);
    }
    printf("MAIL FROM response: %s", response);

    /* Send SMTP RCPT TO message */
    char rcpt_to_message[BUF_SIZE];
    snprintf(rcpt_to_message, BUF_SIZE, "RCPT TO:<%s>\r\n", recipient_email);
    if (send(smtp_socket, rcpt_to_message, strlen(rcpt_to_message), 0) == -1) {
        perror("Failed to send RCPT TO message");
        exit(EXIT_FAILURE);
    }
    if (recv(smtp_socket, response, BUF_SIZE, 0) == -1) {
        perror("Failed to receive response for RCPT TO message");
        exit(EXIT_FAILURE);
    }
    printf("RCPT TO response: %s", response);

    /* Send SMTP DATA message */
    char data_message[BUF_SIZE];
    snprintf(data_message, BUF_SIZE, "DATA\r\n");
    if (send(smtp_socket, data_message, strlen(data_message), 0) == -1) {
        perror("Failed to send DATA message");
        exit(EXIT_FAILURE);
    }
    if (recv(smtp_socket, response, BUF_SIZE, 0) == -1) {
        perror("Failed to receive response for DATA message");
        exit(EXIT_FAILURE);
    }
    printf("DATA response: %s", response);

    /* Send email body */
    char email_body[BUF_SIZE];
    printf("Enter email body (press '.' on a new line to end):\n");
    do {
        fgets(email_body, BUF_SIZE, stdin);
        if (send(smtp_socket, email_body, strlen(email_body), 0) == -1) {
            perror("Failed to send email body");
            exit(EXIT_FAILURE);
        }
    } while (strcmp(email_body, ".\n") != 0);

    /* Send SMTP QUIT message */
    char quit_message[BUF_SIZE];
    snprintf(quit_message, BUF_SIZE, "QUIT\r\n");
    if (send(smtp_socket, quit_message, strlen(quit_message), 0) == -1) {
        perror("Failed to send QUIT message");
        exit(EXIT_FAILURE);
    }
    if (recv(smtp_socket, response, BUF_SIZE, 0) == -1) {
        perror("Failed to receive response for QUIT message");
        exit(EXIT_FAILURE);
    }
    printf("QUIT response: %s", response);

    /* Close socket and exit */
    close(smtp_socket);
    exit(EXIT_SUCCESS);
}