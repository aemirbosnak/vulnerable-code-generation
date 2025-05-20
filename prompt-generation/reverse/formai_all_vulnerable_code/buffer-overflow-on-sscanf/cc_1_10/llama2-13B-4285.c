//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_EMAIL_LENGTH 512
#define MAX_SUBJECT_LENGTH 256
#define MAX_FROM_LENGTH 256
#define MAX_TO_LENGTH 256
#define MAX_CC_LENGTH 256
#define MAX_BCC_LENGTH 256

typedef struct {
    char *email;
    char *subject;
    char *from;
    char *to;
    char *cc;
    char *bcc;
} email_t;

void init_email(email_t *email) {
    email->email = NULL;
    email->subject = NULL;
    email->from = NULL;
    email->to = NULL;
    email->cc = NULL;
    email->bcc = NULL;
}

void parse_email(email_t *email, char *line) {
    char *token;

    if (sscanf(line, "%[^@]@%[^.]", &token, &email->from) == 2) {
        email->to = token;
    } else if (sscanf(line, "%[^.]", &token) == 1) {
        email->subject = token;
    } else if (sscanf(line, "%[^, ]", &token) == 1) {
        email->cc = token;
    } else if (sscanf(line, "%[^, ]", &token) == 1) {
        email->bcc = token;
    } else {
        email->email = line;
    }
}

void send_email(email_t *email) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    char *message = "Hello, this is an email sent from the C programming language!";

    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(25);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    send(sock, message, strlen(message), 0);

    close(sock);
}

int main() {
    email_t email;
    char buffer[4096];
    char line[1024];
    int bytes_read;

    init_email(&email);

    while (1) {
        printf("Email Client: ");
        fgets(line, 1024, stdin);

        parse_email(&email, line);

        if (email.email != NULL) {
            send_email(&email);
        }
    }

    return 0;
}