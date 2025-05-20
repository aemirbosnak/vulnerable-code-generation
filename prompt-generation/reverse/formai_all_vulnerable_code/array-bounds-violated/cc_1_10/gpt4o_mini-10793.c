//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SMTP_SERVER "smtp.example.com" // Change this to your SMTP server
#define SMTP_PORT 587
#define BUFFER_SIZE 1024

void error_exit(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void send_command(int socket, const char *command) {
    if (send(socket, command, strlen(command), 0) < 0) {
        error_exit("Couldn't send command");
    }
}

void read_response(int socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(socket, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        error_exit("Couldn't read response");
    }
    buffer[bytes_received] = '\0';
    printf("Server response: %s", buffer);
}

int main() {
    // Declare and initialize the socket and server address structure
    int sockfd;
    struct sockaddr_in server_addr;

    // Invoke the establishment of a socket connection
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error_exit("Socket creation failed");
    }
    
    // Prepare the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr); // localhost for testing

    // Establish connection to the SMTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_exit("Connection failed");
    }

    // Read the server's initial response
    read_response(sockfd);

    // HELO command - introduce ourselves to the server
    send_command(sockfd, "HELO localhost\r\n");
    read_response(sockfd);

    // AUTH LOGIN command to authenticate the user
    send_command(sockfd, "AUTH LOGIN\r\n");
    read_response(sockfd);

    // Here you'd send the base64 encoded username and password
    // Fake base64 for demo purposes; replace with actual base64 encoded strings
    send_command(sockfd, "dXNlcm5hbWU=\r\n"); // "username"
    read_response(sockfd);
    send_command(sockfd, "cGFzc3dvcmQ=\r\n"); // "password"
    read_response(sockfd);

    // Specify sender and recipient
    send_command(sockfd, "MAIL FROM:<from@example.com>\r\n");
    read_response(sockfd);
    
    send_command(sockfd, "RCPT TO:<to@example.com>\r\n");
    read_response(sockfd);
    
    // Initiate the data transfer
    send_command(sockfd, "DATA\r\n");
    read_response(sockfd);

    // Send the email headers and body
    send_command(sockfd, "Subject: Test Email\r\n");
    send_command(sockfd, "From: from@example.com\r\n");
    send_command(sockfd, "To: to@example.com\r\n");
    send_command(sockfd, "\r\n"); // End of headers
    send_command(sockfd, "This is a test email sent from our SMTP client.\r\n");
    send_command(sockfd, ".\r\n"); // End of data
    read_response(sockfd);

    // Finally, gracefully close the session with QUIT
    send_command(sockfd, "QUIT\r\n");
    read_response(sockfd);

    // Cleanup and close the socket
    close(sockfd);
    
    return 0;
}