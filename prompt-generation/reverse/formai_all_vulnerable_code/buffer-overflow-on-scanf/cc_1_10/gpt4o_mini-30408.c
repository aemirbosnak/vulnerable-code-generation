//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
} Subscriber;

Subscriber mailingList[MAX_SUBSCRIBERS];
int subscriberCount = 0;

void addSubscriber() {
    if (subscriberCount >= MAX_SUBSCRIBERS) {
        printf("Mailing list is full! Cannot add more subscribers.\n");
        return;
    }
    
    char name[NAME_LENGTH];
    printf("Enter your name to subscribe: ");
    scanf(" %[^\n]", name);

    // Check for duplicate
    for (int i = 0; i < subscriberCount; i++) {
        if (strcmp(mailingList[i].name, name) == 0) {
            printf("You are already subscribed!\n");
            return;
        }
    }

    strcpy(mailingList[subscriberCount].name, name);
    subscriberCount++;
    printf("Welcome, %s! You have successfully subscribed!\n", name);
}

void removeSubscriber() {
    char name[NAME_LENGTH];
    printf("Enter your name to unsubscribe: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < subscriberCount; i++) {
        if (strcmp(mailingList[i].name, name) == 0) {
            printf("Goodbye, %s! You have been unsubscribed.\n", name);
            for (int j = i; j < subscriberCount - 1; j++) {
                mailingList[j] = mailingList[j + 1]; // Shift left
            }
            subscriberCount--;
            return;
        }
    }

    printf("No subscription found for %s.\n", name);
}

void displaySubscribers() {
    if (subscriberCount == 0) {
        printf("No subscribers in the mailing list.\n");
        return;
    }

    printf("\nCurrent Subscribers:\n");
    for (int i = 0; i < subscriberCount; i++) {
        printf("%d. %s\n", i + 1, mailingList[i].name);
    }
}

void showMenu() {
    printf("\n--- Mailing List Manager ---\n");
    printf("1. Subscribe\n");
    printf("2. Unsubscribe\n");
    printf("3. Display Subscribers\n");
    printf("4. Exit\n");
    printf("-----------------------------\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    do {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSubscriber();
                break;
            case 2:
                removeSubscriber();
                break;
            case 3:
                displaySubscribers();
                break;
            case 4:
                printf("Exiting. Thank you for using the Mailing List Manager!\n");
                break;
            default:
                printf("Invalid option! Please choose again.\n");
        }
    } while (choice != 4);

    return 0;
}