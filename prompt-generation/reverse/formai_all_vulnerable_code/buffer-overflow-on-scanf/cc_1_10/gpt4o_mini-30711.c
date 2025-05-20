//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: synchronous
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

void initializeList(MailingList *list) {
    list->count = 0;
}

int addSubscriber(MailingList *list, const char *email) {
    if (list->count >= MAX_SUBSCRIBERS) {
        printf("Mailing list is full! Cannot add more subscribers.\n");
        return -1;
    }
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            printf("Email %s is already subscribed.\n", email);
            return -1;
        }
    }
    strcpy(list->subscribers[list->count].email, email);
    list->count++;
    printf("Successfully added %s to the mailing list.\n", email);
    return 0;
}

int removeSubscriber(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            for (int j = i; j < list->count - 1; j++) {
                list->subscribers[j] = list->subscribers[j + 1];
            }
            list->count--;
            printf("Successfully removed %s from the mailing list.\n", email);
            return 0;
        }
    }
    printf("Email %s not found in the mailing list.\n", email);
    return -1;
}

void displaySubscribers(const MailingList *list) {
    if (list->count == 0) {
        printf("No subscribers in the mailing list.\n");
        return;
    }
    printf("Mailing List Subscribers:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s\n", i + 1, list->subscribers[i].email);
    }
}

int main() {
    MailingList list;
    initializeList(&list);
    
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
        getchar();  // clear the newline character from input

        switch (choice) {
            case 1:
                printf("Enter email to subscribe: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0;  // Remove newline character
                addSubscriber(&list, email);
                break;

            case 2:
                printf("Enter email to unsubscribe: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0;  // Remove newline character
                removeSubscriber(&list, email);
                break;

            case 3:
                displaySubscribers(&list);
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}