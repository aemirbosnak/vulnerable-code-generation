//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char email[NAME_LENGTH];
} Subscriber;

typedef struct {
    Subscriber subscribers[MAX_SUBSCRIBERS];
    int count;
} MailingList;

// Function Prototypes
void initMailingList(MailingList* list);
int addSubscriber(MailingList* list, const char* name, const char* email);
int removeSubscriber(MailingList* list, const char* email);
void displaySubscribers(const MailingList* list);
void clearBuffer();

int main() {
    MailingList list;
    initMailingList(&list);

    int choice;
    char name[NAME_LENGTH];
    char email[NAME_LENGTH];

    do {
        printf("\nMailing List Manager\n");
        printf("1. Add Subscriber\n");
        printf("2. Remove Subscriber\n");
        printf("3. Display Subscribers\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer(); // Clear newline from buffer

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline

                printf("Enter email: ");
                fgets(email, NAME_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline

                if (addSubscriber(&list, name, email)) {
                    printf("Subscriber added successfully.\n");
                } else {
                    printf("Failed to add subscriber. List might be full.\n");
                }
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, NAME_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline

                if (removeSubscriber(&list, email)) {
                    printf("Subscriber removed successfully.\n");
                } else {
                    printf("Subscriber not found.\n");
                }
                break;
            case 3:
                printf("Current Subscribers:\n");
                displaySubscribers(&list);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function implementations
void initMailingList(MailingList* list) {
    list->count = 0;
}

int addSubscriber(MailingList* list, const char* name, const char* email) {
    if (list->count >= MAX_SUBSCRIBERS) {
        return 0; // List is full
    }

    strcpy(list->subscribers[list->count].name, name);
    strcpy(list->subscribers[list->count].email, email);
    list->count++;
    return 1; // Successful addition
}

int removeSubscriber(MailingList* list, const char* email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            // Shift subscribers down
            for (int j = i; j < list->count - 1; j++) {
                list->subscribers[j] = list->subscribers[j + 1];
            }
            list->count--;
            return 1; // Successful removal
        }
    }
    return 0; // Subscriber not found
}

void displaySubscribers(const MailingList* list) {
    if (list->count == 0) {
        printf("No subscribers in the list.\n");
        return;
    }

    for (int i = 0; i < list->count; i++) {
        printf("Name: %s, Email: %s\n", list->subscribers[i].name, list->subscribers[i].email);
    }
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}