//FormAI DATASET v1.0 Category: Mailing list manager ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char email[50];
    struct node* next;
} Node;

// Function to display the mailing list
void display(Node* head) {
    if (head == NULL) {
        printf("Mailing list is empty.\n");
        return;
    }
    Node* curr = head;
    printf("Mailing list:\n");
    while (curr != NULL) {
        printf("%s, ", curr->email);
        curr = curr->next;
    }
    printf("\n");
}

// Function to add an email to the mailing list
void addEmail(Node** head, char* email) {
    Node* newEmail = malloc(sizeof(Node));
    strcpy(newEmail->email, email);
    newEmail->next = NULL;
    if (*head == NULL) { // Empty list
        *head = newEmail;
        printf("New email added.\n");
        return;
    }
    Node* curr = *head;
    while (curr->next != NULL) {
        if (strcmp(curr->email, email) == 0) { // Email already in the list
            printf("Email already exists in the mailing list.\n");
            free(newEmail);
            return;
        }
        curr = curr->next;
    }
    if (strcmp(curr->email, email) == 0) { // Email already in the list
        printf("Email already exists in the mailing list.\n");
        free(newEmail);
        return;
    }
    curr->next = newEmail;
    printf("New email added.\n");
}

// Function to remove an email from the mailing list
void removeEmail(Node** head, char* email) {
    if (*head == NULL) { // Empty list
        printf("Mailing list is empty.\n");
        return;
    }
    Node* prev = NULL;
    Node* curr = *head;
    while (curr != NULL) {
        if (strcmp(curr->email, email) == 0) { // Email found
            if (prev == NULL) { // First node in list
                *head = curr->next;
            } else {
                prev->next = curr->next;
            }
            printf("Email removed from the mailing list.\n");
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Email not found in the mailing list.\n");
}

int main() {
    Node* head = NULL;
    int choice;
    char email[50];
    while (1) {
        printf("\n------------------------\n");
        printf("Mailing List Management\n");
        printf("------------------------\n");
        printf("1. Display Mailing List\n");
        printf("2. Add Email\n");
        printf("3. Remove Email\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display(head);
                break;
            case 2:
                printf("Enter email to add: ");
                scanf("%s", email);
                addEmail(&head, email);
                break;
            case 3:
                printf("Enter email to remove: ");
                scanf("%s", email);
                removeEmail(&head, email);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}