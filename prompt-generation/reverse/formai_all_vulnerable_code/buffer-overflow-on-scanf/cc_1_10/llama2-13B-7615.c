//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_MAILBOX_SIZE 1024
#define MAX_MESSAGE_SIZE 10240

typedef struct {
    char *subject;
    char *body;
    char *to;
    char *from;
} mail_t;

void recursive_send_mail(mail_t *mail);
void compose_mail(mail_t *mail);
void send_mail(mail_t *mail);
void display_menu();

int main() {
    mail_t mail;

    while (1) {
        display_menu();
        scanf("%d", &mail.subject);
        if (mail.subject == 1) {
            compose_mail(&mail);
        } else if (mail.subject == 2) {
            send_mail(&mail);
        } else {
            break;
        }
    }

    return 0;
}

void display_menu() {
    printf("Email Client Menu\n");
    printf("1. Compose New Email\n");
    printf("2. Send Email\n");
    printf("3. Quit\n");
}

void compose_mail(mail_t *mail) {
    char buffer[MAX_MESSAGE_SIZE];
    char *p;

    printf("Composing Email...\n");

    p = buffer;
    *p = ' ';
    p++;

    // Recursively compose the email body
    compose_mail(mail);

    // Append the composed email body to the main email body
    strcat(buffer, mail->body);
    strcat(buffer, "\n");

    // Set the email subject and body
    mail->subject = "Composed Email";
    mail->body = buffer;

    // Print the composed email
    printf("Composed Email:\n%s\n", mail->body);
}

void send_mail(mail_t *mail) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[MAX_MESSAGE_SIZE];

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(25);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(1);
    }

    // Send the email
    send(sock, mail->body, strlen(mail->body), 0);

    // Close the socket
    close(sock);

    // Print the sent email
    printf("Email sent successfully\n");
}