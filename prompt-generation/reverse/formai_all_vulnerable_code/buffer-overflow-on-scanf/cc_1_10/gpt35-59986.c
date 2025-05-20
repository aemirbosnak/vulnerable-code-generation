//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Sherlock Holmes
// The Case of the Mysterious Emailer
// A SMTP Client Program
// Written by Detective Sherlock Holmes

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define SERVER_ADDRESS "smtp.example.com" // The SMTP Server Address
#define SERVER_PORT 25 // The SMTP Server Port

void send_mail(char* to, char* from, char* subject, char* message) {
    // Open a TCP socket to the SMTP server
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("Socket creation failed");
        return;
    }

    // Connect to the SMTP server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);

    if (connect(socket_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
        perror("Connection failed");
        close(socket_fd);
        return;
    }

    char buffer[1024];

    // Wait for a response from the SMTP server
    if (recv(socket_fd, buffer, sizeof(buffer), 0) == -1) {
        perror("Error receiving response from server");
        close(socket_fd);
        return;
    }

    // Send the "HELO" command
    sprintf(buffer, "HELO %s\r\n", SERVER_ADDRESS);
    if (send(socket_fd, buffer, strlen(buffer), 0) == -1) {
        perror("Error sending HELO command");
        close(socket_fd);
        return;
    }

    // Wait for a response from the SMTP server
    if (recv(socket_fd, buffer, sizeof(buffer), 0) == -1) {
        perror("Error receiving response from server");
        close(socket_fd);
        return;
    }

    // Send the "MAIL FROM" command
    sprintf(buffer, "MAIL FROM:<%s>\r\n", from);
    if (send(socket_fd, buffer, strlen(buffer), 0) == -1) {
        perror("Error sending MAIL FROM command");
        close(socket_fd);
        return;
    }

    // Wait for a response from the SMTP server
    if (recv(socket_fd, buffer, sizeof(buffer), 0) == -1) {
        perror("Error receiving response from server");
        close(socket_fd);
        return;
    }

    // Send the "RCPT TO" command
    sprintf(buffer, "RCPT TO:<%s>\r\n", to);
    if (send(socket_fd, buffer, strlen(buffer), 0) == -1) {
        perror("Error sending RCPT TO command");
        close(socket_fd);
        return;
    }

    // Wait for a response from the SMTP server
    if (recv(socket_fd, buffer, sizeof(buffer), 0) == -1) {
        perror("Error receiving response from server");
        close(socket_fd);
        return;
    }

    // Send the "DATA" command
    sprintf(buffer, "DATA\r\n");
    if (send(socket_fd, buffer, strlen(buffer), 0) == -1) {
        perror("Error sending DATA command");
        close(socket_fd);
        return;
    }

    // Wait for a response from the SMTP server
    if (recv(socket_fd, buffer, sizeof(buffer), 0) == -1) {
        perror("Error receiving response from server");
        close(socket_fd);
        return;
    }

    // Send the email headers and message body
    sprintf(buffer, "To: <%s>\r\n", to);
    if (send(socket_fd, buffer, strlen(buffer), 0) == -1) {
        perror("Error sending email headers");
        close(socket_fd);
        return;
    }
    sprintf(buffer, "From: <%s>\r\n", from);
    if (send(socket_fd, buffer, strlen(buffer), 0) == -1) {
        perror("Error sending email headers");
        close(socket_fd);
        return;
    }
    sprintf(buffer, "Subject: %s\r\n", subject);
    if (send(socket_fd, buffer, strlen(buffer), 0) == -1) {
        perror("Error sending email headers");
        close(socket_fd);
        return;
    }
    sprintf(buffer, "\r\n%s\r\n", message);
    if (send(socket_fd, buffer, strlen(buffer), 0) == -1) {
        perror("Error sending email message");
        close(socket_fd);
        return;
    }

    // Send the "QUIT" command
    sprintf(buffer, "QUIT\r\n");
    if (send(socket_fd, buffer, strlen(buffer), 0) == -1) {
        perror("Error sending QUIT command");
        close(socket_fd);
        return;
    }

    close(socket_fd);
    printf("Email successfully sent to %s\n", to);
}

int main() {
    printf("Welcome to the Mysterious Emailer!\n");

    // Gather email information from the user
    char to[1024], from[1024], subject[1024], message[1024];

    printf("Recipient: ");
    scanf("%s", to);
    printf("Sender: ");
    scanf("%s", from);
    printf("Subject: ");
    scanf("%s", subject);
    printf("Message: ");
    scanf("%s", message);

    // Send the email
    send_mail(to, from, subject, message);

    printf("Thank you for using the Mysterious Emailer!\n");

    return 0;
}