//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define EMAIL_LENGTH 50

typedef struct {
    char name[50];
    char email[EMAIL_LENGTH];
} Subscriber;

typedef struct {
    Subscriber subscribers[MAX_EMAILS];
    int count;
} MailingList;

void initializeMailingList(MailingList *list) {
    list->count = 0;
}

void addSubscriber(MailingList *list) {
    if (list->count < MAX_EMAILS) {
        Subscriber new_subscriber;
        printf("Enter your name: ");
        fgets(new_subscriber.name, sizeof(new_subscriber.name), stdin);
        new_subscriber.name[strcspn(new_subscriber.name, "\n")] = '\0'; // Remove newline

        printf("Enter your email: ");
        fgets(new_subscriber.email, sizeof(new_subscriber.email), stdin);
        new_subscriber.email[strcspn(new_subscriber.email, "\n")] = '\0'; // Remove newline

        list->subscribers[list->count] = new_subscriber;
        list->count++;
        printf("Subscriber added successfully!\n");
    } else {
        printf("Mailing list is full!\n");
    }
}

void removeSubscriber(MailingList *list) {
    char email[EMAIL_LENGTH];
    printf("Enter the email of the subscriber to remove: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0'; // Remove newline

    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            for (int j = i; j < list->count - 1; j++) {
                list->subscribers[j] = list->subscribers[j + 1];
            }
            list->count--;
            printf("Subscriber removed successfully!\n");
            return;
        }
    }
    printf("Subscriber not found!\n");
}

void displaySubscribers(const MailingList *list) {
    printf("\nCurrent Subscribers:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s - %s\n", i + 1, list->subscribers[i].name, list->subscribers[i].email);
    }
}

void clearMailingList(MailingList *list) {
    list->count = 0;
    printf("All subscribers have been removed from the mailing list!\n");
}

int main() {
    MailingList myList;
    initializeMailingList(&myList);
    
    int choice;
    do {
        printf("\n*** Mailing List Manager ***\n");
        printf("1. Add Subscriber\n");
        printf("2. Remove Subscriber\n");
        printf("3. Display Subscribers\n");
        printf("4. Clear Mailing List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after scanf

        switch (choice) {
            case 1:
                addSubscriber(&myList);
                break;
            case 2:
                removeSubscriber(&myList);
                break;
            case 3:
                displaySubscribers(&myList);
                break;
            case 4:
                clearMailingList(&myList);
                break;
            case 5:
                printf("Exiting the Mailing List Manager. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}