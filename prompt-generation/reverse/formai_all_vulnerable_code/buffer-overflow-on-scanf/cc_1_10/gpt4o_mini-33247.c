//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define EMAIL_LENGTH 100
#define MAX_MESSAGE_LENGTH 512

typedef struct {
    char email[EMAIL_LENGTH];
} Subscriber;

typedef struct {
    Subscriber subscribers[MAX_SUBSCRIBERS];
    int count;
} MailingList;

void initializeList(MailingList *list) {
    list->count = 0;
}

int addSubscriber(MailingList *list, const char *email) {
    if (list->count >= MAX_SUBSCRIBERS) {
        return -1; // List full
    }
    
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            return -2; // Subscriber already exists
        }
    }

    strcpy(list->subscribers[list->count].email, email);
    list->count++;
    return 0; // Success
}

int removeSubscriber(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            // Shift subscribers down
            for (int j = i; j < list->count - 1; j++) {
                list->subscribers[j] = list->subscribers[j + 1];
            }
            list->count--;
            return 0; // Success
        }
    }
    return -1; // Subscriber not found
}

void sendMessage(MailingList *list, const char *message) {
    printf("Sending message to %d subscribers:\n", list->count);
    for (int i = 0; i < list->count; i++) {
        printf("To: %s\nMessage: %s\n\n", list->subscribers[i].email, message);
    }
}

void listSubscribers(MailingList *list) {
    printf("Current Subscribers (%d):\n", list->count);
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s\n", i + 1, list->subscribers[i].email);
    }
}

void clearList(MailingList *list) {
    list->count = 0;
    printf("All subscribers have been removed.\n");
}

void displayMenu() {
    printf("\nMailing List Manager\n");
    printf("1. Add Subscriber\n");
    printf("2. Remove Subscriber\n");
    printf("3. List Subscribers\n");
    printf("4. Send Message\n");
    printf("5. Clear List\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    MailingList mailingList;
    initializeList(&mailingList);

    while (1) {
        displayMenu();
        int option;
        scanf("%d", &option);
        getchar(); // clear newline

        switch (option) {
            case 1: {
                char email[EMAIL_LENGTH];
                printf("Enter subscriber email: ");
                fgets(email, EMAIL_LENGTH, stdin);
                strtok(email, "\n"); // Remove newline
                
                int result = addSubscriber(&mailingList, email);
                if (result == 0) {
                    printf("Subscriber %s added successfully.\n", email);
                } else if (result == -1) {
                    printf("List is full.\n");
                } else if (result == -2) {
                    printf("Subscriber %s already exists.\n", email);
                }
                break;
            }
            case 2: {
                char email[EMAIL_LENGTH];
                printf("Enter subscriber email to remove: ");
                fgets(email, EMAIL_LENGTH, stdin);
                strtok(email, "\n"); // Remove newline
                
                if (removeSubscriber(&mailingList, email) == 0) {
                    printf("Subscriber %s removed successfully.\n", email);
                } else {
                    printf("Subscriber %s not found.\n", email);
                }
                break;
            }
            case 3: {
                listSubscribers(&mailingList);
                break;
            }
            case 4: {
                char message[MAX_MESSAGE_LENGTH];
                printf("Enter your message: ");
                fgets(message, MAX_MESSAGE_LENGTH, stdin);
                strtok(message, "\n"); // Remove newline
                
                sendMessage(&mailingList, message);
                break;
            }
            case 5: {
                clearList(&mailingList);
                break;
            }
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}