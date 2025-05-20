//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char email[100];
    struct Node *next;
} Node;

Node *head = NULL;

void addRecipient(const char *email) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strncpy(newNode->email, email, sizeof(newNode->email));
    newNode->next = head;
    head = newNode;
    printf("Added: %s\n", email);
}

void removeRecipient(const char *email) {
    Node *temp = head, *prev = NULL;
    while (temp != NULL && strcmp(temp->email, email) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Email not found: %s\n", email);
        return;
    }
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Removed: %s\n", email);
}

void displayRecipients() {
    Node *current = head;
    if (current == NULL) {
        printf("No recipients in the mailing list.\n");
        return;
    }
    printf("Mailing List Recipients:\n");
    while (current != NULL) {
        printf("- %s\n", current->email);
        current = current->next;
    }
}

void freeList() {
    Node *current = head;
    Node *nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

int main() {
    int choice;
    char email[100];

    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add Recipient\n");
        printf("2. Remove Recipient\n");
        printf("3. Display Recipients\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        if(scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // Clear invalid input
            continue;
        }

        switch (choice) {
        case 1:
            printf("Enter email to add: ");
            scanf("%s", email);
            addRecipient(email);
            break;
        case 2:
            printf("Enter email to remove: ");
            scanf("%s", email);
            removeRecipient(email);
            break;
        case 3:
            displayRecipients();
            break;
        case 4:
            freeList();
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}