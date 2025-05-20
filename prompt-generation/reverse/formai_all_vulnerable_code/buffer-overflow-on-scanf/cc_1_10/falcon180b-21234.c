//Falcon-180B DATASET v1.0 Category: Email Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAILS 100
#define SUBJECT_LENGTH 80
#define BODY_LENGTH 1024
#define EMAIL_LENGTH 256

typedef struct {
    char from[EMAIL_LENGTH];
    char to[EMAIL_LENGTH];
    char subject[SUBJECT_LENGTH];
    char body[BODY_LENGTH];
    time_t timestamp;
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email() {
    if (num_emails >= MAX_EMAILS) {
        printf("Sorry, cannot add more emails.\n");
        return;
    }

    printf("Enter sender email: ");
    scanf("%s", emails[num_emails].from);

    printf("Enter recipient email: ");
    scanf("%s", emails[num_emails].to);

    printf("Enter subject: ");
    scanf("%s", emails[num_emails].subject);

    printf("Enter body: ");
    scanf("%[^\n]", emails[num_emails].body);

    emails[num_emails].timestamp = time(NULL);
    num_emails++;
}

void display_emails() {
    printf("Total emails: %d\n", num_emails);
    for (int i = 0; i < num_emails; i++) {
        printf("Email %d:\n");
        printf("From: %s\n", emails[i].from);
        printf("To: %s\n", emails[i].to);
        printf("Subject: %s\n", emails[i].subject);
        printf("Body: %s\n", emails[i].body);
        printf("Timestamp: %s\n\n", ctime(&emails[i].timestamp));
    }
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        printf("Choose an option:\n");
        printf("1. Add email\n");
        printf("2. Display emails\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_email();
                break;
            case 2:
                display_emails();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}