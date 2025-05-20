//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LISTS 100
#define MAX_SUBSCRIBERS 100
#define EMAIL_LENGTH 100
#define LIST_NAME_LENGTH 50

typedef struct {
    char email[EMAIL_LENGTH];
} Subscriber;

typedef struct {
    char name[LIST_NAME_LENGTH];
    Subscriber subscribers[MAX_SUBSCRIBERS];
    int subscriber_count;
} MailingList;

MailingList mailingLists[MAX_LISTS];
int list_count = 0;

void createList() {
    if (list_count >= MAX_LISTS) {
        printf("Maximum mailing list limit reached.\n");
        return;
    }
    
    MailingList newList;
    printf("Enter mailing list name: ");
    scanf("%s", newList.name);
    newList.subscriber_count = 0;

    mailingLists[list_count++] = newList;
    printf("Mailing list '%s' created successfully!\n", newList.name);
}

void subscribe() {
    char list_name[LIST_NAME_LENGTH];
    char email[EMAIL_LENGTH];

    printf("Enter mailing list name to subscribe to: ");
    scanf("%s", list_name);
    
    for (int i = 0; i < list_count; i++) {
        if (strcmp(mailingLists[i].name, list_name) == 0) {
            if (mailingLists[i].subscriber_count >= MAX_SUBSCRIBERS) {
                printf("Subscriber limit reached for list '%s'.\n", list_name);
                return;
            }
            
            printf("Enter your email to subscribe: ");
            scanf("%s", email);
            strcpy(mailingLists[i].subscribers[mailingLists[i].subscriber_count++].email, email);
            printf("You've been subscribed to '%s'!\n", list_name);
            return;
        }
    }
    printf("Mailing list '%s' not found.\n", list_name);
}

void unsubscribe() {
    char list_name[LIST_NAME_LENGTH];
    char email[EMAIL_LENGTH];

    printf("Enter mailing list name to unsubscribe from: ");
    scanf("%s", list_name);
    
    for (int i = 0; i < list_count; i++) {
        if (strcmp(mailingLists[i].name, list_name) == 0) {
            printf("Enter your email to unsubscribe: ");
            scanf("%s", email);

            for (int j = 0; j < mailingLists[i].subscriber_count; j++) {
                if (strcmp(mailingLists[i].subscribers[j].email, email) == 0) {
                    // Shift subscribers down
                    for (int k = j; k < mailingLists[i].subscriber_count - 1; k++) {
                        mailingLists[i].subscribers[k] = mailingLists[i].subscribers[k + 1];
                    }
                    mailingLists[i].subscriber_count--;
                    printf("You've been unsubscribed from '%s'!\n", list_name);
                    return;
                }
            }
            printf("Email '%s' not found in list '%s'.\n", email, list_name);
            return;
        }
    }
    printf("Mailing list '%s' not found.\n", list_name);
}

void displayLists() {
    if (list_count == 0) {
        printf("No mailing lists available.\n");
        return;
    }
    
    printf("Available Mailing Lists:\n");
    for (int i = 0; i < list_count; i++) {
        printf("%d. %s - %d subscribers\n", i + 1, mailingLists[i].name, mailingLists[i].subscriber_count);
    }
}

void displaySubscribers() {
    char list_name[LIST_NAME_LENGTH];

    printf("Enter mailing list name to display subscribers: ");
    scanf("%s", list_name);

    for (int i = 0; i < list_count; i++) {
        if (strcmp(mailingLists[i].name, list_name) == 0) {
            printf("Subscribers for '%s':\n", list_name);
            for (int j = 0; j < mailingLists[i].subscriber_count; j++) {
                printf("%s\n", mailingLists[i].subscribers[j].email);
            }
            return;
        }
    }
    printf("Mailing list '%s' not found.\n", list_name);
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Futuristic Mailing List Manager ---\n");
        printf("1. Create Mailing List\n");
        printf("2. Subscribe to Mailing List\n");
        printf("3. Unsubscribe from Mailing List\n");
        printf("4. Display Mailing Lists\n");
        printf("5. Display Subscribers\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createList();
                break;
            case 2:
                subscribe();
                break;
            case 3:
                unsubscribe();
                break;
            case 4:
                displayLists();
                break;
            case 5:
                displaySubscribers();
                break;
            case 6:
                printf("Exiting... Goodbye from the future!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}