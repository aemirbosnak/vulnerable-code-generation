//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    char hostname[256];
    strncpy(hostname, argv[1], sizeof(hostname));
    int port = atoi(argv[2]);

    // create socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("socket");
        return 1;
    }

    // get host by name
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Host not found: %s\n", hostname);
        return 1;
    }

    // set up server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    memcpy(&server_address.sin_addr.s_addr, server->h_addr, server->h_length);
    server_address.sin_port = htons(port);

    // connect to server
    int status = connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    if (status == -1) {
        perror("connect");
        return 1;
    }

    // read greeting message from server
    char buffer[BUFFER_SIZE];
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // send HELO command
    char helo_cmd[BUFFER_SIZE];
    snprintf(helo_cmd, BUFFER_SIZE, "HELO %s\r\n", hostname);
    status = send(client_socket, helo_cmd, strlen(helo_cmd), 0);
    if (status == -1) {
        perror("send");
        return 1;
    }

    // read response to HELO command
    memset(buffer, 0, BUFFER_SIZE);
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // send MAIL FROM command
    char from_address[] = "sender@example.com";
    char mail_from_cmd[BUFFER_SIZE];
    snprintf(mail_from_cmd, BUFFER_SIZE, "MAIL FROM:<%s>\r\n", from_address);
    status = send(client_socket, mail_from_cmd, strlen(mail_from_cmd), 0);
    if (status == -1) {
        perror("send");
        return 1;
    }

    // read response to MAIL FROM command
    memset(buffer, 0, BUFFER_SIZE);
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // send RCPT TO command
    char to_address[] = "receiver@example.com";
    char rcpt_to_cmd[BUFFER_SIZE];
    snprintf(rcpt_to_cmd, BUFFER_SIZE, "RCPT TO:<%s>\r\n", to_address);
    status = send(client_socket, rcpt_to_cmd, strlen(rcpt_to_cmd), 0);
    if (status == -1) {
        perror("send");
        return 1;
    }

    // read response to RCPT TO command
    memset(buffer, 0, BUFFER_SIZE);
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // send DATA command
    char data_cmd[] = "DATA\r\n";
    status = send(client_socket, data_cmd, strlen(data_cmd), 0);
    if (status == -1) {
        perror("send");
        return 1;
    }

    // read response to DATA command
    memset(buffer, 0, BUFFER_SIZE);
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // send email message
    char email_message[] = "Subject: Test Email\r\n\r\nThis is a test email.\r\n";
    status = send(client_socket, email_message, strlen(email_message), 0);
    if (status == -1) {
        perror("send");
        return 1;
    }

    // send end of email message indicator
    char end_of_message[] = "\r\n.\r\n";
    status = send(client_socket, end_of_message, strlen(end_of_message), 0);
    if (status == -1) {
        perror("send");
        return 1;
    }

    // read response to end of email message indicator
    memset(buffer, 0, BUFFER_SIZE);
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // send QUIT command
    char quit_cmd[] = "QUIT\r\n";
    status = send(client_socket, quit_cmd, strlen(quit_cmd), 0);
    if (status == -1) {
        perror("send");
        return 1;
    }

    // read response to QUIT command
    memset(buffer, 0, BUFFER_SIZE);
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // close socket
    close(client_socket);

    return 0;
}