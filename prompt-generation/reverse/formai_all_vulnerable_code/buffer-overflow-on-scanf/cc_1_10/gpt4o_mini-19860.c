//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define EMAIL_LENGTH 100

// Struct to hold a subscriber's information
typedef struct {
    char email[EMAIL_LENGTH];
} Subscriber;

// The mailing list manager struct
typedef struct {
    Subscriber subscribers[MAX_SUBSCRIBERS];
    int count;
} MailingListManager;

// Function to initialize the mailing list
void initMailingList(MailingListManager *mlm) {
    mlm->count = 0;
}

// Function to add a subscriber
int addSubscriber(MailingListManager *mlm, const char *email) {
    if (mlm->count >= MAX_SUBSCRIBERS) {
        printf("Mailing list is full!\n");
        return -1;
    }
    // Check for duplicates
    for (int i = 0; i < mlm->count; i++) {
        if (strcmp(mlm->subscribers[i].email, email) == 0) {
            printf("Email already subscribed: %s\n", email);
            return -1;
        }
    }
    // Add new subscriber
    strcpy(mlm->subscribers[mlm->count].email, email);
    printf("Added subscriber: %s\n", email);
    mlm->count++;
    return 0;
}

// Function to remove a subscriber
int removeSubscriber(MailingListManager *mlm, const char *email) {
    int found = 0;
    for (int i = 0; i < mlm->count; i++) {
        if (strcmp(mlm->subscribers[i].email, email) == 0) {
            found = 1;
            // Shift remaining subscribers down
            for (int j = i; j < mlm->count - 1; j++) {
                mlm->subscribers[j] = mlm->subscribers[j + 1];
            }
            mlm->count--;
            printf("Removed subscriber: %s\n", email);
            break;
        }
    }
    if (!found) {
        printf("Email not found: %s\n", email);
        return -1;
    }
    return 0;
}

// Function to display all subscribers
void displaySubscribers(const MailingListManager *mlm) {
    if (mlm->count == 0) {
        printf("No subscribers in the mailing list.\n");
        return;
    }
    printf("Current subscribers:\n");
    for (int i = 0; i < mlm->count; i++) {
        printf("%d: %s\n", i + 1, mlm->subscribers[i].email);
    }
}

// Menu function
void displayMenu() {
    printf("\nMailing List Manager\n");
    printf("1. Add Subscriber\n");
    printf("2. Remove Subscriber\n");
    printf("3. Display Subscribers\n");
    printf("4. Exit\n");
    printf("Select an option (1-4): ");
}

int main() {
    MailingListManager mlm;
    initMailingList(&mlm);
    int choice;
    char email[EMAIL_LENGTH];

    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                scanf("%s", email);
                addSubscriber(&mlm, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                scanf("%s", email);
                removeSubscriber(&mlm, email);
                break;
            case 3:
                displaySubscribers(&mlm);
                break;
            case 4:
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please choose again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}