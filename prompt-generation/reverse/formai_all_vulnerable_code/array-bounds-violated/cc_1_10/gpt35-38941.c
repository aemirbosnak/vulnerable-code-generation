//FormAI DATASET v1.0 Category: Email Client ; Style: high level of detail
/* C Email Client Example */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_EMAIL_SIZE 5000
#define MAX_SUBJECT_SIZE 256
#define MAX_USERNAME_SIZE 64
#define MAX_PASSWORD_SIZE 64
#define MAX_SERVER_SIZE 64
#define MAX_PORT_SIZE 6

// Function to validate email address
int is_valid_email(char *email) {
    int i, len;
    int at = 0, dot = 0;
    char ch;

    len = strlen(email);

    for (i = 0; i < len; i++) {
        ch = email[i];

        if (!isalnum(ch) && ch != '@' && ch != '.' && ch != '-' && ch != '_') {
            return 0;
        } else if (ch == '@') {
            at++;
        } else if (ch == '.') {
            dot++;
        }
    }

    if (at != 1 || dot < 1) {
        return 0;
    }

    return 1;
}

// Function to validate port number
int is_valid_port(char *port_str) {
    int i, len;
    char ch;

    len = strlen(port_str);

    if (len > 5) {
        return 0;
    }

    for (i = 0; i < len; i++) {
        ch = port_str[i];

        if (!isdigit(ch)) {
            return 0;
        }
    }

    return 1;
}

// Function to send email
int send_email(char *from, char *to, char *subject, char *message, char *username, char *password, char *server, int port) {
    int sock, i;
    char buffer[MAX_EMAIL_SIZE];
    struct sockaddr_in server_addr;

    // Initialize socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        perror("Error opening socket");
        return -1;
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_aton(server, &server_addr.sin_addr);

    // Connect to server
    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        close(sock);
        return -1;
    }

    // Send initial message
    sprintf(buffer, "EHLO %s\r\n", server);
    send(sock, buffer, strlen(buffer), 0);

    // Receive initial response
    recv(sock, buffer, MAX_EMAIL_SIZE, 0);

    // Send login information
    sprintf(buffer, "AUTH LOGIN\r\n");
    send(sock, buffer, strlen(buffer), 0);

    // Receive login request
    recv(sock, buffer, MAX_EMAIL_SIZE, 0);

    // Send username
    sprintf(buffer, "%s\r\n", username);
    send(sock, buffer, strlen(buffer), 0);

    // Receive response to username
    recv(sock, buffer, MAX_EMAIL_SIZE, 0);

    // Send password
    sprintf(buffer, "%s\r\n", password);
    send(sock, buffer, strlen(buffer), 0);

    // Receive response to password
    recv(sock, buffer, MAX_EMAIL_SIZE, 0);

    // Send email contents
    sprintf(buffer, "MAIL FROM:<%s>\r\n", from);
    send(sock, buffer, strlen(buffer), 0);

    recv(sock, buffer, MAX_EMAIL_SIZE, 0);

    sprintf(buffer, "RCPT TO:<%s>\r\n", to);
    send(sock, buffer, strlen(buffer), 0);

    recv(sock, buffer, MAX_EMAIL_SIZE, 0);

    sprintf(buffer, "DATA\r\n");
    send(sock, buffer, strlen(buffer), 0);

    recv(sock, buffer, MAX_EMAIL_SIZE, 0);

    sprintf(buffer, "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, message);
    send(sock, buffer, strlen(buffer), 0);

    // Receive response to email
    recv(sock, buffer, MAX_EMAIL_SIZE, 0);

    // Disconnect from server
    sprintf(buffer, "QUIT\r\n");
    send(sock, buffer, strlen(buffer), 0);

    close(sock);

    return 0;
}

int main() {
    char from[MAX_EMAIL_SIZE], to[MAX_EMAIL_SIZE], subject[MAX_SUBJECT_SIZE], message[MAX_EMAIL_SIZE];
    char username[MAX_USERNAME_SIZE], password[MAX_PASSWORD_SIZE], server[MAX_SERVER_SIZE], port_str[MAX_PORT_SIZE];
    int port;

    printf("Enter sender email address:\n");
    fgets(from, MAX_EMAIL_SIZE, stdin);
    from[strlen(from) - 1] = '\0';

    if (!is_valid_email(from)) {
        printf("Invalid email address.\n");
        return -1;
    }

    printf("Enter recipient email address:\n");
    fgets(to, MAX_EMAIL_SIZE, stdin);
    to[strlen(to) - 1] = '\0';

    if (!is_valid_email(to)) {
        printf("Invalid email address.\n");
        return -1;
    }

    printf("Enter subject:\n");
    fgets(subject, MAX_SUBJECT_SIZE, stdin);
    subject[strlen(subject) - 1] = '\0';

    printf("Enter message:\n");
    fgets(message, MAX_EMAIL_SIZE, stdin);
    message[strlen(message) - 1] = '\0';

    printf("Enter username:\n");
    fgets(username, MAX_USERNAME_SIZE, stdin);
    username[strlen(username) - 1] = '\0';

    printf("Enter password:\n");
    fgets(password, MAX_PASSWORD_SIZE, stdin);
    password[strlen(password) - 1] = '\0';

    printf("Enter server:\n");
    fgets(server, MAX_SERVER_SIZE, stdin);
    server[strlen(server) - 1] = '\0';

    printf("Enter port:\n");
    fgets(port_str, MAX_PORT_SIZE, stdin);
    port_str[strlen(port_str) - 1] = '\0';

    if (!is_valid_port(port_str)) {
        printf("Invalid port number.\n");
        return -1;
    }

    port = atoi(port_str);

    // Send email
    if (send_email(from, to, subject, message, username, password, server, port) != 0) {
        printf("Error sending email.\n");
        return -1;
    }

    printf("Email sent successfully.\n");

    return 0;
}