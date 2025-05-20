//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email(char* name, char* email) {
    if (num_emails >= MAX_EMAILS) {
        printf("Error: Mailing list is full.\n");
        return;
    }

    strcpy(emails[num_emails].name, name);
    strcpy(emails[num_emails].email, email);

    num_emails++;
}

void send_email(char* subject, char* message, char* from_email) {
    printf("Sending email...\n");
}

void view_emails() {
    printf("Mailing List:\n");
    for (int i = 0; i < num_emails; i++) {
        printf("%s - %s\n", emails[i].name, emails[i].email);
    }
}

int main() {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];

    printf("Welcome to the Mailing List Manager!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Please enter your email: ");
    scanf("%s", email);

    add_email(name, email);

    view_emails();

    return 0;
}