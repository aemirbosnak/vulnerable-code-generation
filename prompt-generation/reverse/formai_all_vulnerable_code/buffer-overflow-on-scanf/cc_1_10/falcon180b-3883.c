//Falcon-180B DATASET v1.0 Category: Email Client ; Style: medieval
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

void add_email() {
    if (num_emails >= MAX_EMAILS) {
        printf("Thou canst not add more emails, the inbox is full!\n");
        return;
    }

    printf("Enter the subject of the email: ");
    scanf("%49s", emails[num_emails].subject);

    printf("Enter the body of the email: ");
    fgets(emails[num_emails].body, MAX_BODY_LENGTH, stdin);

    time(&emails[num_emails].timestamp);

    num_emails++;

    printf("Email added successfully!\n");
}

void list_emails() {
    if (num_emails == 0) {
        printf("Thou hast no emails in thy inbox.\n");
        return;
    }

    printf("Subject\tTimestamp\n");
    for (int i = 0; i < num_emails; i++) {
        printf("%s\t%s\n", emails[i].subject, ctime(&emails[i].timestamp));
    }
}

void read_email(int index) {
    if (index >= num_emails || index < 0) {
        printf("Invalid email index.\n");
        return;
    }

    printf("Subject: %s\n", emails[index].subject);
    printf("Body:\n%s", emails[index].body);
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        printf("Choose thy action:\n");
        printf("1. Add email\n");
        printf("2. List emails\n");
        printf("3. Read email\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_email();
                break;
            case 2:
                list_emails();
                break;
            case 3:
                printf("Enter the email index: ");
                int index;
                scanf("%d", &index);
                read_email(index);
                break;
            case 4:
                printf("Farewell, noble user!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}