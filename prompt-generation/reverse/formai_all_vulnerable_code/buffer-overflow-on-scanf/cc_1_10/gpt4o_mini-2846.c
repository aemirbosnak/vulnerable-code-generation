//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define EMAIL_LENGTH 50

// Struct representing an email subscriber
typedef struct {
    char email[EMAIL_LENGTH];
} Subscriber;

// A mailing list manager structure
typedef struct {
    Subscriber subscribers[MAX_SUBSCRIBERS];
    int count;
} MailingListManager;

// Function prototypes
void initialize(MailingListManager *mlm);
void addSubscriber(MailingListManager *mlm, const char *email);
void removeSubscriber(MailingListManager *mlm, const char *email);
void listSubscribers(MailingListManager *mlm);
int isEmailPresent(MailingListManager *mlm, const char *email);
void handleUserInput(MailingListManager *mlm);

int main() {
    MailingListManager mlm;
    initialize(&mlm);
    handleUserInput(&mlm);
    return 0;
}

// Initialize the mailing list manager
void initialize(MailingListManager *mlm) {
    mlm->count = 0;
    printf("Welcome to the Mailing List Manager! Prepare for a wild ride...\n");
}

// Check if an email is present in the mailing list
int isEmailPresent(MailingListManager *mlm, const char *email) {
    for (int i = 0; i < mlm->count; i++) {
        if (strcmp(mlm->subscribers[i].email, email) == 0) {
            return 1; // Found
        }
    }
    return 0; // Not found
}

// Add a subscriber to the mailing list
void addSubscriber(MailingListManager *mlm, const char *email) {
    if (mlm->count >= MAX_SUBSCRIBERS) {
        printf("Oh no! The mailing list is full! Can't add more subscribers!\n");
        return;
    }
    if (isEmailPresent(mlm, email)) {
        printf("Uh-oh! This email (%s) is already subscribed!\n", email);
        return;
    }
    strcpy(mlm->subscribers[mlm->count].email, email);
    mlm->count++;
    printf("Success! %s has been added to the list!\n", email);
}

// Remove a subscriber from the mailing list
void removeSubscriber(MailingListManager *mlm, const char *email) {
    int found = 0;
    for (int i = 0; i < mlm->count; i++) {
        if (strcmp(mlm->subscribers[i].email, email) == 0) {
            found = 1;
            for (int j = i; j < mlm->count - 1; j++) {
                mlm->subscribers[j] = mlm->subscribers[j + 1]; // Shift subscribers left
            }
            mlm->count--;
            printf("Whoops! %s has been removed from the list!\n", email);
            break;
        }
    }
    if (!found) {
        printf("Yikes! No such email (%s) found to remove!\n", email);
    }
}

// List all subscribers in the mailing list
void listSubscribers(MailingListManager *mlm) {
    if (mlm->count == 0) {
        printf("Whoa! No subscribers in the list yet! It's empty!\n");
        return;
    }
    printf("Here are the current subscribers:\n");
    for (int i = 0; i < mlm->count; i++) {
        printf("%d: %s\n", i + 1, mlm->subscribers[i].email);
    }
}

// Handle user input for managing the mailing list
void handleUserInput(MailingListManager *mlm) {
    char command[10], email[EMAIL_LENGTH];
    while (1) {
        printf("\nEnter command (add/remove/list/exit): ");
        scanf("%s", command);
        
        if (strcmp(command, "add") == 0) {
            printf("Enter email to add: ");
            scanf("%s", email);
            addSubscriber(mlm, email);
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter email to remove: ");
            scanf("%s", email);
            removeSubscriber(mlm, email);
        } else if (strcmp(command, "list") == 0) {
            listSubscribers(mlm);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the Mailing List Manager. See you next time!\n");
            break;
        } else {
            printf("Oops! Invalid command! Try again...\n");
        }
    }
}