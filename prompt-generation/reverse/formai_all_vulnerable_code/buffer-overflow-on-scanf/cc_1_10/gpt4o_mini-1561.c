//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define EMAIL_SIZE 50

typedef struct Member {
    char email[EMAIL_SIZE];
    struct Member *next;
} Member;

typedef struct MailingList {
    Member *head;
} MailingList;

// Function to create a new Mail List
MailingList* createMailingList() {
    MailingList *list = (MailingList*)malloc(sizeof(MailingList));
    list->head = NULL;
    return list;
}

// Function to add a member to the mailing list
void addMember(MailingList *list, const char *email) {
    Member *newMember = (Member*)malloc(sizeof(Member));
    strncpy(newMember->email, email, EMAIL_SIZE);
    newMember->next = list->head;
    list->head = newMember;
    
    printf("Added: %s to the mailing list.\n", email);
}

// Function to remove a member from the mailing list
void removeMember(MailingList *list, const char *email) {
    Member *current = list->head;
    Member *previous = NULL;

    while (current != NULL && strcmp(current->email, email) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Email '%s' not found in the mailing list.\n", email);
        return;
    }

    if (previous == NULL) { // The member to be removed is the head
        list->head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    printf("Removed: %s from the mailing list.\n", email);
}

// Function to display the mailing list
void displayMembers(MailingList *list) {
    Member *current = list->head;
    if (current == NULL) {
        printf("The mailing list is empty.\n");
        return;
    }
    
    printf("Current mailing list members:\n");
    while (current != NULL) {
        printf("- %s\n", current->email);
        current = current->next;
    }
}

// Function to free the mailing list
void freeMailingList(MailingList *list) {
    Member *current = list->head;
    Member *nextMember;

    while (current != NULL) {
        nextMember = current->next;
        free(current);
        current = nextMember;
    }

    free(list);
}

// Main interactive function
void mailingListManager() {
    MailingList *list = createMailingList();
    char email[EMAIL_SIZE];
    int choice;

    while (1) {
        printf("\nWelcome to the Mailing List Manager!\n");
        printf("1. Add member\n");
        printf("2. Remove member\n");
        printf("3. Display members\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, EMAIL_SIZE, stdin);
                email[strcspn(email, "\n")] = 0; // remove newline
                addMember(list, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, EMAIL_SIZE, stdin);
                email[strcspn(email, "\n")] = 0; // remove newline
                removeMember(list, email);
                break;
            case 3:
                displayMembers(list);
                break;
            case 4:
                freeMailingList(list);
                printf("Exiting the Mailing List Manager.\n");
                return;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}

int main() {
    mailingListManager();
    return 0;
}