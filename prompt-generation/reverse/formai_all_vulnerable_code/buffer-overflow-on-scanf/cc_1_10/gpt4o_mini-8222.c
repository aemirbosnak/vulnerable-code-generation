//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store each member of the mailing list
typedef struct Member {
    char email[100];
    struct Member* next;
} Member;

// Structure to represent a mailing list
typedef struct MailingList {
    Member* head;
} MailingList;

// Function prototypes
MailingList* createMailingList();
void addMember(MailingList* list, const char* email);
void removeMember(MailingList* list, const char* email);
void displayMembers(MailingList* list);
void freeMailingList(MailingList* list);
int isMember(MailingList* list, const char* email);

int main() {
    MailingList* list = createMailingList();
    int choice;
    char email[100];

    printf("Welcome to the Mailing List Manager!\n");
    
    do {
        printf("\nMenu:\n");
        printf("1. Add Member\n");
        printf("2. Remove Member\n");
        printf("3. Display Members\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear the newline buffer

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, 100, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline character
                addMember(list, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, 100, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline character
                removeMember(list, email);
                break;
            case 3:
                displayMembers(list);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

    freeMailingList(list);
    return 0;
}

// Function to create a new mailing list
MailingList* createMailingList() {
    MailingList* list = (MailingList*)malloc(sizeof(MailingList));
    list->head = NULL; // Initialize with no members
    return list;
}

// Function to add a new member to the mailing list
void addMember(MailingList* list, const char* email) {
    if (isMember(list, email)) {
        printf("Email %s already in the mailing list!\n", email);
        return;
    }

    Member* newMember = (Member*)malloc(sizeof(Member));
    strcpy(newMember->email, email);
    newMember->next = list->head;
    list->head = newMember;

    printf("Email %s added to the mailing list.\n", email);
}

// Function to remove a member from the mailing list
void removeMember(MailingList* list, const char* email) {
    Member* current = list->head;
    Member* previous = NULL;

    while (current != NULL && strcmp(current->email, email) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Email %s not found in the mailing list.\n", email);
        return;
    }

    if (previous == NULL) {
        list->head = current->next; // The member to be removed is the head
    } else {
        previous->next = current->next;
    }

    free(current);
    printf("Email %s removed from the mailing list.\n", email);
}

// Function to display all members of the mailing list
void displayMembers(MailingList* list) {
    Member* current = list->head;
    if (current == NULL) {
        printf("The mailing list is empty.\n");
        return;
    }

    printf("Mailing List Members:\n");
    while (current != NULL) {
        printf("- %s\n", current->email);
        current = current->next;
    }
}

// Helper function to check if an email is already in the mailing list
int isMember(MailingList* list, const char* email) {
    Member* current = list->head;
    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// Function to free all members of the mailing list
void freeMailingList(MailingList* list) {
    Member* current = list->head;
    Member* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}