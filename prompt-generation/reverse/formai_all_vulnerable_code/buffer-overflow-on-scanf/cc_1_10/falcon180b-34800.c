//Falcon-180B DATASET v1.0 Category: Email Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define DELIMITER ","

typedef struct email {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email() {
    if (num_emails >= MAX_EMAILS) {
        printf("Error: Maximum number of emails reached.\n");
        return;
    }

    printf("Enter email subject: ");
    scanf("%s", emails[num_emails].subject);

    printf("Enter email body: ");
    fgets(emails[num_emails].body, MAX_BODY_LENGTH, stdin);
    emails[num_emails].body[strcspn(emails[num_emails].body, "\n")] = '\0';

    num_emails++;
}

void send_emails() {
    FILE *file;
    char filename[20];
    int i;

    for (i = 0; i < num_emails; i++) {
        sprintf(filename, "email_%d.txt", i);
        file = fopen(filename, "w");

        if (file == NULL) {
            printf("Error: Could not create file.\n");
            continue;
        }

        fprintf(file, "Subject: %s\n", emails[i].subject);
        fprintf(file, "Body:\n%s", emails[i].body);

        fclose(file);
        printf("Email sent successfully.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\nEmail Client\n");
        printf("1. Add email\n");
        printf("2. Send emails\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_email();
                break;
            case 2:
                send_emails();
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}