//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 100
#define MAX_LIST_SIZE 50

typedef struct {
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

typedef struct {
    Subscriber list[MAX_LIST_SIZE];
    int count;
} MailingList;

void initializeList(MailingList* ml) {
    ml->count = 0;
}

int addSubscriber(MailingList* ml, const char* email) {
    if (ml->count >= MAX_LIST_SIZE) {
        printf("Mailing List is full! Cannot add more subscribers.\n");
        return 0;
    }
    // Check for duplicates
    for (int i = 0; i < ml->count; i++) {
        if (strcmp(ml->list[i].email, email) == 0) {
            printf("Subscriber with email '%s' already exists!\n", email);
            return 0;
        }
    }
    strcpy(ml->list[ml->count].email, email);
    ml->count++;
    printf("Added subscriber: %s\n", email);
    return 1;
}

int removeSubscriber(MailingList* ml, const char* email) {
    for (int i = 0; i < ml->count; i++) {
        if (strcmp(ml->list[i].email, email) == 0) {
            ml->count--;
            for (int j = i; j < ml->count; j++) {
                ml->list[j] = ml->list[j + 1];
            }
            printf("Removed subscriber: %s\n", email);
            return 1;
        }
    }
    printf("Subscriber with email '%s' not found!\n", email);
    return 0;
}

void displayMailingList(const MailingList* ml) {
    if (ml->count == 0) {
        printf("The mailing list is currently empty.\n");
        return;
    }
    printf("Mailing List Subscribers:\n");
    for (int i = 0; i < ml->count; i++) {
        printf("- %s\n", ml->list[i].email);
    }
}

int searchSubscriber(const MailingList* ml, const char* email) {
    for (int i = 0; i < ml->count; i++) {
        if (strcmp(ml->list[i].email, email) == 0) {
            printf("Subscriber found: %s\n", ml->list[i].email);
            return 1;
        }
    }
    printf("Subscriber with email '%s' not found!\n", email);
    return 0;
}

void showMenu() {
    printf("\nMailing List Manager Menu:\n");
    printf("1. Add Subscriber\n");
    printf("2. Remove Subscriber\n");
    printf("3. Display Mailing List\n");
    printf("4. Search Subscriber\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    MailingList ml;
    initializeList(&ml);
    
    int choice;
    char email[MAX_EMAIL_LENGTH];

    while (1) {
        showMenu();
        scanf("%d", &choice);
        getchar();  // Clear newline character from input buffer

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline character
                addSubscriber(&ml, email);
                break;

            case 2:
                printf("Enter email to remove: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline character
                removeSubscriber(&ml, email);
                break;

            case 3:
                displayMailingList(&ml);
                break;

            case 4:
                printf("Enter email to search: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline character
                searchSubscriber(&ml, email);
                break;

            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}