//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SUBSCRIBERS 100
#define EMAIL_LENGTH 100
#define MAX_MESSAGE_LENGTH 500
#define COMMAND_LENGTH 50

typedef struct Subscriber {
    char email[EMAIL_LENGTH];
    time_t subscribe_time;
} Subscriber;

typedef struct MailingList {
    Subscriber subscribers[MAX_SUBSCRIBERS];
    int count;
} MailingList;

void initializeList(MailingList *list) {
    list->count = 0;
}

int addSubscriber(MailingList *list, const char *email) {
    if (list->count >= MAX_SUBSCRIBERS) {
        printf("Mailbox is full, cannot subscribe more users in this dystopian world.\n");
        return -1;
    }
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            printf("Email already subscribed, this is a digital realm of redundancy.\n");
            return -1;
        }
    }

    strncpy(list->subscribers[list->count].email, email, EMAIL_LENGTH);
    list->subscribers[list->count].subscribe_time = time(NULL);
    list->count++;
    printf("Subscriber %s entered the neon cyberspace.\n", email);
    return 0;
}

void removeSubscriber(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            printf("Subscriber %s erased from the digital matrix.\n", email);
            for (int j = i; j < list->count - 1; j++) {
                list->subscribers[j] = list->subscribers[j + 1];
            }
            list->count--;
            return;
        }
    }
    printf("Subscriber with email %s not found in this neon dystopia.\n", email);
}

void sendMessage(MailingList *list, const char *message) {
    printf("\n--- Dispatching Message: ---\n");
    for (int i = 0; i < list->count; i++) {
        printf("To: %s\nMessage: %s\n", list->subscribers[i].email, message);
    }
    printf("--- All messages dispatched in the void. ---\n");
}

void displaySubscribers(MailingList *list) {
    if (list->count == 0) {
        printf("No subscribers in the dark alleys of the network.\n");
        return;
    }
    printf("\n--- Current Subscribers in the Cyberspace: ---\n");
    for (int i = 0; i < list->count; i++) {
        printf("#%d: %s\n", i + 1, list->subscribers[i].email);
    }
    printf("--- End of list, till the next data surge! ---\n");
}

int main() {
    MailingList myMailingList;
    initializeList(&myMailingList);
    char command[COMMAND_LENGTH];
    char email[EMAIL_LENGTH];
    char message[MAX_MESSAGE_LENGTH];

    printf("Welcome to the Cyber-Mailing List Manager!\n");
    while (1) {
        printf("\nEnter command (subscribe, unsubscribe, send, display, exit): ");
        scanf("%s", command);

        if (strcmp(command, "subscribe") == 0) {
            printf("Enter email to subscribe: ");
            scanf("%s", email);
            addSubscriber(&myMailingList, email);
        }
        else if (strcmp(command, "unsubscribe") == 0) {
            printf("Enter email to unsubscribe: ");
            scanf("%s", email);
            removeSubscriber(&myMailingList, email);
        }
        else if (strcmp(command, "send") == 0) {
            printf("Enter your message to send: ");
            getchar(); // to clean the newline character from previous input
            fgets(message, MAX_MESSAGE_LENGTH, stdin);
            message[strcspn(message, "\n")] = 0; // remove newline character
            sendMessage(&myMailingList, message);
        }
        else if (strcmp(command, "display") == 0) {
            displaySubscribers(&myMailingList);
        }
        else if (strcmp(command, "exit") == 0) {
            printf("Shutting down the Cyber-Mailing List Manager.\n");
            break;
        }
        else {
            printf("Unknown command, the network is unforgiving.\n");
        }
    }

    return 0;
}