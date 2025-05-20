//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a subscriber
typedef struct Subscriber {
    char email[100];
    struct Subscriber *next;
} Subscriber;

// Function prototypes
Subscriber *addSubscriber(Subscriber *head, const char *email);
Subscriber *removeSubscriber(Subscriber *head, const char *email);
void displaySubscribers(Subscriber *head);
void freeList(Subscriber *head);
void menu();

// Main function
int main() {
    Subscriber *head = NULL;
    int choice;
    char email[100];

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                scanf("%s", email);
                head = addSubscriber(head, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                scanf("%s", email);
                head = removeSubscriber(head, email);
                break;
            case 3:
                displaySubscribers(head);
                break;
            case 4:
                freeList(head);
                printf("Exiting the program!\n");
                exit(0);
            default:
                printf("Invalid Option! Please try again.\n");
        }
    }

    return 0;
}

// Function to display the menu
void menu() {
    printf("\n--- Mailing List Manager ---\n");
    printf("1. Add Subscriber\n");
    printf("2. Remove Subscriber\n");
    printf("3. Display Subscribers\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

// Function to add a subscriber
Subscriber *addSubscriber(Subscriber *head, const char *email) {
    Subscriber *newSubscriber = (Subscriber *)malloc(sizeof(Subscriber));
    if (!newSubscriber) {
        printf("Memory allocation failed!\n");
        return head;
    }
    strcpy(newSubscriber->email, email);
    newSubscriber->next = NULL;

    if (head == NULL) {
        return newSubscriber;
    }

    Subscriber *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newSubscriber;
    return head;
}

// Function to remove a subscriber
Subscriber *removeSubscriber(Subscriber *head, const char *email) {
    if (head == NULL) {
        printf("The mailing list is empty!\n");
        return NULL;
    }

    Subscriber *current = head;
    Subscriber *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (previous == NULL) {
                Subscriber *temp = head;
                head = head->next;
                free(temp);
            } else {
                previous->next = current->next;
                free(current);
            }
            printf("Subscriber %s removed!\n", email);
            return head;
        }
        previous = current;
        current = current->next;
    }
    printf("Subscriber %s not found!\n", email);
    return head;
}

// Function to display subscribers
void displaySubscribers(Subscriber *head) {
    if (head == NULL) {
        printf("No subscribers found!\n");
        return;
    }
    printf("Current Subscribers:\n");
    Subscriber *current = head;
    while (current != NULL) {
        printf("- %s\n", current->email);
        current = current->next;
    }
}

// Function to free the linked list
void freeList(Subscriber *head) {
    Subscriber *current = head;
    while (current != NULL) {
        Subscriber *temp = current;
        current = current->next;
        free(temp);
    }
}