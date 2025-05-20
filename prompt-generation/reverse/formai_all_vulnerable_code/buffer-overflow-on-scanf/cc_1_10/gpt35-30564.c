//FormAI DATASET v1.0 Category: Mailing list manager ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 50
#define MAX_EMAIL_LENGTH 50

typedef struct MailingList {
    char emails[MAX_EMAILS][MAX_EMAIL_LENGTH];
    int size;
} MailingList;

void displayMailingList(MailingList* list) {
    printf("Mailing List:\n");
    for(int i=0; i<list->size; i++) {
        printf("%s\n", list->emails[i]);
    }
}

void addToMailingList(MailingList* list, char email[MAX_EMAIL_LENGTH]) {
    if(list->size >= MAX_EMAILS) {
        printf("Error: Mailing list is full. Cannot add more emails.\n");
        return;
    }

    for(int i=0; i<list->size; i++) {
        if(strcmp(list->emails[i], email) == 0) {
            printf("Error: Email already exists in mailing list.\n");
            return;
        }
    }

    strcpy(list->emails[list->size], email);
    list->size++;
    printf("Email added successfully.\n");
}

void removeFromMailingList(MailingList* list, char email[MAX_EMAIL_LENGTH]) {
    int emailIndex = -1;

    for(int i=0; i<list->size; i++) {
        if(strcmp(list->emails[i], email) == 0) {
            emailIndex = i;
            break;
        }
    }

    if(emailIndex == -1) {
        printf("Error: Email does not exist in mailing list.\n");
        return;
    }

    for(int i=emailIndex; i<list->size-1; i++) {
        strcpy(list->emails[i], list->emails[i+1]);
    }
    list->size--;
    printf("Email removed successfully.\n");
}

int main() {
    MailingList list;
    list.size = 0;

    int choice;
    char email[MAX_EMAIL_LENGTH];

    do {
        printf("Choose an option:\n");
        printf("1. Display mailing list\n");
        printf("2. Add email to mailing list\n");
        printf("3. Remove email from mailing list\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                displayMailingList(&list);
                break;
            case 2:
                printf("Enter email address to add: ");
                scanf("%s", email);
                addToMailingList(&list, email);
                break;
            case 3:
                printf("Enter email address to remove: ");
                scanf("%s", email);
                removeFromMailingList(&list, email);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 4);

    return 0;
}