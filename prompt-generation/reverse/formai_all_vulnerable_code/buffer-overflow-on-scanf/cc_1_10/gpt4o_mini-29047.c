//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER "smtp.example.com" // Change to your SMTP server
#define PORT 25 // Common SMTP port
#define MAX_PAYLOAD 1024

// Function to send the command and receive the response
void send_command(int sock, const char *cmd) {
    char buffer[MAX_PAYLOAD];
    send(sock, cmd, strlen(cmd), 0);
    send(sock, "\r\n", 2, 0); // SMTP commands are terminated with CRLF
    recv(sock, buffer, sizeof(buffer) - 1, 0);
    printf("%s", buffer);
}

// Function to connect to the SMTP server
int connect_to_smtp_server() {
    struct sockaddr_in server_address;
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr("93.184.216.34"); // Example IP (replace with actual)

    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection to SMTP server failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    return sock;
}

// Function to authenticate user
void authenticate_user(int sock, const char *username, const char *password) {
    // Base64 encode username and password first, typically you'd use libraries for this
    // For this example, plain text is used for simplicity, which is not secure.
    char buf[MAX_PAYLOAD];
    snprintf(buf, sizeof(buf), "EHLO localhost");
    send_command(sock, buf);
    
    snprintf(buf, sizeof(buf), "AUTH LOGIN");
    send_command(sock, buf);
    
    // Simulated encoding
    snprintf(buf, sizeof(buf), "%s", username); // You must encode this!
    send_command(sock, buf);
    
    snprintf(buf, sizeof(buf), "%s", password); // You must encode this!
    send_command(sock, buf);
}

// Function to send an email
void send_email(int sock, const char *from, const char *to, const char *subject, const char *body) {
    char buf[MAX_PAYLOAD];
    
    snprintf(buf, sizeof(buf), "MAIL FROM:<%s>", from);
    send_command(sock, buf);
    
    snprintf(buf, sizeof(buf), "RCPT TO:<%s>", to);
    send_command(sock, buf);
    
    send_command(sock, "DATA");
    
    snprintf(buf, sizeof(buf), "Subject: %s\r\n\r\n%s\r\n.", subject, body);
    send(sock, buf, strlen(buf), 0);
    
    char response[MAX_PAYLOAD];
    recv(sock, response, sizeof(response) - 1, 0);
    printf("Response: %s\n", response);
}

// Function to terminate session
void quit_smtp_session(int sock) {
    send_command(sock, "QUIT");
    close(sock);
}

int main() {
    char from[50], to[50], subject[100], body[500];
    char username[50], password[50];

    // Input SMTP credentials and email details
    printf("Enter your email: ");
    scanf("%s", from);
    
    printf("Enter recipient email: ");
    scanf("%s", to);
    
    printf("Enter subject: ");
    getchar(); // Clear the newline from the input buffer
    fgets(subject, sizeof(subject), stdin);
    subject[strcspn(subject, "\n")] = 0; // Remove trailing newline
    
    printf("Enter body of the email: ");
    fgets(body, sizeof(body), stdin);
    body[strcspn(body, "\n")] = 0; // Remove trailing newline
    
    printf("Enter your SMTP username: ");
    scanf("%s", username);
    
    printf("Enter your SMTP password: ");
    scanf("%s", password);
    
    // Connect to SMTP server
    int sock = connect_to_smtp_server();
    
    // Authenticate user
    authenticate_user(sock, username, password);
    
    // Send email
    send_email(sock, from, to, subject, body);
    
    // Terminate session
    quit_smtp_session(sock);
    
    printf("Email sent successfully!\n");
    return 0;
}