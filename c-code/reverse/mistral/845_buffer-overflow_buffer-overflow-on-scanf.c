#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_RECIPIENT 50
#define MAX_SUBJECT 100
#define MAX_BODY 500

void sendEmail(char recipient[MAX_RECIPIENT], char subject[MAX_SUBJECT], char body[MAX_BODY]) {
    printf("Sending email to %s with subject: %s\n", recipient, subject);
    printf("Email body:\n%s\n", body);
}

int main() {
    char recipient[MAX_RECIPIENT];
    char subject[MAX_SUBJECT];
    char body[MAX_BODY];

    printf("Email Client\n");
    printf("1. Send Email\n");
    printf("2. Exit\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter recipient:\n");
        scanf("%s", recipient);
        printf("Enter subject:\n");
        scanf("%s", subject);
        printf("Enter email body:\n");
        scanf("%s", body);

        sendEmail(recipient, subject, body);
    }

    return 0;
}
