#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 200

void compose_email(char name[MAX_NAME_LENGTH], char email[MAX_EMAIL_LENGTH], char subject[MAX_SUBJECT_LENGTH], char body[MAX_BODY_LENGTH]);

int main() {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];

    printf("Email Client\n");
    printf("1. Compose\n2. Exit\n");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter your name: ");
        scanf("%s", name);
        printf("Enter recipient's email: ");
        scanf("%s", email);
        printf("Enter subject: ");
        scanf("%s", subject);
        printf("Enter email body (up to 200 characters): ");
        scanf("%s", body);
        compose_email(name, email, subject, body);
    }

    return 0;
}

void compose_email(char name[MAX_NAME_LENGTH], char email[MAX_EMAIL_LENGTH], char subject[MAX_SUBJECT_LENGTH], char body[MAX_BODY_LENGTH]) {
    printf("From: %s\n", name);
    printf("To: %s\n", email);
    printf("Subject: %s\n", subject);
    printf("Body:\n%s\n", body);

    // Vulnerable to buffer overflow in the email body section
}
