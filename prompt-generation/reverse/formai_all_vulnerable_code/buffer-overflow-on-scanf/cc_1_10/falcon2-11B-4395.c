//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAIL_LENGTH 100
#define MAX_MAILING_LIST_SIZE 100

typedef struct {
    char email[MAX_EMAIL_LENGTH];
    int is_deleted;
} MailingList;

MailingList mailingList[MAX_MAILING_LIST_SIZE];
int listSize = 0;

void addEmailToList(const char* email) {
    int i;
    MailingList* list = malloc(MAX_MAILING_LIST_SIZE * sizeof(MailingList));

    for (i = 0; i < MAX_MAILING_LIST_SIZE; i++) {
        list[i].email[0] = '\0';
        list[i].is_deleted = 0;
    }

    strcpy(list[listSize].email, email);
    list[listSize].is_deleted = 0;
    listSize++;
}

void deleteEmailFromList(const char* email) {
    int i;
    for (i = 0; i < listSize; i++) {
        if (strcmp(mailingList[i].email, email) == 0) {
            mailingList[i].is_deleted = 1;
            break;
        }
    }
}

void displayMailingList() {
    int i;
    printf("Mailing List:\n");
    for (i = 0; i < listSize; i++) {
        if (!mailingList[i].is_deleted) {
            printf("Email: %s\n", mailingList[i].email);
        }
    }
}

int main() {
    int choice;
    char email[MAX_EMAIL_LENGTH];

    do {
        printf("1. Add Email\n");
        printf("2. Delete Email\n");
        printf("3. Display Mailing List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter email address: ");
                scanf("%s", email);
                addEmailToList(email);
                break;
            case 2:
                printf("Enter email address: ");
                scanf("%s", email);
                deleteEmailFromList(email);
                break;
            case 3:
                displayMailingList();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice!= 4);

    return 0;
}