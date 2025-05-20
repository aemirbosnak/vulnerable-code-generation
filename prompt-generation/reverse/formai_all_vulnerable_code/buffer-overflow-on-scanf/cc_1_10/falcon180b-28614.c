//Falcon-180B DATASET v1.0 Category: Email Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 200

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    time_t timestamp;
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email(char* subject, char* body) {
    if (num_emails >= MAX_EMAILS) {
        printf("Error: Email inbox is full.\n");
        return;
    }
    strcpy(emails[num_emails].subject, subject);
    strcpy(emails[num_emails].body, body);
    emails[num_emails].timestamp = time(NULL);
    num_emails++;
}

void print_email(int index) {
    if (index >= 0 && index < num_emails) {
        printf("Subject: %s\n", emails[index].subject);
        printf("Body: %s\n", emails[index].body);
        printf("Timestamp: %s\n\n", ctime(&emails[index].timestamp));
    } else {
        printf("Error: Invalid email index.\n");
    }
}

void search_emails(char* keyword) {
    int i;
    for (i = 0; i < num_emails; i++) {
        if (strstr(emails[i].subject, keyword) || strstr(emails[i].body, keyword)) {
            print_email(i);
        }
    }
}

int main() {
    int choice;
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];

    do {
        printf("Email Client\n");
        printf("1. Add email\n");
        printf("2. Print email\n");
        printf("3. Search emails\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter subject: ");
                scanf("%s", subject);
                printf("Enter body: ");
                scanf("%s", body);
                add_email(subject, body);
                break;
            case 2:
                printf("Enter email index: ");
                scanf("%d", &choice);
                print_email(choice);
                break;
            case 3:
                printf("Enter keyword: ");
                scanf("%s", subject);
                search_emails(subject);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Error: Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}