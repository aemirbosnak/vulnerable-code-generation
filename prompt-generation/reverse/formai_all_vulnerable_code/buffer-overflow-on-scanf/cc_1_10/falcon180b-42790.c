//Falcon-180B DATASET v1.0 Category: Email Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAILS 1000
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 10000

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    time_t timestamp;
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void print_email(int index) {
    Email email = emails[index];

    printf("Subject: %s\n", email.subject);
    printf("Timestamp: %s\n", ctime(&email.timestamp));
    printf("Body:\n%s\n", email.body);
}

int main() {
    char input[1000];
    int choice;

    while (1) {
        printf("\nCyberpunk Email Client\n");
        printf("1. Compose Email\n");
        printf("2. Read Emails\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter subject: ");
            scanf("%s", input);

            printf("Enter body: ");
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\r")] = '\0';

            emails[num_emails].subject[0] = toupper(input[0]);
            strcat(emails[num_emails].subject, &input[1]);

            strcat(emails[num_emails].body, input);
            emails[num_emails].timestamp = time(NULL);
            num_emails++;
            break;

        case 2:
            printf("You have %d unread emails.\n", num_emails);

            for (int i = 0; i < num_emails; i++) {
                print_email(i);
            }
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}