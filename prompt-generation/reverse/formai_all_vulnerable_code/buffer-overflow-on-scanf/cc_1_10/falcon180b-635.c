//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct email_entry {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} EmailEntry;

EmailEntry emails[MAX_EMAILS];
int num_emails = 0;

void add_email(char* name, char* email) {
    if (num_emails >= MAX_EMAILS) {
        printf("Error: Mailing list is full.\n");
        return;
    }
    strcpy(emails[num_emails].name, name);
    strcpy(emails[num_emails].email, email);
    num_emails++;
    printf("Email added successfully.\n");
}

void remove_email(char* name) {
    int i;
    for (i = 0; i < num_emails; i++) {
        if (strcmp(emails[i].name, name) == 0) {
            memmove(&emails[i], &emails[i+1], sizeof(EmailEntry) * (num_emails - i - 1));
            num_emails--;
            printf("Email removed successfully.\n");
            return;
        }
    }
    printf("Email not found.\n");
}

void display_emails() {
    int i;
    for (i = 0; i < num_emails; i++) {
        printf("%s - %s\n", emails[i].name, emails[i].email);
    }
}

int main() {
    char choice;
    int i;
    do {
        printf("Mailing list manager\n");
        printf("1. Add email\n");
        printf("2. Remove email\n");
        printf("3. Display emails\n");
        printf("4. Exit\n");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                printf("Enter name: ");
                scanf("%s", emails[num_emails-1].name);
                printf("Enter email: ");
                scanf("%s", emails[num_emails-1].email);
                break;
            case '2':
                printf("Enter name to remove: ");
                scanf("%s", emails[num_emails-1].name);
                remove_email(emails[num_emails-1].name);
                break;
            case '3':
                display_emails();
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '4');
    return 0;
}