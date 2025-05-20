//Falcon-180B DATASET v1.0 Category: Email Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 1024
#define MAX_EMAIL_COUNT 100

typedef struct {
    char email[MAX_EMAIL_LENGTH];
    int count;
} Email;

void read_emails(Email emails[], int count) {
    FILE *file = fopen("emails.txt", "r");
    char line[MAX_EMAIL_LENGTH];

    if (file == NULL) {
        printf("Error reading emails file\n");
        exit(1);
    }

    for (int i = 0; i < count; i++) {
        fgets(line, MAX_EMAIL_LENGTH, file);
        strcpy(emails[i].email, line);
        emails[i].count = 0;
    }

    fclose(file);
}

void send_email(Email email) {
    printf("Sending email to %s\n", email.email);
    email.count++;
}

int main() {
    Email emails[MAX_EMAIL_COUNT];
    int count;

    printf("Enter the number of emails to send: ");
    scanf("%d", &count);

    read_emails(emails, count);

    for (int i = 0; i < count; i++) {
        send_email(emails[i]);
    }

    return 0;
}