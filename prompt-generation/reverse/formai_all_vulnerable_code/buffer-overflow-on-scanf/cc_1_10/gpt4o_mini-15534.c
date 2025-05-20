//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char email[NAME_LENGTH];
} Subscriber;

typedef struct {
    Subscriber subscribers[MAX_SUBSCRIBERS];
    int count;
} MailingList;

// Function declarations
void addSubscriber(MailingList *list);
void removeSubscriber(MailingList *list);
void viewSubscribers(const MailingList *list);
void clearInputBuffer();

int main() {
    MailingList mailingList;
    mailingList.count = 0;
    int choice;

    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add Subscriber\n");
        printf("2. Remove Subscriber\n");
        printf("3. View Subscribers\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        
        scanf("%d", &choice);
        clearInputBuffer(); // Clear the input buffer before reading a string

        switch (choice) {
            case 1:
                if (mailingList.count < MAX_SUBSCRIBERS) {
                    addSubscriber(&mailingList);
                } else {
                    printf("Subscriber limit reached!\n");
                }
                break;
            case 2:
                removeSubscriber(&mailingList);
                break;
            case 3:
                viewSubscribers(&mailingList);
                break; 
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addSubscriber(MailingList *list) {
    Subscriber newSubscriber;
    
    printf("Enter subscriber name: ");
    fgets(newSubscriber.name, NAME_LENGTH, stdin);
    newSubscriber.name[strcspn(newSubscriber.name, "\n")] = '\0'; // Remove newline

    printf("Enter subscriber email: ");
    fgets(newSubscriber.email, NAME_LENGTH, stdin);
    newSubscriber.email[strcspn(newSubscriber.email, "\n")] = '\0'; // Remove newline

    list->subscribers[list->count] = newSubscriber;
    list->count++;
    printf("Subscriber added successfully.\n");
}

void removeSubscriber(MailingList *list) {
    if (list->count == 0) {
        printf("No subscribers to remove.\n");
        return;
    }

    char email[NAME_LENGTH];
    printf("Enter the email of the subscriber to remove: ");
    fgets(email, NAME_LENGTH, stdin);
    email[strcspn(email, "\n")] = '\0'; // Remove newline

    int found = 0;
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            // Move the last subscriber to the current index to "remove" the subscriber
            list->subscribers[i] = list->subscribers[list->count - 1];
            list->count--;
            found = 1;
            printf("Subscriber removed successfully.\n");
            break;
        }
    }
    
    if (!found) {
        printf("Subscriber with email %s not found.\n", email);
    }
}

void viewSubscribers(const MailingList *list) {
    if (list->count == 0) {
        printf("No subscribers in the mailing list.\n");
        return;
    }

    printf("\nCurrent Subscribers:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s (%s)\n", i + 1, list->subscribers[i].name, list->subscribers[i].email);
    }
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}