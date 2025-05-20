//FormAI DATASET v1.0 Category: Mailing list manager ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100

// define email structure
typedef struct {
    char name[50];
    char email[50];
} Email;

// define mailing list structure
typedef struct {
    char title[50];
    Email emails[MAX_EMAILS];
    int count;
} MailingList;

// function to create a new mailing list
void createMailingList(MailingList *list) {
    printf("Enter mailing list title: ");
    scanf("%s", list->title);
    list->count = 0;
}

// function to add email to mailing list
void addEmail(MailingList *list) {
    if (list->count >= MAX_EMAILS) {
        printf("Mailing list is full.\n");
        return;
    }
    Email newEmail;
    printf("Enter name: ");
    scanf("%s", newEmail.name);
    printf("Enter email: ");
    scanf("%s", newEmail.email);
    list->emails[list->count] = newEmail;
    list->count++;
}

// function to print all emails in mailing list
void printEmails(MailingList list) {
    printf("%s\n", list.title);
    for (int i = 0; i < list.count; i++) {
        printf("%s - %s\n", list.emails[i].name, list.emails[i].email);
    }
}

int main() {
    MailingList list;
    createMailingList(&list);
    int choice;
    do {
        printf("1. Add email\n");
        printf("2. Print all emails\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEmail(&list);
                break;
            case 2:
                printEmails(list);
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);
    return 0;
}