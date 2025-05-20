//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a member of the mailing list
typedef struct Member {
    char email[100];
    struct Member *next;
} Member;

// Structure to represent the mailing list
typedef struct MailingList {
    Member *head;
} MailingList;

// Function prototypes
MailingList* create_list();
void add_member(MailingList *list, const char *email);
void remove_member(MailingList *list, const char *email);
void display_members(const MailingList *list);
void free_list(MailingList *list);

int main() {
    MailingList *list = create_list();
    int choice;
    char email[100];

    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add Member\n");
        printf("2. Remove Member\n");
        printf("3. Display Members\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        
        // Input validation for choice
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                scanf("%s", email);
                add_member(list, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                scanf("%s", email);
                remove_member(list, email);
                break;
            case 3:
                display_members(list);
                break;
            case 4:
                free_list(list);
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Function to create and return a new MailingList
MailingList* create_list() {
    MailingList *list = (MailingList *)malloc(sizeof(MailingList));
    if (!list) {
        perror("Failed to create list");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    return list;
}

// Function to add a member to the mailing list
void add_member(MailingList *list, const char *email) {
    Member *new_member = (Member *)malloc(sizeof(Member));
    if (!new_member) {
        perror("Failed to add member");
        return;
    }
    strncpy(new_member->email, email, sizeof(new_member->email) - 1);
    new_member->email[sizeof(new_member->email) - 1] = '\0'; // Ensure null-termination
    new_member->next = list->head; // Add to the beginning of the list
    list->head = new_member;
    printf("Member added: %s\n", new_member->email);
}

// Function to remove a member from the mailing list
void remove_member(MailingList *list, const char *email) {
    Member *current = list->head;
    Member *previous = NULL;

    while (current != NULL && strcmp(current->email, email) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Email not found: %s\n", email);
        return;
    }

    if (previous == NULL) {
        list->head = current->next; // Removing the head member
    } else {
        previous->next = current->next; // Bypass the current member
    }

    free(current);
    printf("Member removed: %s\n", email);
}

// Function to display all members in the mailing list
void display_members(const MailingList *list) {
    Member *current = list->head;
    if (current == NULL) {
        printf("No members in the mailing list.\n");
        return;
    }
    printf("Mailing List Members:\n");
    while (current != NULL) {
        printf("- %s\n", current->email);
        current = current->next;
    }
}

// Function to free all members in the mailing list
void free_list(MailingList *list) {
    Member *current = list->head;
    while (current != NULL) {
        Member *to_free = current;
        current = current->next;
        free(to_free);
    }
    free(list);
}