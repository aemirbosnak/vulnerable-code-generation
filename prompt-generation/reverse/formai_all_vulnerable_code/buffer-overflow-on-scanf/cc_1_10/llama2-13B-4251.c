//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_EMAIL_LENGTH 512
#define MAX_SUBJECT_LENGTH 1024
#define MAX_ATTACHMENT_LENGTH 102400

struct email {
    char *from;
    char *to;
    char *subject;
    char *message;
    char *attachment;
};

int main(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    struct email email;
    printf("Enter sender's email: ");
    scanf("%s", email.from);
    printf("Enter recipient's email: ");
    scanf("%s", email.to);
    printf("Enter subject: ");
    scanf("%s", email.subject);
    printf("Enter message: ");
    scanf("%s", email.message);
    printf("Enter attachment (optional): ");
    char *attachment = NULL;
    scanf("%s", attachment);

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(25);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    char send_buffer[1024];
    char recv_buffer[1024];

    // Build the email message
    sprintf(send_buffer, "From: %s\r\nTo: %s\r\nSubject: %s\r\n%s\r\n",
            email.from, email.to, email.subject, email.message);

    // Add attachment if present
    if (attachment != NULL) {
        sprintf(send_buffer + strlen(send_buffer), "Attachment: %s\r\n", attachment);
    }

    // Send the email
    if (send(sock, send_buffer, strlen(send_buffer), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // Receive the response
    recv(sock, recv_buffer, 1024, 0);

    // Print the response
    printf("Server response: %s\n", recv_buffer);

    close(sock);
    return 0;
}