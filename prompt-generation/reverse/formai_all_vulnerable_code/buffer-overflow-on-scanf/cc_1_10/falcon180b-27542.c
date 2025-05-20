//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 1000
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email(char* name, char* email) {
    strcpy(emails[num_emails].name, name);
    strcpy(emails[num_emails].email, email);
    num_emails++;
}

void print_emails() {
    for (int i = 0; i < num_emails; i++) {
        printf("%s - %s\n", emails[i].name, emails[i].email);
    }
}

void remove_email(char* email) {
    for (int i = 0; i < num_emails; i++) {
        if (strcmp(emails[i].email, email) == 0) {
            for (int j = i; j < num_emails - 1; j++) {
                strcpy(emails[j].name, emails[j+1].name);
                strcpy(emails[j].email, emails[j+1].email);
            }
            num_emails--;
            return;
        }
    }
}

int main() {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    int choice;

    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add email\n");
        printf("2. Remove email\n");
        printf("3. Print emails\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                add_email(name, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                scanf("%s", email);
                remove_email(email);
                break;
            case 3:
                print_emails();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}