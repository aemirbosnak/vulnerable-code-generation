//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Subscriber {
    char email[100];
    struct Subscriber* next;
} Subscriber;

Subscriber* head = NULL;

void subscribe();
void unsubscribe();
void viewList();
void clearBuffer();

int main() {
    int choice;

    do {
        printf("\n=== Mailing List Manager ===\n");
        printf("1. Subscribe\n");
        printf("2. Unsubscribe\n");
        printf("3. View Mailing List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                subscribe();
                break;
            case 2:
                unsubscribe();
                break;
            case 3:
                viewList();
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void subscribe() {
    Subscriber* newSubscriber = (Subscriber*)malloc(sizeof(Subscriber));
    if (newSubscriber == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter your email to subscribe: ");
    fgets(newSubscriber->email, sizeof(newSubscriber->email), stdin);
    newSubscriber->email[strcspn(newSubscriber->email, "\n")] = '\0'; // Remove newline character
    newSubscriber->next = head;
    head = newSubscriber;

    printf("Successfully subscribed: %s\n", newSubscriber->email);
}

void unsubscribe() {
    char email[100];
    printf("Enter your email to unsubscribe: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0'; // Remove newline character

    Subscriber* current = head;
    Subscriber* previous = NULL;

    while (current != NULL && strcmp(current->email, email) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Email not found in the mailing list.\n");
        return;
    }

    if (previous == NULL) {
        head = current->next; // Unsubscribing the head
    } else {
        previous->next = current->next; // Unlinking the subscriber
    }

    free(current);
    printf("Successfully unsubscribed: %s\n", email);
}

void viewList() {
    if (head == NULL) {
        printf("The mailing list is currently empty.\n");
        return;
    }

    printf("Current Mailing List:\n");
    Subscriber* current = head;
    while (current != NULL) {
        printf(" - %s\n", current->email);
        current = current->next;
    }
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {} // Clear the input buffer
}