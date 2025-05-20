//MISTRAL-7B DATASET v1.0 Category: Email Client ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256
#define EMAIL_FILE "emails.txt"

typedef struct {
    char from[MAX_LINE];
    char to[MAX_LINE];
    char subject[MAX_LINE];
    char body[MAX_LINE];
} Email;

void read_email(FILE *fp, Email *email) {
    fscanf(fp, "%s %s %s %[^\n]\n", email->from, email->to, email->subject, email->body);
}

void write_email(FILE *fp, Email email) {
    fprintf(fp, "%s: %s\n", email.from, email.to);
    fprintf(fp, "Subject: %s\n\n", email.subject);
    fprintf(fp, "%s\n", email.body);
}

void receive_email(Email *email) {
    FILE *fp = fopen(EMAIL_FILE, "r");
    if (fp == NULL) {
        printf("Error: Unable to open email file.\n");
        return;
    }

    read_email(fp, email);
    fclose(fp);

    printf("\nReceived email from %s:\n", email->from);
    printf("Subject: %s\n", email->subject);
    printf("\n%s\n", email->body);
}

void send_email(Email email) {
    FILE *fp = fopen(EMAIL_FILE, "a");
    if (fp == NULL) {
        printf("Error: Unable to open email file for writing.\n");
        return;
    }

    write_email(fp, email);
    fclose(fp);

    printf("\nEmail sent to %s.\n", email.to);
}

int main() {
    Email my_email = {"Alan Turing", "Colossus", "Greetings, Colossus!", "Hello, mighty computer!\nI hope this email finds you in good health.\nBest regards,\nAlan Turing"};

    printf("\nSending email:\n");
    send_email(my_email);

    Email received_email;
    printf("\nChecking for new emails:\n");
    receive_email(&received_email);

    return 0;
}