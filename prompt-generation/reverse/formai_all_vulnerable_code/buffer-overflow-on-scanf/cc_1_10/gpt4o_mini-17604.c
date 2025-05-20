//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for member nodes in the mailing list
typedef struct Member {
    char email[100];
    struct Member* next;
} Member;

// Function to create a new member
Member* createMember(const char* email) {
    Member* newMember = (Member*)malloc(sizeof(Member));
    if (newMember == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newMember->email, email, 100);
    newMember->next = NULL;
    return newMember;
}

// Function to add a member to the mailing list
void addMember(Member** head, const char* email) {
    Member* newMember = createMember(email);
    newMember->next = *head;
    *head = newMember;
    printf("Added: %s\n", email);
}

// Function to remove a member from the mailing list
void removeMember(Member** head, const char* email) {
    Member* current = *head;
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
        *head = current->next; // Removing head
    } else {
        previous->next = current->next; // Bypass the current
    }
    free(current);
    printf("Removed: %s\n", email);
}

// Function to display all members in the mailing list
void displayMembers(const Member* head) {
    const Member* current = head;
    printf("Current Mailing List Members:\n");
    while (current != NULL) {
        printf(" - %s\n", current->email);
        current = current->next;
    }
}

// Function to free the mailing list
void freeMembers(Member* head) {
    Member* current = head;
    while (current != NULL) {
        Member* next = current->next;
        free(current);
        current = next;
    }
}

// Main function to manage the mailing list
int main() {
    Member* mailingList = NULL;
    int choice;
    char email[100];

    printf("Welcome to the Mailing List Manager!\n");
    do {
        printf("\nMenu:\n");
        printf("1. Add Member\n");
        printf("2. Remove Member\n");
        printf("3. Display Members\n");
        printf("4. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character after scanf

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline character
                addMember(&mailingList, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline character
                removeMember(&mailingList, email);
                break;
            case 3:
                displayMembers(mailingList);
                break;
            case 4:
                printf("Exiting the Mailing List Manager. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    freeMembers(mailingList);
    return 0;
}