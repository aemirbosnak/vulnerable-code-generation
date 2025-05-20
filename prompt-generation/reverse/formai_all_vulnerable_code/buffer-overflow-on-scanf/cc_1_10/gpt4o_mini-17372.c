//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: unmistakable
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

void initializeList(MailingList *list) {
    list->count = 0;
}

int addSubscriber(MailingList *list, const char *email) {
    if (list->count >= MAX_SUBSCRIBERS) {
        printf("Mailing list is full, cannot add more subscribers.\n");
        return -1;
    }
    strncpy(list->subscribers[list->count].email, email, EMAIL_LENGTH);
    list->count++;
    printf("Added: %s\n", email);
    return 0;
}

int removeSubscriber(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            list->subscribers[i] = list->subscribers[list->count - 1];
            list->count--;
            printf("Removed: %s\n", email);
            return 0;
        }
    }
    printf("Email %s not found in the list.\n", email);
    return -1;
}

void listSubscribers(const MailingList *list) {
    printf("Current Subscribers (%d):\n", list->count);
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s\n", i + 1, list->subscribers[i].email);
    }
}

int isEmailValid(const char *email) {
    // A simple check for an "@" and a "."
    if (strchr(email, '@') && strchr(email, '.')) {
        return 1;
    }
    return 0;
}

void displayMenu() {
    printf("\nMailing List Manager\n");
    printf("1. Add Subscriber\n");
    printf("2. Remove Subscriber\n");
    printf("3. List Subscribers\n");
    printf("4. Exit\n");
}

int main() {
    MailingList list;
    initializeList(&list);

    int choice;
    char email[EMAIL_LENGTH];

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                scanf("%s", email);
                if (isEmailValid(email)) {
                    addSubscriber(&list, email);
                } else {
                    printf("Invalid email format. Try again.\n");
                }
                break;
            case 2:
                printf("Enter email to remove: ");
                scanf("%s", email);
                removeSubscriber(&list, email);
                break;
            case 3:
                listSubscribers(&list);
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please select a correct option.\n");
                break;
        }
    }

    return 0;
}