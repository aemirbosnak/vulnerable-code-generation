//Falcon-180B DATASET v1.0 Category: Email Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct email {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    int read;
} Email;

Email emails[MAX_EMAILS];
int num_emails;

void read_emails() {
    FILE *fp;
    char filename[30] = "emails.txt";
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: emails file not found.\n");
        exit(1);
    }

    while (fscanf(fp, "%s %s %d", emails[num_emails].subject, emails[num_emails].body, &emails[num_emails].read)!= EOF) {
        num_emails++;
    }

    fclose(fp);
}

void write_emails() {
    FILE *fp;
    char filename[30] = "emails.txt";
    fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Error: could not open emails file for writing.\n");
        exit(1);
    }

    for (int i = 0; i < num_emails; i++) {
        fprintf(fp, "%s %s %d\n", emails[i].subject, emails[i].body, emails[i].read);
    }

    fclose(fp);
}

void print_emails() {
    for (int i = 0; i < num_emails; i++) {
        printf("%d. Subject: %s\n", i+1, emails[i].subject);
        printf("  Body:\n%s\n", emails[i].body);
        printf("  Read: %s\n\n", emails[i].read? "Yes" : "No");
    }
}

void mark_as_read(int index) {
    emails[index].read = 1;
    write_emails();
}

int main() {
    read_emails();
    print_emails();

    int choice;
    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Mark as read\n2. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter email index: ");
                scanf("%d", &choice);
                mark_as_read(choice-1);
                break;
            case 2:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}