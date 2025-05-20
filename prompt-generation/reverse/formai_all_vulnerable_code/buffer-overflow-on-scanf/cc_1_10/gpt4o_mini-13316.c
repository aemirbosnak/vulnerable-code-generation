//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define EMAIL_LENGTH 100

typedef struct {
    char email[EMAIL_LENGTH];
} Subscriber;

typedef struct {
    Subscriber subscribers[MAX_SUBSCRIBERS];
    int count;
} MailingList;

void add_subscriber(MailingList *list, const char *email) {
    if (list->count >= MAX_SUBSCRIBERS) {
        printf("Sorry, the mailing list is full.\n");
        return;
    }
    
    // Prevent duplicate subscriptions
    for (int i = 0; i < list->count; ++i) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            printf("Email %s is already subscribed.\n", email);
            return;
        }
    }

    strcpy(list->subscribers[list->count].email, email);
    list->count++;
    printf("Successfully added %s to the mailing list!\n", email);
}

void remove_subscriber(MailingList *list, const char *email) {
    int found = 0;

    for (int i = 0; i < list->count; ++i) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            found = 1;
            printf("Removing %s from the mailing list...\n", email);
            // Shift all subsequent subscribers up one position
            for (int j = i; j < list->count - 1; ++j) {
                list->subscribers[j] = list->subscribers[j + 1];
            }
            list->count--;
            break;
        }
    }

    if (!found) {
        printf("Email %s not found in the mailing list.\n", email);
    } else {
        printf("Successfully removed %s from the mailing list!\n", email);
    }
}

void display_subscribers(const MailingList *list) {
    if (list->count == 0) {
        printf("The mailing list is empty.\n");
        return;
    }
    
    printf("Current subscribers:\n");
    for (int i = 0; i < list->count; ++i) {
        printf("%d: %s\n", i + 1, list->subscribers[i].email);
    }
}

int main() {
    MailingList myList;
    myList.count = 0;

    int choice;
    char email[EMAIL_LENGTH];

    do {
        printf("\n--- Mailing List Manager ---\n");
        printf("1. Add Subscriber\n");
        printf("2. Remove Subscriber\n");
        printf("3. Display Subscribers\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to remove newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter email to subscribe: ");
                fgets(email, EMAIL_LENGTH, stdin);
                // Remove newline character from fgets
                email[strcspn(email, "\n")] = 0;
                add_subscriber(&myList, email);
                break;
                
            case 2:
                printf("Enter email to remove: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0;
                remove_subscriber(&myList, email);
                break;
                
            case 3:
                display_subscribers(&myList);
                break;
                
            case 4:
                printf("Exiting the program. Happy mailing!\n");
                break;
                
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}