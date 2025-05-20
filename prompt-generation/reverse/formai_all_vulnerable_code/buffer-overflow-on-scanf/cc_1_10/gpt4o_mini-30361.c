//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: inquisitive
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
        printf("Mailing list is full. Cannot add more subscribers.\n");
        return -1;
    }
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            printf("Email %s is already subscribed.\n", email);
            return -1;
        }
    }
    strncpy(list->subscribers[list->count].email, email, EMAIL_LENGTH);
    list->count++;
    printf("Email %s added successfully.\n", email);
    return 0;
}

int removeSubscriber(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            // Shift remaining subscribers left
            for (int j = i; j < list->count - 1; j++) {
                list->subscribers[j] = list->subscribers[j + 1];
            }
            list->count--;
            printf("Email %s removed successfully.\n", email);
            return 0;
        }
    }
    printf("Email %s not found in the mailing list.\n", email);
    return -1;
}

void listSubscribers(MailingList *list) {
    if (list->count == 0) {
        printf("No subscribers found in mailing list.\n");
        return;
    }
    printf("Current Subscribers:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s\n", i + 1, list->subscribers[i].email);
    }
}

void displayMenu() {
    printf("\nMailing List Manager\n");
    printf("1. Add Subscriber\n");
    printf("2. Remove Subscriber\n");
    printf("3. List Subscribers\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    MailingList list;
    initializeList(&list);
    int choice;
    char email[EMAIL_LENGTH];

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Consume newline character after scanf

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove trailing newline
                addSubscriber(&list, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove trailing newline
                removeSubscriber(&list, email);
                break;
            case 3:
                listSubscribers(&list);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}