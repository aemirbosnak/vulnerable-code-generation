//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define PORT 587

void respond(int socket, const char *message) {
    send(socket, message, strlen(message), 0);
}

int receive_response(int socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0';
    printf("Server: %s", buffer);
    return atoi(buffer);
}

int main() {
    char server_address[100], from_email[100], to_email[100], subject[100], message_body[500];
    int socket_desc;
    struct sockaddr_in server;
    
    printf("Welcome to the Simple C Email Client!\n");
    printf("Enter SMTP Server Address (e.g., smtp.example.com): ");
    scanf("%s", server_address);

    // Creating socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        perror("Could not create socket");
        return 1;
    }

    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // for demo; replace with server_address if needed
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    // Connect to the SMTP server
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connect failed");
        return 1;
    }

    printf("Connected to the SMTP server.\n");

    // Receive server greeting
    receive_response(socket_desc);

    // HELO command
    respond(socket_desc, "HELO localhost\r\n");
    receive_response(socket_desc);

    // Get email details from user
    printf("Enter your Email Address (From): ");
    scanf("%s", from_email);
    printf("Enter Recipient Email Address (To): ");
    scanf("%s", to_email);
    printf("Enter Subject: ");
    getchar(); // to consume the newline left by previous input
    fgets(subject, sizeof(subject), stdin);
    printf("Enter Message Body:\n");
    fgets(message_body, sizeof(message_body), stdin);

    // MAIL FROM command
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "MAIL FROM:<%s>\r\n", from_email);
    respond(socket_desc, command);
    receive_response(socket_desc);

    // RCPT TO command
    snprintf(command, sizeof(command), "RCPT TO:<%s>\r\n", to_email);
    respond(socket_desc, command);
    receive_response(socket_desc);

    // DATA command
    respond(socket_desc, "DATA\r\n");
    receive_response(socket_desc);

    // Sending the mail content
    snprintf(command, sizeof(command), "Subject: %s\r\nFrom: %s\r\nTo: %s\r\n\r\n%s\r\n.\r\n", 
            subject, from_email, to_email, message_body);
    respond(socket_desc, command);
    receive_response(socket_desc);

    // QUIT command
    respond(socket_desc, "QUIT\r\n");
    receive_response(socket_desc);

    // Close the socket
    close(socket_desc);
    printf("Email sent successfully! Goodbye!\n");
    return 0;
}