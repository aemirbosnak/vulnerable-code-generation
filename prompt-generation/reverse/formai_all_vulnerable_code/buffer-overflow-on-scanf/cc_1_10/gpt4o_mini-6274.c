//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define MAX_EMAIL_LENGTH 256

typedef struct {
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

typedef struct {
    Subscriber subscribers[MAX_SUBSCRIBERS];
    int count;
} MailingList;

void initialize(MailingList* list) {
    list->count = 0;
}

int addSubscriber(MailingList* list, const char* email) {
    if (list->count >= MAX_SUBSCRIBERS) {
        printf("Error: Mailing list is full.\n");
        return -1;
    }
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            printf("Error: Subscriber already exists.\n");
            return -1;
        }
    }
    strncpy(list->subscribers[list->count].email, email, MAX_EMAIL_LENGTH);
    list->count++;
    printf("Subscriber %s added successfully.\n", email);
    return 0;
}

int removeSubscriber(MailingList* list, const char* email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            list->subscribers[i] = list->subscribers[list->count - 1];
            list->count--;
            printf("Subscriber %s removed successfully.\n", email);
            return 0;
        }
    }
    printf("Error: Subscriber not found.\n");
    return -1;
}

void listSubscribers(MailingList* list) {
    if (list->count == 0) {
        printf("No subscribers in the mailing list.\n");
        return;
    }
    printf("Mailing List Subscribers:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s\n", i + 1, list->subscribers[i].email);
    }
}

void sendMessage(MailingList* list, const char* message) {
    if (list->count == 0) {
        printf("Error: No subscribers to send the message to.\n");
        return;
    }
    printf("Sending message: \"%s\"\n", message);
    for (int i = 0; i < list->count; i++) {
        // Here we would simulate sending an email. In a real-world application, we would interact with an email server.
        printf("Sent to: %s\n", list->subscribers[i].email);
    }
}

void freeMailingList(MailingList* list) {
    // No dynamic memory allocated in this simple implementation,
    // but this function could be used for cleanup if necessary.
}

int main() {
    MailingList list;
    initialize(&list);

    int choice;
    char email[MAX_EMAIL_LENGTH], message[512];
    
    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add Subscriber\n");
        printf("2. Remove Subscriber\n");
        printf("3. List Subscribers\n");
        printf("4. Send Message\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter subscriber email: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0; // Remove trailing newline
                addSubscriber(&list, email);
                break;
            case 2:
                printf("Enter subscriber email: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0; // Remove trailing newline
                removeSubscriber(&list, email);
                break;
            case 3:
                listSubscribers(&list);
                break;
            case 4:
                printf("Enter message to send: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // Remove trailing newline
                sendMessage(&list, message);
                break;
            case 5:
                freeMailingList(&list);
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}