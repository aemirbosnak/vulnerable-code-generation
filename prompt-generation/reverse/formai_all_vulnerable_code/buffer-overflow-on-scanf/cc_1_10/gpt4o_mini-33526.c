//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
} Subscriber;

typedef struct {
    Subscriber subscribers[MAX_SUBSCRIBERS];
    int count;
} MailingList;

void initializeMailingList(MailingList *list) {
    list->count = 0;
}

void addSubscriber(MailingList *list, const char *name, const char *email) {
    if (list->count >= MAX_SUBSCRIBERS) {
        printf("Mailing list is full! Cannot add more subscribers.\n");
        return;
    }
    strncpy(list->subscribers[list->count].name, name, MAX_NAME_LENGTH);
    strncpy(list->subscribers[list->count].email, email, MAX_NAME_LENGTH);
    list->count++;
    printf("Subscriber added: %s (%s)\n", name, email);
}

void removeSubscriber(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            printf("Removing subscriber: %s (%s)\n", list->subscribers[i].name, email);
            for (int j = i; j < list->count - 1; j++) {
                list->subscribers[j] = list->subscribers[j + 1];
            }
            list->count--;
            return;
        }
    }
    printf("Subscriber with email %s not found.\n", email);
}

void displaySubscribers(const MailingList *list) {
    if (list->count == 0) {
        printf("No subscribers in the mailing list.\n");
        return;
    }
    
    printf("Current Mailing List Subscribers:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s (%s)\n", i + 1, list->subscribers[i].name, list->subscribers[i].email);
    }
}

void menu() {
    printf("Mailing List Manager\n");
    printf("1. Add Subscriber\n");
    printf("2. Remove Subscriber\n");
    printf("3. Display Subscribers\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    MailingList mailingList;
    initializeMailingList(&mailingList);
    
    int option;
    char name[MAX_NAME_LENGTH], email[MAX_NAME_LENGTH];

    while (1) {
        menu();
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                addSubscriber(&mailingList, name, email);
                break;
            case 2:
                printf("Enter email of the subscriber to remove: ");
                scanf("%s", email);
                removeSubscriber(&mailingList, email);
                break;
            case 3:
                displaySubscribers(&mailingList);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}