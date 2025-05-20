//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 25

struct email {
    char *from;
    char *to;
    char *subject;
    char *message;
};

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct email email;

    // Get email details from user
    printf("Enter sender's email: ");
    scanf("%s", email.from);
    printf("Enter recipient's email: ");
    scanf("%s", email.to);
    printf("Enter subject: ");
    scanf("%s", email.subject);
    printf("Enter message: ");
    scanf("%s", email.message);

    // Connect to SMTP server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
    connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Send email
    char send_buffer[1024];
    sprintf(send_buffer, "HELO %s\r\n", email.from);
    send(sock, send_buffer, strlen(send_buffer), 0);
    sprintf(send_buffer, "MAIL FROM:<%s>\r\n", email.from);
    send(sock, send_buffer, strlen(send_buffer), 0);
    sprintf(send_buffer, "RCPT TO:<%s>\r\n", email.to);
    send(sock, send_buffer, strlen(send_buffer), 0);
    sprintf(send_buffer, "DATA\r\n");
    send(sock, send_buffer, strlen(send_buffer), 0);
    send(sock, email.message, strlen(email.message), 0);
    sprintf(send_buffer, "\r\n.\r\n");
    send(sock, send_buffer, strlen(send_buffer), 0);

    // Get response from SMTP server
    char recv_buffer[1024];
    recv(sock, recv_buffer, 1024, 0);
    printf("%s\n", recv_buffer);

    // Close connection
    char close_buffer[1024];
    sprintf(close_buffer, "QUIT\r\n");
    send(sock, close_buffer, strlen(close_buffer), 0);
    close(sock);

    return 0;
}