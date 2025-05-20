//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
} Subscriber;

typedef struct {
    Subscriber subscribers[MAX_SUBSCRIBERS];
    int count;
} MailingList;

void initMailingList(MailingList* list) {
    list->count = 0;
}

void addSubscriber(MailingList* list) {
    if (list->count >= MAX_SUBSCRIBERS) {
        printf("Mailing list is full!\n");
        return;
    }
    
    printf("Enter name to add: ");
    scanf(" %[^\n]%*c", list->subscribers[list->count].name);
    list->count++;
    printf("Subscriber added successfully!\n");
}

void removeSubscriber(MailingList* list) {
    char name[NAME_LENGTH];
    
    printf("Enter name to remove: ");
    scanf(" %[^\n]%*c", name);
    
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].name, name) == 0) {
            list->subscribers[i] = list->subscribers[list->count - 1]; // Move last to the removed spot
            list->count--;
            printf("Subscriber removed successfully!\n");
            return;
        }
    }
    
    printf("Subscriber not found!\n");
}

void viewSubscribers(const MailingList* list) {
    if (list->count == 0) {
        printf("No subscribers in the mailing list.\n");
        return;
    }
    
    printf("Current Subscribers:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s\n", i + 1, list->subscribers[i].name);
    }
}

void displayMenu() {
    printf("\nMailing List Manager\n");
    printf("1. Add Subscriber\n");
    printf("2. Remove Subscriber\n");
    printf("3. View Subscribers\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    MailingList mailingList;
    initMailingList(&mailingList);
    
    while (1) {
        displayMenu();
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addSubscriber(&mailingList);
                break;
            case 2:
                removeSubscriber(&mailingList);
                break;
            case 3:
                viewSubscribers(&mailingList);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}