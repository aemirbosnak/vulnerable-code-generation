//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: accurate
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

void send_email(struct email *email) {
    int sock;
    char buffer[1024];
    char *message = email->message;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }

    memset(buffer, 0, 1024);
    sprintf(buffer, "FROM: %s\r\nTO: %s\r\nSUBJECT: %s\r\n\r\n%s",
            email->from, email->to, email->subject, message);

    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("send failed");
        exit(1);
    }

    close(sock);
}

int main() {
    struct email email;
    char *email_address[] = {"user@example.com", "recipient@example.com"};
    char *subject[] = {"Test Email", "Another Test Email"};
    char *message[] = {"This is a test email.", "This is another test email."};

    printf("Enter sender's email address: ");
    scanf("%s", email.from);
    printf("Enter recipient's email address: ");
    scanf("%s", email.to);
    printf("Enter subject: ");
    scanf("%s", email.subject);
    printf("Enter message: ");
    scanf("%s", email.message);

    send_email(&email);

    return 0;
}