//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 25
#define MAX_MESSAGE_LENGTH 512

struct email {
    char *from;
    char *to;
    char *subject;
    char *message;
};

void send_email(struct email *email) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connection failed");
        exit(1);
    }

    char message[MAX_MESSAGE_LENGTH];
    snprintf(message, sizeof(message), "%s %s %s\r\n%s", email->from, email->to, email->subject, email->message);

    send(sock, message, strlen(message), 0);

    char response[MAX_MESSAGE_LENGTH];
    recv(sock, response, MAX_MESSAGE_LENGTH, 0);

    printf("Response: %s\n", response);

    close(sock);
}

int main() {
    struct email email;
    printf("Enter sender's email: ");
    scanf("%s", email.from);
    printf("Enter recipient's email: ");
    scanf("%s", email.to);
    printf("Enter subject: ");
    scanf("%s", email.subject);
    printf("Enter message: ");
    scanf("%s", email.message);

    send_email(&email);

    return 0;
}