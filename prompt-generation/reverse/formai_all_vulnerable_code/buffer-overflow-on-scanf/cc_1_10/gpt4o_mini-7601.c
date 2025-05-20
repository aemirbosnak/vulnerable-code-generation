//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

typedef struct Member {
    char name[MAX_NAME_LENGTH];
    struct Member *next;
} Member;

typedef struct MailingList {
    Member *head;
} MailingList;

// Function prototypes
MailingList* createMailingList();
void addMember(MailingList *list, const char *name);
void removeMember(MailingList *list, const char *name);
void displayMembers(MailingList *list);
void freeMailingList(MailingList *list);

int main() {
    MailingList *list = createMailingList();
    int choice;
    char name[MAX_NAME_LENGTH];

    do {
        printf("\nMailing List Manager\n");
        printf("1. Add Member\n");
        printf("2. Remove Member\n");
        printf("3. Display Members\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To absorb newline character after entering choice

        switch (choice) {
            case 1:
                printf("Enter member name to add: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                // Remove trailing newline character from fgets
                name[strcspn(name, "\n")] = 0; 
                addMember(list, name);
                break;
            case 2:
                printf("Enter member name to remove: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0;
                removeMember(list, name);
                break;
            case 3:
                displayMembers(list);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    freeMailingList(list);
    return 0;
}

MailingList* createMailingList() {
    MailingList *list = (MailingList *)malloc(sizeof(MailingList));
    list->head = NULL;
    return list;
}

void addMember(MailingList *list, const char *name) {
    Member *newMember = (Member *)malloc(sizeof(Member));
    strncpy(newMember->name, name, MAX_NAME_LENGTH);
    newMember->next = list->head;
    list->head = newMember;
    printf("Member '%s' added!\n", name);
}

void removeMember(MailingList *list, const char *name) {
    Member *current = list->head;
    Member *previous = NULL;

    while (current != NULL && strncmp(current->name, name, MAX_NAME_LENGTH) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Member '%s' not found!\n", name);
        return;
    }

    if (previous == NULL) {
        list->head = current->next; 
    } else {
        previous->next = current->next; 
    }

    free(current);
    printf("Member '%s' removed!\n", name);
}

void displayMembers(MailingList *list) {
    if (list->head == NULL) {
        printf("No members in the mailing list.\n");
        return;
    }

    printf("Mailing List Members:\n");
    Member *current = list->head;
    while (current != NULL) {
        printf("- %s\n", current->name);
        current = current->next;
    }
}

void freeMailingList(MailingList *list) {
    Member *current = list->head;
    Member *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    free(list);
}