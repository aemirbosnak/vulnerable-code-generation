//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: minimalist
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
        printf("Mailing list is full!\n");
        return -1;
    }
    strcpy(list->subscribers[list->count].email, email);
    list->count++;
    printf("Added: %s\n", email);
    return 0;
}

void removeSubscriber(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            list->subscribers[i] = list->subscribers[list->count - 1];
            list->count--;
            printf("Removed: %s\n", email);
            return;
        }
    }
    printf("Email %s not found in mailing list.\n", email);
}

void displaySubscribers(MailingList *list) {
    if (list->count == 0) {
        printf("No subscribers in the mailing list.\n");
        return;
    }
    printf("Mailing List Subscribers:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s\n", i + 1, list->subscribers[i].email);
    }
}

int searchSubscriber(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            return i;
        }
    }
    return -1;
}

void clearList(MailingList *list) {
    list->count = 0;
    printf("Mailing list cleared.\n");
}

void displayMenu() {
    printf("\nMailing List Manager\n");
    printf("1. Add Subscriber\n");
    printf("2. Remove Subscriber\n");
    printf("3. Display Subscribers\n");
    printf("4. Clear List\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    MailingList list;
    initializeList(&list);
    int option;
    char email[EMAIL_LENGTH];

    while (1) {
        displayMenu();
        scanf("%d", &option);
        getchar();  // Clear newline from input buffer

        switch (option) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0;  // Remove newline
                addSubscriber(&list, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0;  // Remove newline
                removeSubscriber(&list, email);
                break;
            case 3:
                displaySubscribers(&list);
                break;
            case 4:
                clearList(&list);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}