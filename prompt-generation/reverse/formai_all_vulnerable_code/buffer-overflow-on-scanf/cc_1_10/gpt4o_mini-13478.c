//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define EMAIL_LENGTH 50

typedef struct {
    char email[EMAIL_LENGTH];
} Subscriber;

typedef struct {
    Subscriber subscribers[MAX_SUBSCRIBERS];
    int count;
} MailingList;

// Function to initialize the mailing list
void initMailingList(MailingList* list) {
    list->count = 0;
}

// Function to print the mailing list
void displaySubscribers(MailingList* list) {
    if (list->count == 0) {
        printf("No subscribers in the mailing list.\n");
    } else {
        printf("Current Subscribers:\n");
        for (int i = 0; i < list->count; i++) {
            printf("%d: %s\n", i + 1, list->subscribers[i].email);
        }
    }
}

// Function to add a subscriber
int addSubscriber(MailingList* list, const char* email) {
    if (list->count >= MAX_SUBSCRIBERS) {
        printf("Mailing list is full! Cannot add more subscribers.\n");
        return -1;
    }
    strncpy(list->subscribers[list->count].email, email, EMAIL_LENGTH);
    list->count++;
    printf("Added subscriber: %s\n", email);
    return 0;
}

// Function to remove a subscriber
int removeSubscriber(MailingList* list, const char* email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            for (int j = i; j < list->count - 1; j++) {
                list->subscribers[j] = list->subscribers[j + 1];
            }
            list->count--;
            printf("Removed subscriber: %s\n", email);
            return 0;
        }
    }
    printf("Email not found: %s\n", email);
    return -1;
}

// Function to prompt user input
void promptUserInput(MailingList* list) {
    int choice;
    char email[EMAIL_LENGTH];
    do {
        printf("\nMailing List Manager\n");
        printf("1. Add Subscriber\n");
        printf("2. Remove Subscriber\n");
        printf("3. Display Subscribers\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume newline after number input

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline character
                if (strlen(email) > 0) {
                    addSubscriber(list, email);
                }
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline character
                if (strlen(email) > 0) {
                    removeSubscriber(list, email);
                }
                break;
            case 3:
                displaySubscribers(list);
                break;
            case 4:
                printf("Exiting the Mailing List Manager.\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }
    } while (choice != 4);
}

int main() {
    MailingList list;
    initMailingList(&list);
    promptUserInput(&list);
    return 0;
}