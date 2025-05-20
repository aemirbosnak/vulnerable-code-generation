//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define EMAIL_LENGTH 100

typedef struct {
    char email[EMAIL_LENGTH];
} Subscriber;

typedef struct {
    Subscriber subscribers[MAX_SUBSCRIBERS];
    int count;
} MailingList;

// Function prototypes
void initializeList(MailingList *list);
int addSubscriber(MailingList *list, const char *email);
void removeSubscriber(MailingList *list, const char *email);
void displaySubscribers(const MailingList *list);
int isEmailInList(const MailingList *list, const char *email);
void clearBuffer();

int main() {
    MailingList mailingList;
    initializeList(&mailingList);

    int choice;
    char email[EMAIL_LENGTH];
    
    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add Subscriber\n");
        printf("2. Remove Subscriber\n");
        printf("3. Display Subscribers\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                printf("Enter subscriber email: ");
                fgets(email, EMAIL_LENGTH, stdin);
                strtok(email, "\n"); // Remove newline character
                if (addSubscriber(&mailingList, email))
                    printf("Subscriber added successfully!\n");
                else
                    printf("Failed to add subscriber (List may be full or email is invalid).\n");
                break;

            case 2:
                printf("Enter subscriber email to remove: ");
                fgets(email, EMAIL_LENGTH, stdin);
                strtok(email, "\n");
                removeSubscriber(&mailingList, email);
                break;

            case 3:
                displaySubscribers(&mailingList);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void initializeList(MailingList *list) {
    list->count = 0;
}

int addSubscriber(MailingList *list, const char *email) {
    if (list->count >= MAX_SUBSCRIBERS) {
        return 0; // List is full
    }
    if (isEmailInList(list, email)) {
        printf("Email already exists in the list.\n");
        return 0;
    }
    strcpy(list->subscribers[list->count].email, email);
    list->count++;
    return 1; // Successfully added
}

void removeSubscriber(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            // Shift the remaining subscribers left
            for (int j = i; j < list->count - 1; j++) {
                list->subscribers[j] = list->subscribers[j + 1];
            }
            list->count--;
            printf("Subscriber removed successfully!\n");
            return;
        }
    }
    printf("Email not found in the list.\n");
}

void displaySubscribers(const MailingList *list) {
    if (list->count == 0) {
        printf("No subscribers in the list.\n");
        return;
    }
    printf("\n--- List of Subscribers ---\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s\n", i + 1, list->subscribers[i].email);
    }
}

int isEmailInList(const MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            return 1; // Email found
        }
    }
    return 0; // Email not found
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}