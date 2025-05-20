//Falcon-180B DATASET v1.0 Category: Email Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 200

typedef struct email {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    int read;
} Email;

void read_emails(Email* emails) {
    FILE* fp = fopen("emails.txt", "r");
    if (fp == NULL) {
        printf("No emails found.\n");
        exit(1);
    }

    int count = 0;
    while (count < MAX_EMAILS && fscanf(fp, "%s %s %d\n", emails[count].subject, emails[count].body, &emails[count].read) == 3) {
        count++;
    }

    fclose(fp);
}

void write_email(Email* emails, int index) {
    FILE* fp = fopen("emails.txt", "w");
    if (fp == NULL) {
        printf("Error writing emails.\n");
        exit(1);
    }

    for (int i = 0; i < MAX_EMAILS; i++) {
        if (emails[i].read == 0) {
            fprintf(fp, "%s %s %d\n", emails[i].subject, emails[i].body, emails[i].read);
        }
    }

    fclose(fp);
}

void display_emails(Email* emails) {
    printf("Subject\tRead\n");
    for (int i = 0; i < MAX_EMAILS; i++) {
        if (emails[i].read == 0) {
            printf("%s\tno\n", emails[i].subject);
        }
    }
}

void mark_as_read(Email* emails, int index) {
    emails[index].read = 1;
    write_email(emails, index);
}

int main() {
    Email emails[MAX_EMAILS];

    read_emails(emails);
    display_emails(emails);

    int choice;
    do {
        printf("\nEnter your choice:\n");
        printf("1. Display emails\n");
        printf("2. Mark as read\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_emails(emails);
                break;
            case 2:
                printf("Enter email index to mark as read: ");
                scanf("%d", &choice);
                mark_as_read(emails, choice - 1);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}