//Falcon-180B DATASET v1.0 Category: Email Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 1000

typedef struct Email {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    int read;
} Email;

Email emails[MAX_EMAILS];
int num_emails;

void init() {
    num_emails = 0;
}

void add_email() {
    printf("Enter email subject (max %d characters): ", MAX_SUBJECT_LENGTH - 1);
    scanf("%s", emails[num_emails].subject);

    printf("Enter email body (max %d characters): ", MAX_BODY_LENGTH - 1);
    scanf("%s", emails[num_emails].body);

    emails[num_emails].read = 0;
    num_emails++;
}

void list_emails() {
    printf("Email list:\n");
    for (int i = 0; i < num_emails; i++) {
        printf("%d. %s (%s)\n", i + 1, emails[i].subject, emails[i].read? "Read" : "Unread");
    }
}

void read_email(int index) {
    if (index >= 0 && index < num_emails) {
        emails[index].read = 1;
        printf("Email %d has been marked as read.\n", index + 1);
    } else {
        printf("Invalid email index.\n");
    }
}

int main() {
    init();

    int choice;
    while (1) {
        printf("\nEmail Client Menu:\n");
        printf("1. Add email\n");
        printf("2. List emails\n");
        printf("3. Read email\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_email();
                break;
            case 2:
                list_emails();
                break;
            case 3:
                printf("Enter email index to mark as read: ");
                scanf("%d", &choice);
                read_email(choice - 1);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}