//Falcon-180B DATASET v1.0 Category: Email Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 500

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    time_t timestamp;
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email(char* subject, char* body) {
    if (num_emails >= MAX_EMAILS) {
        printf("Cannot add more emails. Email box is full!\n");
        return;
    }

    strcpy(emails[num_emails].subject, subject);
    strcpy(emails[num_emails].body, body);
    emails[num_emails].timestamp = time(NULL);

    num_emails++;
}

void print_emails() {
    printf("=================== Email Box ===================\n");
    for (int i = 0; i < num_emails; i++) {
        printf("%d. %s\n%s\n", i+1, emails[i].subject, emails[i].body);
    }
    printf("=================================================\n");
}

int main() {
    char choice;

    while (1) {
        printf("\n");
        printf("Welcome to the Email Client!\n");
        printf("Please choose an option:\n");
        printf("A - Add email\n");
        printf("R - Read emails\n");
        printf("Q - Quit\n");
        scanf(" %c", &choice);

        switch (choice) {
            case 'A':
                printf("Enter email subject: ");
                scanf(" %[^\n]", emails[num_emails].subject);
                printf("Enter email body: ");
                scanf(" %[^\n]", emails[num_emails].body);
                add_email(emails[num_emails].subject, emails[num_emails].body);
                break;
            case 'R':
                print_emails();
                break;
            case 'Q':
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}