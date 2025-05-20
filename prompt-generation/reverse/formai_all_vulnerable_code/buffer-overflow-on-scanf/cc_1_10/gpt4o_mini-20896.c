//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define MAX_EMAIL_LENGTH 256

typedef struct Subscriber {
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

typedef struct MailingList {
    Subscriber subscribers[MAX_SUBSCRIBERS];
    int count;
} MailingList;

void initializeList(MailingList* list) {
    list->count = 0;
}

int addSubscriber(MailingList* list, const char* email) {
    if (list->count >= MAX_SUBSCRIBERS) {
        printf("Alas! The list is full; our love cannot grow further.\n");
        return -1;
    }

    // Check for duplicates 
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            printf("Oh dear! You are already a part of this romantic journey!\n");
            return -1;
        }
    }

    // Add a new subscriber
    strcpy(list->subscribers[list->count].email, email);
    list->count++;
    printf("Welcome to our love letters, dear %s!\n", email);
    return 0;
}

void displaySubscribers(const MailingList* list) {
    printf("Our cherished subscribers:\n");
    if (list->count == 0) {
        printf("No one has joined our love yet.\n");
        return;
    }
    for (int i = 0; i < list->count; i++) {
        printf(" - %s\n", list->subscribers[i].email);
    }
}

void sendLoveLetter(const MailingList* list, const char* message) {
    printf("💌 Sending love letters...\n");
    for (int i = 0; i < list->count; i++) {
        printf("Sending to %s: %s\n", list->subscribers[i].email, message);
    }
    printf("All letters have blossomed like flowers in spring! 🌷\n");
}

int removeSubscriber(MailingList* list, const char* email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            printf("Goodbye dear %s, your presence will be missed!\n", email);
            // Shift subscrivers to fill the gap
            for (int j = i; j < list->count - 1; j++) {
                list->subscribers[j] = list->subscribers[j + 1];
            }
            list->count--;
            return 0;
        }
    }
    printf("Oh dear! %s was not found in our little romance tale.\n", email);
    return -1;
}

void freeMailingList(MailingList* list) {
    // In our simple tale, no dynamic memory is allocated.
    // However, let us still offer goodbyes.
    printf("Clearing all memories of our sweet subscribers...\n");
    initializeList(list);
}

int main() {
    MailingList loveList;
    initializeList(&loveList);
    
    int choice;
    char email[MAX_EMAIL_LENGTH];
    char message[512];

    do {
        printf("\nWelcome to the Romantic Mailing List Manager!\n");
        printf("1. Add Subscriber\n");
        printf("2. Remove Subscriber\n");
        printf("3. Display Subscribers\n");
        printf("4. Send Love Letter\n");
        printf("5. Exit\n");
        printf("Choose your destiny (1-5): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter your delightful email: ");
                scanf("%s", email);
                addSubscriber(&loveList, email);
                break;
            case 2:
                printf("Enter the email to say farewell: ");
                scanf("%s", email);
                removeSubscriber(&loveList, email);
                break;
            case 3:
                displaySubscribers(&loveList);
                break;
            case 4:
                printf("Write your heart's message: ");
                getchar(); // To consume newline
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // Remove the newline
                sendLoveLetter(&loveList, message);
                break;
            case 5:
                freeMailingList(&loveList);
                printf("Thank you for being part of this love journey! 💖\n");
                break;
            default:
                printf("A wrong choice, but that's how love is—a delightful mystery.\n");
                break;
        }
    } while (choice != 5);
    
    return 0;
}