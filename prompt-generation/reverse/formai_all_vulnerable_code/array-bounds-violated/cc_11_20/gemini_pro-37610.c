//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: visionary
// Embark on this celestial voyage, where code and imagination intertwine, and witness the birth of a visionary SMTP client.

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>

// A constellation of constants
#define SMTP_PORT 25
#define MAX_BUFFER 1024

// A vessel to carry our ethereal messages
typedef struct email {
    char from[MAX_BUFFER];
    char to[MAX_BUFFER];
    char subject[MAX_BUFFER];
    char body[MAX_BUFFER];
} email;

// The ethereal realm where our client resides
int main() {
    // Establish a connection to the celestial sphere
    struct sockaddr_in server_addr;
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        printf("Failed to connect to the celestial sphere.\n");
        return EXIT_FAILURE;
    }

    // Define the celestial coordinates of our destination
    struct hostent *server = gethostbyname("smtp.example.com");
    if (server == NULL) {
        printf("Celestial destination unknown.\n");
        return EXIT_FAILURE;
    }
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(SMTP_PORT);

    // Initiate the celestial handshake
    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Failed to establish celestial contact.\n");
        return EXIT_FAILURE;
    }

    // Receive the celestial greeting
    char buffer[MAX_BUFFER];
    int bytes_received = recv(sock_fd, buffer, MAX_BUFFER - 1, 0);
    if (bytes_received < 0) {
        printf("Celestial greeting lost in the ether.\n");
        return EXIT_FAILURE;
    }
    buffer[bytes_received] = '\0';
    printf("Celestial greeting: %s\n", buffer);

    // Compose our ethereal message
    email message;
    strcpy(message.from, "celestial_sender@example.com");
    strcpy(message.to, "celestial_recipient@example.com");
    strcpy(message.subject, "Greetings from the Celestial Sphere");
    strcpy(message.body, "May your celestial journey be filled with wonder and wisdom.");

    // Send the message to the celestial realm
    char mail_command[MAX_BUFFER];
    sprintf(mail_command, "MAIL FROM:<%s>\n", message.from);
    if (send(sock_fd, mail_command, strlen(mail_command), 0) < 0) {
        printf("Message lost in the celestial void.\n");
        return EXIT_FAILURE;
    }
    bytes_received = recv(sock_fd, buffer, MAX_BUFFER - 1, 0);
    if (bytes_received < 0) {
        printf("Celestial acknowledgement lost in the ether.\n");
        return EXIT_FAILURE;
    }
    buffer[bytes_received] = '\0';
    printf("Celestial acknowledgement: %s\n", buffer);

    sprintf(mail_command, "RCPT TO:<%s>\n", message.to);
    if (send(sock_fd, mail_command, strlen(mail_command), 0) < 0) {
        printf("Message lost in the celestial void.\n");
        return EXIT_FAILURE;
    }
    bytes_received = recv(sock_fd, buffer, MAX_BUFFER - 1, 0);
    if (bytes_received < 0) {
        printf("Celestial acknowledgement lost in the ether.\n");
        return EXIT_FAILURE;
    }
    buffer[bytes_received] = '\0';
    printf("Celestial acknowledgement: %s\n", buffer);

    if (send(sock_fd, "DATA\n", strlen("DATA\n"), 0) < 0) {
        printf("Message lost in the celestial void.\n");
        return EXIT_FAILURE;
    }
    bytes_received = recv(sock_fd, buffer, MAX_BUFFER - 1, 0);
    if (bytes_received < 0) {
        printf("Celestial acknowledgement lost in the ether.\n");
        return EXIT_FAILURE;
    }
    buffer[bytes_received] = '\0';
    printf("Celestial acknowledgement: %s\n", buffer);

    sprintf(mail_command, "From: %s\n", message.from);
    if (send(sock_fd, mail_command, strlen(mail_command), 0) < 0) {
        printf("Message lost in the celestial void.\n");
        return EXIT_FAILURE;
    }
    sprintf(mail_command, "To: %s\n", message.to);
    if (send(sock_fd, mail_command, strlen(mail_command), 0) < 0) {
        printf("Message lost in the celestial void.\n");
        return EXIT_FAILURE;
    }
    sprintf(mail_command, "Subject: %s\n", message.subject);
    if (send(sock_fd, mail_command, strlen(mail_command), 0) < 0) {
        printf("Message lost in the celestial void.\n");
        return EXIT_FAILURE;
    }
    if (send(sock_fd, message.body, strlen(message.body), 0) < 0) {
        printf("Message lost in the celestial void.\n");
        return EXIT_FAILURE;
    }
    if (send(sock_fd, ".\n", strlen(".\n"), 0) < 0) {
        printf("Message lost in the celestial void.\n");
        return EXIT_FAILURE;
    }
    bytes_received = recv(sock_fd, buffer, MAX_BUFFER - 1, 0);
    if (bytes_received < 0) {
        printf("Celestial acknowledgement lost in the ether.\n");
        return EXIT_FAILURE;
    }
    buffer[bytes_received] = '\0';
    printf("Celestial acknowledgement: %s\n", buffer);

    // End the celestial dialogue
    if (send(sock_fd, "QUIT\n", strlen("QUIT\n"), 0) < 0) {
        printf("Farewell lost in the celestial void.\n");
        return EXIT_FAILURE;
    }
    bytes_received = recv(sock_fd, buffer, MAX_BUFFER - 1, 0);
    if (bytes_received < 0) {
        printf("Celestial farewell lost in the ether.\n");
        return EXIT_FAILURE;
    }
    buffer[bytes_received] = '\0';
    printf("Celestial farewell: %s\n", buffer);

    // Close the ethereal gateway
    close(sock_fd);

    return EXIT_SUCCESS;
}