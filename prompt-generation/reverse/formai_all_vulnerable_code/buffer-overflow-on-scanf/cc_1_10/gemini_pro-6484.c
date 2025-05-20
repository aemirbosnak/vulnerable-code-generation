//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

// The mind-bending part begins here
#define SOCKET_ERROR -1
#define SERVER_PORT 25
#define MAX_LINE 1024

// Function to send email
void send_email(char *smtp_server, char *sender, char *recipient, char *subject, char *body) {
    // Establish a connection to the SMTP server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == SOCKET_ERROR) {
        perror("Error creating socket");
        exit(1);
    }
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(smtp_server);
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        perror("Error connecting to server");
        exit(1);
    }

    // Read the greeting from the server
    char greeting[MAX_LINE];
    int bytes_received = recv(sockfd, greeting, MAX_LINE, 0);
    if (bytes_received == SOCKET_ERROR) {
        perror("Error receiving greeting");
        exit(1);
    }
    printf("%s", greeting);

    // Send the HELO command
    char helo_command[MAX_LINE];
    sprintf(helo_command, "HELO %s\r\n", "localhost");
    if (send(sockfd, helo_command, strlen(helo_command), 0) == SOCKET_ERROR) {
        perror("Error sending HELO command");
        exit(1);
    }
    char helo_response[MAX_LINE];
    bytes_received = recv(sockfd, helo_response, MAX_LINE, 0);
    if (bytes_received == SOCKET_ERROR) {
        perror("Error receiving HELO response");
        exit(1);
    }
    printf("%s", helo_response);

    // Send the MAIL FROM command
    char mail_from_command[MAX_LINE];
    sprintf(mail_from_command, "MAIL FROM: <%s>\r\n", sender);
    if (send(sockfd, mail_from_command, strlen(mail_from_command), 0) == SOCKET_ERROR) {
        perror("Error sending MAIL FROM command");
        exit(1);
    }
    char mail_from_response[MAX_LINE];
    bytes_received = recv(sockfd, mail_from_response, MAX_LINE, 0);
    if (bytes_received == SOCKET_ERROR) {
        perror("Error receiving MAIL FROM response");
        exit(1);
    }
    printf("%s", mail_from_response);

    // Send the RCPT TO command
    char rcpt_to_command[MAX_LINE];
    sprintf(rcpt_to_command, "RCPT TO: <%s>\r\n", recipient);
    if (send(sockfd, rcpt_to_command, strlen(rcpt_to_command), 0) == SOCKET_ERROR) {
        perror("Error sending RCPT TO command");
        exit(1);
    }
    char rcpt_to_response[MAX_LINE];
    bytes_received = recv(sockfd, rcpt_to_response, MAX_LINE, 0);
    if (bytes_received == SOCKET_ERROR) {
        perror("Error receiving RCPT TO response");
        exit(1);
    }
    printf("%s", rcpt_to_response);

    // Send the DATA command
    char data_command[MAX_LINE];
    sprintf(data_command, "DATA\r\n");
    if (send(sockfd, data_command, strlen(data_command), 0) == SOCKET_ERROR) {
        perror("Error sending DATA command");
        exit(1);
    }
    char data_response[MAX_LINE];
    bytes_received = recv(sockfd, data_response, MAX_LINE, 0);
    if (bytes_received == SOCKET_ERROR) {
        perror("Error receiving DATA response");
        exit(1);
    }
    printf("%s", data_response);

    // Send the email body
    char email_body[MAX_LINE];
    sprintf(email_body, "From: %s\nTo: %s\nSubject: %s\n\n%s\r\n", sender, recipient, subject, body);
    if (send(sockfd, email_body, strlen(email_body), 0) == SOCKET_ERROR) {
        perror("Error sending email body");
        exit(1);
    }

    // Send the period to indicate the end of the email body
    char period[MAX_LINE];
    sprintf(period, ".\r\n");
    if (send(sockfd, period, strlen(period), 0) == SOCKET_ERROR) {
        perror("Error sending period");
        exit(1);
    }

    // Read the response from the server
    char response[MAX_LINE];
    bytes_received = recv(sockfd, response, MAX_LINE, 0);
    if (bytes_received == SOCKET_ERROR) {
        perror("Error receiving response");
        exit(1);
    }
    printf("%s", response);

    // Close the connection to the server
    close(sockfd);
}

// Function to get the SMTP server address from the user
char *get_smtp_server() {
    char *smtp_server = malloc(MAX_LINE);
    printf("Enter the SMTP server address: ");
    scanf("%s", smtp_server);
    return smtp_server;
}

// Function to get the sender's email address from the user
char *get_sender() {
    char *sender = malloc(MAX_LINE);
    printf("Enter your email address: ");
    scanf("%s", sender);
    return sender;
}

// Function to get the recipient's email address from the user
char *get_recipient() {
    char *recipient = malloc(MAX_LINE);
    printf("Enter the recipient's email address: ");
    scanf("%s", recipient);
    return recipient;
}

// Function to get the subject of the email from the user
char *get_subject() {
    char *subject = malloc(MAX_LINE);
    printf("Enter the subject of the email: ");
    scanf("%s", subject);
    return subject;
}

// Function to get the body of the email from the user
char *get_body() {
    char *body = malloc(MAX_LINE);
    printf("Enter the body of the email: ");
    scanf("%s", body);
    return body;
}

// Main function
int main() {
    // Get the SMTP server address from the user
    char *smtp_server = get_smtp_server();

    // Get the sender's email address from the user
    char *sender = get_sender();

    // Get the recipient's email address from the user
    char *recipient = get_recipient();

    // Get the subject of the email from the user
    char *subject = get_subject();

    // Get the body of the email from the user
    char *body = get_body();

    // Send the email
    send_email(smtp_server, sender, recipient, subject, body);

    // Free the allocated memory
    free(smtp_server);
    free(sender);
    free(recipient);
    free(subject);
    free(body);

    return 0;
}