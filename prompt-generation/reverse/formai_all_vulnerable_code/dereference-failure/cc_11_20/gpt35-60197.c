//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int socket_desc;
    struct sockaddr_in server;
    char message[BUFFER_SIZE], response[BUFFER_SIZE];
    char *server_addr, *to_email, *from_email, *subject, *body;
    char *usr_agent = "My Email Client v1.0";
    int read_size;

    if (argc != 5) {
        printf("Usage: ./email_client <server_addr> <to_email> <from_email> <subject>\n");
        return 1;
    }

    server_addr = argv[1];
    to_email = argv[2];
    from_email = argv[3];
    subject = argv[4];

    // build email message body
    printf("Enter email body:\n");
    fgets(message, BUFFER_SIZE, stdin);
    body = strdup(message);

    // create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Failed to create socket.\n");
        return 1;
    }

    server.sin_addr.s_addr = inet_addr(server_addr);
    server.sin_family = AF_INET;
    server.sin_port = htons(SMTP_PORT);

    // connect to server
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Could not connect to server.\n");
        return 1;
    }

    // read server response
    if (recv(socket_desc, response, BUFFER_SIZE, 0) < 0) {
        printf("Failed to read response from server.\n");
        return 1;
    }

    // send HELO message
    memset(message, 0, BUFFER_SIZE);
    sprintf(message, "HELO %s\r\n", usr_agent);
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        printf("Failed to send HELO message.\n");
        return 1;
    }

    // read server response
    if (recv(socket_desc, response, BUFFER_SIZE, 0) < 0) {
        printf("Failed to read response from server.\n");
        return 1;
    }
    printf("%s\n", response);

    // send MAIL FROM message
    memset(message, 0, BUFFER_SIZE);
    sprintf(message, "MAIL FROM:<%s>\r\n", from_email);
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        printf("Failed to send MAIL FROM message.\n");
        return 1;
    }

    // read server response
    if (recv(socket_desc, response, BUFFER_SIZE, 0) < 0) {
        printf("Failed to read response from server.\n");
        return 1;
    }
    printf("%s\n", response);

    // send RCPT TO message
    memset(message, 0, BUFFER_SIZE);
    sprintf(message, "RCPT TO:<%s>\r\n", to_email);
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        printf("Failed to send RCPT TO message.\n");
        return 1;
    }

    // read server response
    if (recv(socket_desc, response, BUFFER_SIZE, 0) < 0) {
        printf("Failed to read response from server.\n");
        return 1;
    }
    printf("%s\n", response);

    // send DATA message
    memset(message, 0, BUFFER_SIZE);
    sprintf(message, "DATA\r\n");
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        printf("Failed to send DATA message.\n");
        return 1;
    }

    // read server response
    if (recv(socket_desc, response, BUFFER_SIZE, 0) < 0) {
        printf("Failed to read response from server.\n");
        return 1;
    }
    printf("%s\n", response);

    // send email message
    memset(message, 0, BUFFER_SIZE);
    sprintf(message, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", from_email, to_email, subject, body);
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        printf("Failed to send email message.\n");
        return 1;
    }

    // read server response
    if (recv(socket_desc, response, BUFFER_SIZE, 0) < 0) {
        printf("Failed to read response from server.\n");
        return 1;
    }
    printf("%s\n", response);

    // send QUIT message
    memset(message, 0, BUFFER_SIZE);
    sprintf(message, "QUIT\r\n");
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        printf("Failed to send QUIT message.\n");
        return 1;
    }

    // read server response
    if (recv(socket_desc, response, BUFFER_SIZE, 0) < 0) {
        printf("Failed to read response from server.\n");
        return 1;
    }
    printf("%s\n", response);

    close(socket_desc);

    return 0;
}