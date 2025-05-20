//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold subscriber information
typedef struct Subscriber {
    char email[256];
    struct Subscriber *next;
} Subscriber;

// Function prototypes
void addSubscriber(Subscriber **head, const char *email);
void removeSubscriber(Subscriber **head, const char *email);
void displaySubscribers(Subscriber *head);
void freeList(Subscriber *head);

int main() {
    Subscriber *head = NULL;
    int choice;
    char email[256];

    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add Subscriber\n");
        printf("2. Remove Subscriber\n");
        printf("3. Display Subscribers\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0; // trim newline
                addSubscriber(&head, email);
                printf("Added: %s\n", email);
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0; // trim newline
                removeSubscriber(&head, email);
                printf("Removed: %s\n", email);
                break;
            case 3:
                printf("Current Subscribers:\n");
                displaySubscribers(head);
                break;
            case 4:
                freeList(head);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void addSubscriber(Subscriber **head, const char *email) {
    Subscriber *newSubscriber = (Subscriber *)malloc(sizeof(Subscriber));
    if (!newSubscriber) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newSubscriber->email, email);
    newSubscriber->next = *head;
    *head = newSubscriber;
}

void removeSubscriber(Subscriber **head, const char *email) {
    Subscriber *current = *head;
    Subscriber *previous = NULL;

    while (current != NULL && strcmp(current->email, email) != 0) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Subscriber not found: %s\n", email);
        return;
    }
    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
}

void displaySubscribers(Subscriber *head) {
    Subscriber *current = head;
    if (current == NULL) {
        printf("No subscribers found.\n");
        return;
    }
    while (current != NULL) {
        printf("- %s\n", current->email);
        current = current->next;
    }
}

void freeList(Subscriber *head) {
    Subscriber *current = head;
    Subscriber *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}