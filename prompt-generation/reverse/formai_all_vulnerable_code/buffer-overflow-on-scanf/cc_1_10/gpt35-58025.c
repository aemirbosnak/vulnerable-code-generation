//FormAI DATASET v1.0 Category: Mailing list manager ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100

typedef struct Email {
    char name[50];
    char email[50];
} Email;

typedef struct MailingList {
    int num_emails;
    Email emails[MAX_EMAILS];
} MailingList;

void addEmail(MailingList *list) {
    if (list->num_emails >= MAX_EMAILS) {
        printf("Mailing list is full!\n");
        return;
    }

    Email new_email;

    printf("Enter name: ");
    scanf("%s", new_email.name);
    printf("Enter email: ");
    scanf("%s", new_email.email);

    list->emails[list->num_emails] = new_email;
    list->num_emails++;

    printf("Email added successfully!\n");
}

void removeEmail(MailingList *list) {
    if (list->num_emails == 0) {
        printf("Mailing list is empty!\n");
        return;
    }

    char email[50];
    printf("Enter the email you want to remove: ");
    scanf("%s", email);

    int found = 0;
    for (int i = 0; i < list->num_emails; i++) {
        if (strcmp(list->emails[i].email, email) == 0) {
            found = 1;
            for (int j = i; j < list->num_emails - 1; j++) {
                list->emails[j] = list->emails[j+1];
            }
            list->num_emails--;
        }
    }

    if (found) {
        printf("Email removed successfully!\n");
    } else {
        printf("Email not found!\n");
    }
}

void printList(MailingList *list) {
    if (list->num_emails == 0) {
        printf("Mailing list is empty!\n");
        return;
    }

    printf("%-20s\t%-20s\n", "Name", "Email");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < list->num_emails; i++) {
        printf("%-20s\t%-20s\n", list->emails[i].name, list->emails[i].email);
    }
}

int main() {
    MailingList list;
    list.num_emails = 0;

    int choice;
    while (1) {
        printf("\n");
        printf("Mailing List Manager\n");
        printf("1. Add email\n");
        printf("2. Remove email\n");
        printf("3. Print list\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                addEmail(&list);
                break;
            case 2:
                removeEmail(&list);
                break;
            case 3:
                printList(&list);
                break;
            case 4:
                printf("Thank you for using Mailing List Manager!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}