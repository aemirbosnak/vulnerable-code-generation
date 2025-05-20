//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFF 4096 // Max size of buffer

int main(int argc, char* argv[]) {

    if (argc != 3) {
        printf("Usage: %s <server address> <port number>\n", argv[0]);
        return 0;
    }

    char* server = argv[1];
    int port = atoi(argv[2]);

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Error creating socket\n");
        return -1;
    }

    // Set server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, server, &server_addr.sin_addr) <= 0) {
        perror("Invalid address or address not supported\n");
        return -1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server\n");
        return -1;
    }

    printf("Connected to server: %s:%d\n", server, port);

    // Receive welcome message
    char buff[MAX_BUFF] = {0};
    if (recv(sock, buff, MAX_BUFF, 0) < 0) {
        perror("Error receiving message from server\n");
        return -1;
    }

    printf("Server message: %s", buff);

    // Send HELO message
    if (send(sock, "HELO client\n", strlen("HELO client\n"), 0) < 0) {
        perror("Error sending HELO message\n");
        return -1;
    }

    // Receive HELO response
    if (recv(sock, buff, MAX_BUFF, 0) < 0) {
        perror("Error receiving message from server\n");
        return -1;
    }

    printf("Server message: %s", buff);

    // Send MAIL FROM message
    char mail_from[MAX_BUFF] = {0};
    printf("Enter your email address: ");
    scanf("%s", mail_from);
    char mail_from_msg[MAX_BUFF] = {0};
    sprintf(mail_from_msg, "MAIL FROM: <%s>\n", mail_from);

    if (send(sock, mail_from_msg, strlen(mail_from_msg), 0) < 0) {
        perror("Error sending MAIL FROM message\n");
        return -1;
    }

    // Receive MAIL FROM response
    if (recv(sock, buff, MAX_BUFF, 0) < 0) {
        perror("Error receiving message from server\n");
        return -1;
    }

    printf("Server message: %s", buff);

    // Send RCPT TO message
    char rcpt_to[MAX_BUFF] = {0};
    printf("Enter recipient email address: ");
    scanf("%s", rcpt_to);
    char rcpt_to_msg[MAX_BUFF] = {0};
    sprintf(rcpt_to_msg, "RCPT TO: <%s>\n", rcpt_to);

    if (send(sock, rcpt_to_msg, strlen(rcpt_to_msg), 0) < 0) {
        perror("Error sending RCPT TO message\n");
        return -1;
    }

    // Receive RCPT TO response
    if (recv(sock, buff, MAX_BUFF, 0) < 0) {
        perror("Error receiving message from server\n");
        return -1;
    }

    printf("Server message: %s", buff);

    // Send DATA message
    if (send(sock, "DATA\n", strlen("DATA\n"), 0) < 0) {
        perror("Error sending DATA message\n");
        return -1;
    }

    // Receive DATA response
    if (recv(sock, buff, MAX_BUFF, 0) < 0) {
        perror("Error receiving message from server\n");
        return -1;
    }

    printf("Server message: %s", buff);

    // Send message body
    char message_body[MAX_BUFF] = {0};
    printf("Enter message body (end with '.\\r\\n'): ");
    scanf(" %[^\n]s", message_body);

    if (send(sock, message_body, strlen(message_body), 0) < 0) {
        perror("Error sending message body\n");
        return -1;
    }

    // Send message end
    if (send(sock, ".\r\n", strlen(".\r\n"), 0) < 0) {
        perror("Error sending message end\n");
        return -1;
    }

    // Receive message end response
    if (recv(sock, buff, MAX_BUFF, 0) < 0) {
        perror("Error receiving message from server\n");
        return -1;
    }

    printf("Server message: %s", buff);

    // Send QUIT message
    if (send(sock, "QUIT\n", strlen("QUIT\n"), 0) < 0) {
        perror("Error sending QUIT message\n");
        return -1;
    }

    // Receive QUIT response
    if (recv(sock, buff, MAX_BUFF, 0) < 0) {
        perror("Error receiving message from server\n");
        return -1;
    }

    printf("Server message: %s", buff);

    // Close socket
    close(sock);

    return 0;
}