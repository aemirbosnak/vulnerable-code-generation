//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define EMAIL_LENGTH 100

typedef struct {
    char email[EMAIL_LENGTH];
} Subscriber;

typedef struct {
    Subscriber subscribers[MAX_EMAILS];
    int count;
} MailingList;

void initializeList(MailingList *list) {
    list->count = 0;
    printf("🎉 Welcome to the Ultimate Mailing List Manager! 🎉\n");
}

void addSubscriber(MailingList *list, const char *email) {
    if (list->count < MAX_EMAILS) {
        strcpy(list->subscribers[list->count].email, email);
        list->count++;
        printf("✨ Successfully added: %s to the mailing list! ✨\n", email);
    } else {
        printf("🚨 Mailing list is full! Cannot add more subscribers. 🚨\n");
    }
}

void removeSubscriber(MailingList *list, const char *email) {
    int found = -1;
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            found = i;
            break;
        }
    }
    
    if (found != -1) {
        for (int i = found; i < list->count - 1; i++) {
            list->subscribers[i] = list->subscribers[i + 1];
        }
        list->count--;
        printf("✨ Successfully removed: %s from the mailing list! ✨\n", email);
    } else {
        printf("🚫 Email address %s not found in the mailing list. 🚫\n", email);
    }
}

void displaySubscribers(MailingList *list) {
    if (list->count == 0) {
        printf("📭 The mailing list is currently empty! 📭\n");
        return;
    }

    printf("📜 Current Subscribers in the Mailing List 📜\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s\n", i + 1, list->subscribers[i].email);
    }
}

void clearList(MailingList *list) {
    list->count = 0;
    printf("🧹 The mailing list has been cleared! 🧹\n");
}

void showMenu() {
    printf("\n🌟 Mailing List Manager Menu 🌟\n");
    printf("1. Add Subscriber\n");
    printf("2. Remove Subscriber\n");
    printf("3. Display Subscribers\n");
    printf("4. Clear Mailing List\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    MailingList mailingList;
    initializeList(&mailingList);
    int choice;
    char email[EMAIL_LENGTH];

    while (1) {
        showMenu();
        scanf("%d", &choice);
        getchar(); // To consume newline character

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove trailing newline
                addSubscriber(&mailingList, email);
                break;

            case 2:
                printf("Enter email to remove: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove trailing newline
                removeSubscriber(&mailingList, email);
                break;

            case 3:
                displaySubscribers(&mailingList);
                break;

            case 4:
                clearList(&mailingList);
                break;

            case 5:
                printf("👋 Thank you for using the Mailing List Manager! Goodbye! 👋\n");
                exit(0);
                break;

            default:
                printf("❌ Invalid option! Please try again! ❌\n");
        }
    }

    return 0;
}