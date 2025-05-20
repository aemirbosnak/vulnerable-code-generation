//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_MESSAGE_SIZE 1024

int main(int argc, char *argv[]) {
    // Check if the user provided the recipient's address
    if (argc < 3) {
        printf("Usage: %s <recipient_address> <message>\n", argv[0]);
        exit(1);
    }

    char *recipient_address = argv[1];
    char *message = argv[2];
    int socket_desc;
    struct sockaddr_in server;

    // Create a socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket\n");
        exit(1);
    }

    // Define the server address and port
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // Change this to your SMTP server address
    server.sin_family = AF_INET;
    server.sin_port = htons(25);

    // Connect to the server
    if (connect(socket_desc, (struct sockaddr *) &server, sizeof(server)) < 0) {
        printf("Could not connect to server\n");
        exit(1);
    }

    // Receive the server greeting
    char buffer[MAX_MESSAGE_SIZE];
    if (recv(socket_desc, buffer, MAX_MESSAGE_SIZE, 0) < 0) {
        printf("Could not receive data from server\n");
        exit(1);
    }
    printf("%s\n", buffer);

    // Send the HELO/EHLO command
    char *helo = "EHLO client\r\n";
    if (send(socket_desc, helo, strlen(helo), 0) < 0) {
        printf("Could not send HELO/EHLO command\n");
        exit(1);
    }

    // Receive the server response
    if (recv(socket_desc, buffer, MAX_MESSAGE_SIZE, 0) < 0) {
        printf("Could not receive data from server\n");
        exit(1);
    }
    printf("%s\n", buffer);

    // Send the MAIL FROM command
    char *mail_from = "MAIL FROM: <sender@example.com>\r\n";
    if (send(socket_desc, mail_from, strlen(mail_from), 0) < 0) {
        printf("Could not send MAIL FROM command\n");
        exit(1);
    }

    // Receive the server response
    if (recv(socket_desc, buffer, MAX_MESSAGE_SIZE, 0) < 0) {
        printf("Could not receive data from server\n");
        exit(1);
    }
    printf("%s\n", buffer);

    // Send the RCPT TO command
    char rcpt_to[MAX_MESSAGE_SIZE];
    sprintf(rcpt_to, "RCPT TO: <%s>\r\n", recipient_address);
    if (send(socket_desc, rcpt_to, strlen(rcpt_to), 0) < 0) {
        printf("Could not send RCPT TO command\n");
        exit(1);
    }

    // Receive the server response
    if (recv(socket_desc, buffer, MAX_MESSAGE_SIZE, 0) < 0) {
        printf("Could not receive data from server\n");
        exit(1);
    }
    printf("%s\n", buffer);

    // Send the DATA command
    char *data = "DATA\r\n";
    if (send(socket_desc, data, strlen(data), 0) < 0) {
        printf("Could not send DATA command\n");
        exit(1);
    }

    // Receive the server response
    if (recv(socket_desc, buffer, MAX_MESSAGE_SIZE, 0) < 0) {
        printf("Could not receive data from server\n");
        exit(1);
    }
    printf("%s\n", buffer);

    // Send the message content
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        printf("Could not send message content\n");
        exit(1);
    }

    // Send the end-of-message marker
    char *eom = "\r\n.\r\n";
    if (send(socket_desc, eom, strlen(eom), 0) < 0) {
        printf("Could not send end-of-message marker\n");
        exit(1);
    }

    // Receive the server response
    if (recv(socket_desc, buffer, MAX_MESSAGE_SIZE, 0) < 0) {
        printf("Could not receive data from server\n");
        exit(1);
    }
    printf("%s\n", buffer);

    // Send the QUIT command
    char *quit = "QUIT\r\n";
    if (send(socket_desc, quit, strlen(quit), 0) < 0) {
        printf("Could not send QUIT command\n");
        exit(1);
    }

    // Receive the server response
    if (recv(socket_desc, buffer, MAX_MESSAGE_SIZE, 0) < 0) {
        printf("Could not receive data from server\n");
        exit(1);
    }
    printf("%s\n", buffer);

    // Close the socket
    close(socket_desc);

    return 0;
}