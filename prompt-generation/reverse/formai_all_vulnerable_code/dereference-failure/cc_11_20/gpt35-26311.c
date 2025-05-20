//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char message[MAX_SIZE], server_reply[MAX_SIZE];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
        return 1;
    }

    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = htons(25);

    // Connect to remote server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect failed. Error");
        return 1;
    }

    // Receive greeting message from SMTP server
    if (recv(sock, server_reply, MAX_SIZE, 0) < 0) {
        printf("recv failed");
        return 1;
    }
    printf("%s", server_reply);

    // Send HELO message
    sprintf(message, "HELO %s\r\n", argv[2]);
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("send failed");
        return 1;
    }

    // Receive response to HELO message
    if (recv(sock, server_reply, MAX_SIZE, 0) < 0) {
        printf("recv failed");
        return 1;
    }
    printf("%s", server_reply);

    // Send MAIL FROM message
    sprintf(message, "MAIL FROM: <%s>\r\n", argv[3]);
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("send failed");
        return 1;
    }

    // Receive response to MAIL FROM message
    if (recv(sock, server_reply, MAX_SIZE, 0) < 0) {
        printf("recv failed");
        return 1;
    }
    printf("%s", server_reply);

    // Send RCPT TO message
    sprintf(message, "RCPT TO: <%s>\r\n", argv[4]);
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("send failed");
        return 1;
    }

    // Receive response to RCPT TO message
    if (recv(sock, server_reply, MAX_SIZE, 0) < 0) {
        printf("recv failed");
        return 1;
    }
    printf("%s", server_reply);

    // Send DATA message
    if (send(sock, "DATA\r\n", strlen("DATA\r\n"), 0) < 0) {
        printf("send failed");
        return 1;
    }

    // Receive response to DATA message
    if (recv(sock, server_reply, MAX_SIZE, 0) < 0) {
        printf("recv failed");
        return 1;
    }
    printf("%s", server_reply);

    // Send email message
    sprintf(message, "Subject: %s\r\n\r\n%s\r\n.\r\n", argv[5], argv[6]);
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("send failed");
        return 1;
    }

    // Receive response to email message
    if (recv(sock, server_reply, MAX_SIZE, 0) < 0) {
        printf("recv failed");
        return 1;
    }
    printf("%s", server_reply);

    // Send QUIT message
    if (send(sock, "QUIT\r\n", strlen("QUIT\r\n"), 0) < 0) {
        printf("send failed");
        return 1;
    }

    // Receive response to QUIT message
    if (recv(sock, server_reply, MAX_SIZE, 0) < 0) {
        printf("recv failed");
        return 1;
    }
    printf("%s", server_reply);

    close(sock);
    return 0;
}