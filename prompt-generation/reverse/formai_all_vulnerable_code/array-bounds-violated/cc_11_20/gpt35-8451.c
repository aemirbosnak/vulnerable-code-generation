//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <netinet/in.h>

#define SMTP_PORT 25               // SMTP Server Port Number
#define BUFFER_SIZE 1024           // Buffer size

int main(int argc, char *argv[]) {
    int socket_desc, response;
    struct sockaddr_in server_address;
    struct hostent *server;

    char *from_email, *to_email, *subject, *message_body;
    char buffer[BUFFER_SIZE], command[BUFFER_SIZE];

    // Check if all required arguments are passed
    if(argc < 5) {
        printf("Usage: %s <smtp_server> <from_email> <to_email> <subject> <message_body>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get emails and other details from command line arguments
    char *smtp_server = argv[1];
    from_email = argv[2];
    to_email = argv[3];
    subject = argv[4];
    message_body = argv[5];

    // Get IP address of SMTP Server
    server = gethostbyname(smtp_server);
    if (server == NULL) {
        fprintf(stderr,"Error: Could not resolve SMTP server %s \n", smtp_server);
        exit(EXIT_FAILURE);
    }

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc < 0) {
        fprintf(stderr, "Error: Could not create socket \n");
        exit(EXIT_FAILURE);
    }

    // Set server details
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SMTP_PORT);
    server_address.sin_addr = *((struct in_addr *)server->h_addr);

    // Connect to server
    if (connect(socket_desc, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "Error: Could not connect to SMTP server %s \n", smtp_server);
        exit(EXIT_FAILURE);
    }

    // Wait for SMTP Server's response
    response = recv(socket_desc, buffer, BUFFER_SIZE, 0);
    buffer[response] = '\0';
    printf("%s\n", buffer);

    // Send HELO command to SMTP Server
    sprintf(command, "HELO example.com\r\n");
    if (send(socket_desc, command, strlen(command), 0) < 0) {
        fprintf(stderr, "Error: Could not send HELO command \n");
        exit(EXIT_FAILURE);
    }

    // Wait for SMTP Server's response
    response = recv(socket_desc, buffer, BUFFER_SIZE, 0);
    buffer[response] = '\0';
    printf("%s\n", buffer);

    // Send MAIL FROM command to SMTP Server
    sprintf(command, "MAIL FROM: %s\r\n", from_email);
    if (send(socket_desc, command, strlen(command), 0) < 0) {
        fprintf(stderr, "Error: Could not send MAIL FROM command \n");
        exit(EXIT_FAILURE);
    }

    // Wait for SMTP Server's response
    response = recv(socket_desc, buffer, BUFFER_SIZE, 0);
    buffer[response] = '\0';
    printf("%s\n", buffer);

    // Send RCPT TO command to SMTP Server
    sprintf(command, "RCPT TO: %s\r\n", to_email);
    if (send(socket_desc, command, strlen(command), 0) < 0) {
        fprintf(stderr, "Error: Could not send RCPT TO command \n");
        exit(EXIT_FAILURE);
    }

    // Wait for SMTP Server's response
    response = recv(socket_desc, buffer, BUFFER_SIZE, 0);
    buffer[response] = '\0';
    printf("%s\n", buffer);

    // Send DATA command to SMTP Server
    sprintf(command, "DATA\r\n");
    if (send(socket_desc, command, strlen(command), 0) < 0) {
        fprintf(stderr, "Error: Could not send DATA command \n");
        exit(EXIT_FAILURE);
    }

    // Wait for SMTP Server's response
    response = recv(socket_desc, buffer, BUFFER_SIZE, 0);
    buffer[response] = '\0';
    printf("%s\n", buffer);

    // Send email
    sprintf(command, "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, message_body);
    if (send(socket_desc, command, strlen(command), 0) < 0) {
        fprintf(stderr, "Error: Could not send email \n");
        exit(EXIT_FAILURE);
    }

    // Wait for SMTP Server's response
    response = recv(socket_desc, buffer, BUFFER_SIZE, 0);
    buffer[response] = '\0';
    printf("%s\n", buffer);

    // Send QUIT command to SMTP Server
    sprintf(command, "QUIT\r\n");
    if (send(socket_desc, command, strlen(command), 0) < 0) {
        fprintf(stderr, "Error: Could not send QUIT command \n");
        exit(EXIT_FAILURE);
    }

    // Wait for SMTP Server's response
    response = recv(socket_desc, buffer, BUFFER_SIZE, 0);
    buffer[response] = '\0';
    printf("%s\n", buffer);

    // Close socket
    close(socket_desc);

    return 0;
}