//Falcon-180B DATASET v1.0 Category: Email Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_SUBJECT_LENGTH 80

typedef struct {
    char from[MAX_LINE_LENGTH];
    char to[MAX_LINE_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_LINE_LENGTH];
} Email;

void read_email(FILE *file, Email *email) {
    char line[MAX_LINE_LENGTH];
    int i = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (i == 0) {
            strcpy(email->from, line);
        } else if (i == 1) {
            strcpy(email->to, line);
        } else if (i == 2) {
            strcpy(email->subject, line);
        } else {
            strcat(email->message, line);
            strcat(email->message, "\n");
        }
        i++;
    }
}

void send_email(FILE *file, Email *email) {
    fprintf(file, "From: %s\n", email->from);
    fprintf(file, "To: %s\n", email->to);
    fprintf(file, "Subject: %s\n", email->subject);
    fprintf(file, "%s", email->message);
}

int main() {
    FILE *inbox, *outbox;
    Email email;

    inbox = fopen("inbox.txt", "r");
    outbox = fopen("outbox.txt", "w");

    while (fscanf(inbox, "%s %s %s %s", email.from, email.to, email.subject, email.message)!= EOF) {
        read_email(inbox, &email);
        send_email(outbox, &email);
    }

    fclose(inbox);
    fclose(outbox);

    return 0;
}