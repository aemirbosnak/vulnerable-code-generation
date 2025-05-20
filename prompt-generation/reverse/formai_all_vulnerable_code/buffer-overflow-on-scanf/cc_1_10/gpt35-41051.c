//FormAI DATASET v1.0 Category: Mailing list manager ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct EmailNode {
    char email[50];
    struct EmailNode* next;
};

void addEmailToList(struct EmailNode** head, char email[]) {
    struct EmailNode* newEmail = (struct EmailNode*) malloc(sizeof(struct EmailNode));
    
    strcpy(newEmail->email, email);

    if (*head == NULL) {
        // If the list is empty, make the new email the head
        newEmail->next = NULL;
        *head = newEmail;
        printf("Email added to the list.\n");
    } else {
        // Traverse the list to find the end
        struct EmailNode* current = *head;

        while (current->next != NULL) {
            if (strcmp(current->email, email) == 0) {
                // Email already exists in the list
                printf("Email already exists in the list.\n");
                free(newEmail);
                return;
            }
            current = current->next;
        }

        if (strcmp(current->email, email) == 0) {
            // Email already exists in the list
            printf("Email already exists in the list.\n");
            free(newEmail);
            return;
        }

        // Add the new email to the end of the list
        newEmail->next = NULL;
        current->next = newEmail;
        printf("Email added to the list.\n");
    }
}

void deleteEmailFromList(struct EmailNode** head, char email[]) {
    if (*head == NULL) {
        // If the list is empty, there's nothing to delete
        printf("Email list is empty.\n");
    } else {
        struct EmailNode* current = *head;
        struct EmailNode* previous = NULL;

        while (current != NULL) {
            if (strcmp(current->email, email) == 0) {
                if (previous == NULL) {
                    // If we're deleting the head of the list
                    *head = current->next;
                    free(current);
                    printf("Email deleted from the list.\n");
                    return;
                } else {
                    // If we're deleting a node that's not the head
                    previous->next = current->next;
                    free(current);
                    printf("Email deleted from the list.\n");
                    return;
                }
            }
            previous = current;
            current = current->next;
        }

        // If we've reached the end and haven't found the email, it's not in the list
        printf("Email not found in the list.\n");
    }
}

void printEmailList(struct EmailNode** head) {
    if (*head == NULL) {
        // If the list is empty, there's nothing to print
        printf("Email list is empty.\n");
    } else {
        struct EmailNode* current = *head;

        while (current != NULL) {
            printf("%s\n", current->email);
            current = current->next;
        }
    }
}

int main() {
    struct EmailNode* head = NULL;

    printf("Welcome to the mailing list manager!\n");

    while (1) {
        printf("What would you like to do?\n");
        printf("1. Add an email to the list\n");
        printf("2. Delete an email from the list\n");
        printf("3. Print the email list\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter the email you want to add: ");
                char email[50];
                scanf("%s", email);
                addEmailToList(&head, email);
                break;
            }
            case 2: {
                printf("Enter the email you want to delete: ");
                char email[50];
                scanf("%s", email);
                deleteEmailFromList(&head, email);
                break;
            }
            case 3: {
                printf("Email list:\n");
                printEmailList(&head);
                break;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }

        printf("\n");
    }

    return 0;
}