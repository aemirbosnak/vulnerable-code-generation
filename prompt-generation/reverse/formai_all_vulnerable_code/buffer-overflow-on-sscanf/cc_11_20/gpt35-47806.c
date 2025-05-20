//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <string.h>
#define MAX_COMMAND_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <server> <port>\n", argv[0]);
        return 1;
    }

    struct hostent *he;
    struct sockaddr_in server;

    if ((he = gethostbyname(argv[1])) == NULL) {
        printf("Error resolving host name\n");
        return 1;
    }

    int port;
    sscanf(argv[2], "%d", &port);

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    memcpy(&server.sin_addr, he->h_addr_list[0], he->h_length);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    char command[MAX_COMMAND_LENGTH] = {0};
    char response[MAX_COMMAND_LENGTH] = {0};
    int num_bytes;

    // Receive the server's greeting message
    num_bytes = recv(sock, response, MAX_COMMAND_LENGTH, 0);
    if (num_bytes < 0) {
        perror("Error receiving greeting message");
        return 1;
    }
    printf("Server: %s", response);

    // Send the HELO command
    snprintf(command, MAX_COMMAND_LENGTH, "HELO localhost\r\n");
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("Error sending HELO command");
        return 1;
    }

    // Receive the response to the HELO command
    num_bytes = recv(sock, response, MAX_COMMAND_LENGTH, 0);
    if (num_bytes < 0) {
        perror("Error receiving response to HELO command");
        return 1;
    }
    response[num_bytes] = '\0';
    printf("Server: %s", response);

    // Send the MAIL FROM command
    snprintf(command, MAX_COMMAND_LENGTH, "MAIL FROM:<test@test.com>\r\n");
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("Error sending MAIL FROM command");
        return 1;
    }

    // Receive the response to the MAIL FROM command
    num_bytes = recv(sock, response, MAX_COMMAND_LENGTH, 0);
    if (num_bytes < 0) {
        perror("Error receiving response to MAIL FROM command");
        return 1;
    }
    response[num_bytes] = '\0';
    printf("Server: %s", response);

    // Send the RCPT TO command
    snprintf(command, MAX_COMMAND_LENGTH, "RCPT TO:<test@test.com>\r\n");
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("Error sending RCPT TO command");
        return 1;
    }

    // Receive the response to the RCPT TO command
    num_bytes = recv(sock, response, MAX_COMMAND_LENGTH, 0);
    if (num_bytes < 0) {
        perror("Error receiving response to RCPT TO command");
        return 1;
    }
    response[num_bytes] = '\0';
    printf("Server: %s", response);

    // Send the DATA command
    snprintf(command, MAX_COMMAND_LENGTH, "DATA\r\n");
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("Error sending DATA command");
        return 1;
    }

    // Receive the response to the DATA command
    num_bytes = recv(sock, response, MAX_COMMAND_LENGTH, 0);
    if (num_bytes < 0) {
        perror("Error receiving response to DATA command");
        return 1;
    }
    response[num_bytes] = '\0';
    printf("Server: %s", response);

    // Send the message body
    snprintf(command, MAX_COMMAND_LENGTH, "Subject: Test email\r\n\r\nThis is a test email.\r\n.\r\n");
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("Error sending message body");
        return 1;
    }

    // Receive the response to the message body
    num_bytes = recv(sock, response, MAX_COMMAND_LENGTH, 0);
    if (num_bytes < 0) {
        perror("Error receiving response to message body");
        return 1;
    }
    response[num_bytes] = '\0';
    printf("Server: %s", response);

    // Send the QUIT command
    snprintf(command, MAX_COMMAND_LENGTH, "QUIT\r\n");
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("Error sending QUIT command");
        return 1;
    }

    // Receive the response to the QUIT command
    num_bytes = recv(sock, response, MAX_COMMAND_LENGTH, 0);
    if (num_bytes < 0) {
        perror("Error receiving response to QUIT command");
        return 1;
    }
    response[num_bytes] = '\0';
    printf("Server: %s", response);

    // Close the socket
    close(sock);

    return 0;
}