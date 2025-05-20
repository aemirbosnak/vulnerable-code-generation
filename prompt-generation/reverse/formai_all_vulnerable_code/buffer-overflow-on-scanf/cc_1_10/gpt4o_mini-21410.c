//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define BUF_SIZE 256

typedef struct {
    char email[BUF_SIZE];
} Subscriber;

Subscriber *list[MAX_SUBSCRIBERS];
int count = 0;

void addSubscriber() {
    if (count >= MAX_SUBSCRIBERS) {
        printf("Max subscribers reached!\n");
        return;
    }
    char email[BUF_SIZE];
    printf("Enter email to subscribe: ");
    scanf("%s", email);
    
    if (strchr(email, '@') == NULL || strchr(email, '.') == NULL) {
        printf("Invalid email format!\n");
        return;
    }

    list[count] = (Subscriber *)malloc(sizeof(Subscriber));
    strncpy(list[count]->email, email, BUF_SIZE);
    count++;
    printf("Successfully subscribed: %s\n", email);
}

void removeSubscriber() {
    char email[BUF_SIZE];
    printf("Enter email to unsubscribe: ");
    scanf("%s", email);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(list[i]->email, email) == 0) {
            free(list[i]);
            list[i] = list[count - 1]; // Move last subscriber to current position
            count--;
            printf("Successfully unsubscribed: %s\n", email);
            return;
        }
    }

    printf("Email not found in the list.\n");
}

void printSubscribers() {
    if (count == 0) {
        printf("No subscribers found.\n");
        return;
    }
    printf("Current Subscribers:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s\n", i + 1, list[i]->email);
    }
}

void clearSubscribers() {
    for (int i = 0; i < count; i++) {
        free(list[i]);
    }
    count = 0;
    printf("All subscribers removed.\n");
}

void menu() {
    printf("=== Mailing List Manager ===\n");
    printf("1. Add Subscriber\n");
    printf("2. Remove Subscriber\n");
    printf("3. List Subscribers\n");
    printf("4. Clear All Subscribers\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    do {
        menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addSubscriber();
                break;
            case 2:
                removeSubscriber();
                break;
            case 3:
                printSubscribers();
                break;
            case 4:
                clearSubscribers();
                break;
            case 5:
                clearSubscribers();
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}