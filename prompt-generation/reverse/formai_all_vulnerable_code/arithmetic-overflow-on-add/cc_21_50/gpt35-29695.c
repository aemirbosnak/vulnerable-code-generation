//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char *message, server_reply[256];
    int message_len, recv_len, total_len;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
        return 1;
    }

    // Prepare the server address
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = htons( 25 );

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect failed. Error");
        return 1;
    }

    // Send HELO command
    message = "HELO example.com\r\n";
    message_len = strlen(message);
    if (send(sock, message, message_len, 0) != message_len) {
        printf("Send failed");
        return 1;
    }

    // Receive server reply to HELO command
    memset(server_reply, 0, sizeof(server_reply));
    total_len = 0;
    while ((recv_len = recv(sock, server_reply + total_len, sizeof(server_reply) - total_len, 0)) > 0) {
        total_len += recv_len;
    }
    if (recv_len == -1) {
        printf("Recv failed");
        return 1;
    }

    // Send MAIL FROM command
    message = "MAIL FROM: <sender@example.com>\r\n";
    message_len = strlen(message);
    if (send(sock, message, message_len, 0) != message_len) {
        printf("Send failed");
        return 1;
    }

    // Receive server reply to MAIL FROM command
    memset(server_reply, 0, sizeof(server_reply));
    total_len = 0;
    while ((recv_len = recv(sock, server_reply + total_len, sizeof(server_reply) - total_len, 0)) > 0) {
        total_len += recv_len;
    }
    if (recv_len == -1) {
        printf("Recv failed");
        return 1;
    }

    // Send RCPT TO command for each recipient
    message = "RCPT TO: <recipient1@example.com>\r\n";
    message_len = strlen(message);
    if (send(sock, message, message_len, 0) != message_len) {
        printf("Send failed");
        return 1;
    }

    // Receive server reply to RCPT TO command for first recipient
    memset(server_reply, 0, sizeof(server_reply));
    total_len = 0;
    while ((recv_len = recv(sock, server_reply + total_len, sizeof(server_reply) - total_len, 0)) > 0) {
        total_len += recv_len;
    }
    if (recv_len == -1) {
        printf("Recv failed");
        return 1;
    }

    message = "RCPT TO: <recipient2@example.com>\r\n";
    message_len = strlen(message);
    if (send(sock, message, message_len, 0) != message_len) {
        printf("Send failed");
        return 1;
    }

    // Receive server reply to RCPT TO command for second recipient
    memset(server_reply, 0, sizeof(server_reply));
    total_len = 0;
    while ((recv_len = recv(sock, server_reply + total_len, sizeof(server_reply) - total_len, 0)) > 0) {
        total_len += recv_len;
    }
    if (recv_len == -1) {
        printf("Recv failed");
        return 1;
    }

    // Send DATA command
    message = "DATA\r\n";
    message_len = strlen(message);
    if (send(sock, message, message_len, 0) != message_len) {
        printf("Send failed");
        return 1;
    }

    // Receive server reply to DATA command
    memset(server_reply, 0, sizeof(server_reply));
    total_len = 0;
    while ((recv_len = recv(sock, server_reply + total_len, sizeof(server_reply) - total_len, 0)) > 0) {
        total_len += recv_len;
    }
    if (recv_len == -1) {
        printf("Recv failed");
        return 1;
    }

    // Send message body
    message = "From: sender@example.com\r\nTo: recipient1@example.com, recipient2@example.com\r\nSubject: Test Email\r\n\r\nThis is a test email.\r\n.\r\n";
    message_len = strlen(message);
    if (send(sock, message, message_len, 0) != message_len) {
        printf("Send failed");
        return 1;
    }

    // Receive server reply to message body
    memset(server_reply, 0, sizeof(server_reply));
    total_len = 0;
    while ((recv_len = recv(sock, server_reply + total_len, sizeof(server_reply) - total_len, 0)) > 0) {
        total_len += recv_len;
    }
    if (recv_len == -1) {
        printf("Recv failed");
        return 1;
    }

    // Send QUIT command
    message = "QUIT\r\n";
    message_len = strlen(message);
    if (send(sock, message, message_len, 0) != message_len) {
        printf("Send failed");
        return 1;
    }

    // Receive server reply to QUIT command
    memset(server_reply, 0, sizeof(server_reply));
    total_len = 0;
    while ((recv_len = recv(sock, server_reply + total_len, sizeof(server_reply) - total_len, 0)) > 0) {
        total_len += recv_len;
    }
    if (recv_len == -1) {
        printf("Recv failed");
        return 1;
    }

    // Close socket
    close(sock);

    return 0;
}