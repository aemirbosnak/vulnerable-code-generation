//Falcon-180B DATASET v1.0 Category: Email Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    time_t timestamp;
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void print_email(int index) {
    printf("Subject: %s\n", emails[index].subject);
    printf("Body:\n%s\n", emails[index].body);
    printf("Timestamp: %s\n", ctime(&emails[index].timestamp));
}

int main() {
    char input[1000];
    int choice;

    do {
        printf("Enter your choice:\n");
        printf("1. Compose email\n");
        printf("2. Read email\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter subject: ");
            scanf("%s", input);
            strcpy(emails[num_emails].subject, input);
            printf("Enter body: ");
            fgets(emails[num_emails].body, MAX_BODY_LENGTH, stdin);
            emails[num_emails].timestamp = time(NULL);
            num_emails++;
            break;
        case 2:
            printf("Enter email index: ");
            scanf("%d", &choice);
            if (choice >= 0 && choice < num_emails) {
                print_email(choice);
            } else {
                printf("Invalid email index.\n");
            }
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