//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: Claude Shannon
#include <stdio.h> // For printf() and stdin
#include <stdlib.h> // For exit() and malloc()
#include <string.h> // For strcpy() and strlen()
#include <sys/socket.h> // For socket(), connect(), send(), and recv()
#include <netinet/in.h> // For sockaddr_in and htonl()
#include <arpa/inet.h> // For inet_addr()

// Function to send an email using the SMTP protocol
int send_email(char *sender, char *recipient, char *subject, char *body) {
    // Create a socket for the SMTP server
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return -1;
    }

    // Connect to the SMTP server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(25);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return -1;
    }

    // Read the welcome message from the SMTP server
    char buffer[1024];
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Send the HELO command to the SMTP server
    strcpy(buffer, "HELO example.com\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Send the MAIL FROM command to the SMTP server
    strcpy(buffer, "MAIL FROM: <");
    strcat(buffer, sender);
    strcat(buffer, ">\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Send the RCPT TO command to the SMTP server
    strcpy(buffer, "RCPT TO: <");
    strcat(buffer, recipient);
    strcat(buffer, ">\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Send the DATA command to the SMTP server
    strcpy(buffer, "DATA\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Send the email body to the SMTP server
    strcpy(buffer, "From: ");
    strcat(buffer, sender);
    strcat(buffer, "\r\n");
    send(sock, buffer, strlen(buffer), 0);
    strcpy(buffer, "To: ");
    strcat(buffer, recipient);
    strcat(buffer, "\r\n");
    send(sock, buffer, strlen(buffer), 0);
    strcpy(buffer, "Subject: ");
    strcat(buffer, subject);
    strcat(buffer, "\r\n");
    send(sock, buffer, strlen(buffer), 0);
    strcpy(buffer, "\r\n");
    send(sock, buffer, strlen(buffer), 0);
    send(sock, body, strlen(body), 0);
    strcpy(buffer, "\r\n.\r\n");
    send(sock, buffer, strlen(buffer), 0);

    // Send the QUIT command to the SMTP server
    strcpy(buffer, "QUIT\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Close the socket
    close(sock);

    return 0;
}

// Main function
int main() {
    // Get the sender's email address from the user
    char sender[256];
    printf("Enter your email address: ");
    scanf("%s", sender);

    // Get the recipient's email address from the user
    char recipient[256];
    printf("Enter the recipient's email address: ");
    scanf("%s", recipient);

    // Get the subject of the email from the user
    char subject[256];
    printf("Enter the subject of the email: ");
    scanf("%s", subject);

    // Get the body of the email from the user
    char body[1024];
    printf("Enter the body of the email: ");
    scanf("%s", body);

    // Send the email using the SMTP protocol
    int result = send_email(sender, recipient, subject, body);
    if (result == -1) {
        printf("Error sending email.\n");
        return -1;
    }

    printf("Email sent successfully.\n");

    return 0;
}