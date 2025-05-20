//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100

typedef struct email {
    char name[50];
    char email[100];
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email() {
    if (num_emails >= MAX_EMAILS) {
        printf("Sorry, the mailing list is full!\n");
        return;
    }

    printf("Enter the name of the person: ");
    scanf("%s", emails[num_emails].name);

    printf("Enter the email address: ");
    scanf("%s", emails[num_emails].email);

    num_emails++;
    printf("Email added successfully!\n");
}

void delete_email() {
    int index;

    printf("Enter the index of the email to delete: ");
    scanf("%d", &index);

    if (index < 0 || index >= num_emails) {
        printf("Invalid index!\n");
        return;
    }

    for (int i = index; i < num_emails - 1; i++) {
        strcpy(emails[i].name, emails[i+1].name);
        strcpy(emails[i].email, emails[i+1].email);
    }

    num_emails--;
    printf("Email deleted successfully!\n");
}

void display_emails() {
    for (int i = 0; i < num_emails; i++) {
        printf("Name: %s\nEmail: %s\n", emails[i].name, emails[i].email);
    }
}

int main() {
    int choice;

    do {
        printf("Mailing List Manager\n");
        printf("1. Add email\n2. Delete email\n3. Display emails\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_email();
                break;
            case 2:
                delete_email();
                break;
            case 3:
                display_emails();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}