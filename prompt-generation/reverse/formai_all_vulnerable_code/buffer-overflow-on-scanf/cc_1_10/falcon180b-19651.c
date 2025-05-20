//Falcon-180B DATASET v1.0 Category: Email Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_ATTACHMENTS 10
#define MAX_ATTACHMENT_LENGTH 1000

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    int attachments_count;
    char attachments[MAX_ATTACHMENTS][MAX_ATTACHMENT_LENGTH];
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email() {
    printf("Enter subject: ");
    scanf("%s", emails[num_emails].subject);

    printf("Enter body: ");
    fgets(emails[num_emails].body, MAX_BODY_LENGTH, stdin);
    emails[num_emails].body[strcspn(emails[num_emails].body, "\n")] = '\0';

    printf("Enter number of attachments: ");
    scanf("%d", &emails[num_emails].attachments_count);

    for (int i = 0; i < emails[num_emails].attachments_count; i++) {
        printf("Enter attachment %d: ", i + 1);
        scanf("%s", emails[num_emails].attachments[i]);
    }

    num_emails++;
}

void list_emails() {
    printf("Subject\tBody\n");

    for (int i = 0; i < num_emails; i++) {
        printf("%s\t%s\n", emails[i].subject, emails[i].body);

        for (int j = 0; j < emails[i].attachments_count; j++) {
            printf("\tAttachment %d: %s\n", j + 1, emails[i].attachments[j]);
        }
    }
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        printf("1. Add email\n2. List emails\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_email();
                break;
            case 2:
                list_emails();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (true);

    return 0;
}