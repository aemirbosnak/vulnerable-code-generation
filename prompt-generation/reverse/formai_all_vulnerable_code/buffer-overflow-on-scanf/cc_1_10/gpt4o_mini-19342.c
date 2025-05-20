//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50

// Structure for a subscriber
typedef struct Subscriber {
    char name[NAME_LENGTH];
    struct Subscriber* next;
} Subscriber;

// Structure for the mailing list
typedef struct MailingList {
    Subscriber* head;
} MailingList;

// Function to create a new mailing list
MailingList* createMailingList() {
    MailingList* list = (MailingList*) malloc(sizeof(MailingList));
    list->head = NULL;
    return list;
}

// Function to create a new subscriber
Subscriber* createSubscriber(const char* name) {
    Subscriber* newSubscriber = (Subscriber*) malloc(sizeof(Subscriber));
    strncpy(newSubscriber->name, name, NAME_LENGTH);
    newSubscriber->next = NULL;
    return newSubscriber;
}

// Function to add a subscriber to the mailing list
void addSubscriber(MailingList* list, const char* name) {
    Subscriber* newSubscriber = createSubscriber(name);
    newSubscriber->next = list->head;
    list->head = newSubscriber;
    printf("Subscriber '%s' added to the mailing list.\n", name);
}

// Function to remove a subscriber from the mailing list
void removeSubscriber(MailingList* list, const char* name) {
    Subscriber* current = list->head;
    Subscriber* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                list->head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Subscriber '%s' removed from the mailing list.\n", name);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Subscriber '%s' not found in the mailing list.\n", name);
}

// Function to display subscribers of the mailing list
void displaySubscribers(MailingList* list) {
    Subscriber* current = list->head;
    if (current == NULL) {
        printf("The mailing list is empty.\n");
        return;
    }
    printf("Current subscribers in the mailing list:\n");
    while (current != NULL) {
        printf("- %s\n", current->name);
        current = current->next;
    }
}

// Function to free the mailing list
void freeMailingList(MailingList* list) {
    Subscriber* current = list->head;
    Subscriber* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

// Main function to demonstrate the mailing list manager
int main() {
    MailingList* list = createMailingList();
    char name[NAME_LENGTH];
    int choice;

    do {
        printf("\nMailing List Manager\n");
        printf("1. Add Subscriber\n");
        printf("2. Remove Subscriber\n");
        printf("3. Display Subscribers\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name of the subscriber to add: ");
                scanf("%s", name);
                addSubscriber(list, name);
                break;
            case 2:
                printf("Enter name of the subscriber to remove: ");
                scanf("%s", name);
                removeSubscriber(list, name);
                break;
            case 3:
                displaySubscribers(list);
                break;
            case 4:
                printf("Exiting the Mailing List Manager.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    freeMailingList(list);
    return 0;
}