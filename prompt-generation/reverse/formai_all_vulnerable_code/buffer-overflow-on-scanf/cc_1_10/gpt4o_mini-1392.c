//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBS 100
#define MAX_NAME_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    int isSubscribed;
} Subscriber;

typedef struct {
    Subscriber subscribers[MAX_SUBS];
    int count;
} MailingList;

// Function prototypes
void initializeMailingList(MailingList *list);
void addSubscriber(MailingList *list, const char *name);
void removeSubscriber(MailingList *list, const char *name);
void printMailingList(const MailingList *list);
void showMenu();
int getChoice();
void handleChoice(MailingList *list, int choice);

int main() {
    MailingList mailingList;
    initializeMailingList(&mailingList);
    
    int choice;
    do {
        showMenu();
        choice = getChoice();
        handleChoice(&mailingList, choice);
        
    } while (choice != 4);

    return 0;
}

void initializeMailingList(MailingList *list) {
    list->count = 0;
}

void addSubscriber(MailingList *list, const char *name) {
    if (list->count < MAX_SUBS) {
        strncpy(list->subscribers[list->count].name, name, MAX_NAME_LEN);
        list->subscribers[list->count].isSubscribed = 1;
        list->count++;
        printf("Subscriber '%s' added to the mailing list.\n", name);
    } else {
        printf("Error: Mailing list is full!\n");
    }
}

void removeSubscriber(MailingList *list, const char *name) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].name, name) == 0) {
            list->subscribers[i].isSubscribed = 0;
            printf("Subscriber '%s' removed from the mailing list.\n", name);
            return;
        }
    }
    printf("Error: Subscriber '%s' not found in mailing list!\n", name);
}

void printMailingList(const MailingList *list) {
    printf("\nCurrent Mailing List:\n");
    for (int i = 0; i < list->count; i++) {
        if (list->subscribers[i].isSubscribed) {
            printf("- %s\n", list->subscribers[i].name);
        }
    }
    printf("\n");
}

void showMenu() {
    printf("\nMailing List Manager:\n");
    printf("1. Add Subscriber\n");
    printf("2. Remove Subscriber\n");
    printf("3. Print Mailing List\n");
    printf("4. Exit\n");
}

int getChoice() {
    int choice;
    printf("Please enter your choice (1-4): ");
    scanf("%d", &choice);
    return choice;
}

void handleChoice(MailingList *list, int choice) {
    char name[MAX_NAME_LEN];

    switch (choice) {
        case 1:
            printf("Enter name of subscriber to add: ");
            scanf("%s", name);
            addSubscriber(list, name);
            break;
        case 2:
            printf("Enter name of subscriber to remove: ");
            scanf("%s", name);
            removeSubscriber(list, name);
            break;
        case 3:
            printMailingList(list);
            break;
        case 4:
            printf("Exiting the Mailing List Manager. Goodbye!\n");
            break;
        default:
            printf("Error: Invalid choice! Please select from 1 to 4.\n");
            break;
    }
}