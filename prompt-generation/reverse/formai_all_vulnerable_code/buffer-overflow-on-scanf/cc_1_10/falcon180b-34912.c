//Falcon-180B DATASET v1.0 Category: Email Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAIL_LENGTH 1000
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 5000
#define MAX_RECIPIENTS 10

typedef struct {
    char name[50];
    char email[MAX_EMAIL_LENGTH];
} contact;

typedef struct {
    char from[MAX_EMAIL_LENGTH];
    char to[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    time_t timestamp;
} email;

int compare_emails(const void *a, const void *b) {
    email *e1 = (email *)a;
    email *e2 = (email *)b;

    return strcmp(e1->from, e2->from);
}

void print_email(email *e) {
    printf("From: %s\n", e->from);
    printf("To: %s\n", e->to);
    printf("Subject: %s\n", e->subject);
    printf("Timestamp: %s\n", ctime(&e->timestamp));
    printf("Body:\n%s\n", e->body);
}

int main() {
    int choice;
    char input[MAX_EMAIL_LENGTH];
    contact contacts[MAX_RECIPIENTS];
    email emails[MAX_RECIPIENTS];
    int num_contacts = 0, num_emails = 0;

    do {
        system("clear");
        printf("Welcome to the Romantic Email Client!\n\n");

        printf("Please choose an option:\n");
        printf("1. Add contact\n");
        printf("2. Compose email\n");
        printf("3. View emails\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", contacts[num_contacts].name);
                printf("Enter email: ");
                scanf("%s", contacts[num_contacts].email);
                num_contacts++;
                break;
            case 2:
                printf("Enter recipient's name: ");
                scanf("%s", input);

                for (int i = 0; i < num_contacts; i++) {
                    if (strcmp(input, contacts[i].name) == 0) {
                        strcpy(emails[num_emails].to, contacts[i].email);
                        break;
                    }
                }

                printf("Enter subject: ");
                scanf("%s", emails[num_emails].subject);
                printf("Enter body:\n");
                fgets(emails[num_emails].body, MAX_BODY_LENGTH, stdin);
                strcat(emails[num_emails].body, "\n");
                emails[num_emails].timestamp = time(NULL);
                num_emails++;
                break;
            case 3:
                qsort(emails, num_emails, sizeof(email), compare_emails);

                for (int i = 0; i < num_emails; i++) {
                    print_email(&emails[i]);
                }

                break;
            case 4:
                printf("Thank you for using the Romantic Email Client!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice!= 4);

    return 0;
}