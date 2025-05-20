//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define MAX_EMAIL_LENGTH 255
#define MAX_MESSAGE_LENGTH 512

typedef struct Subscriber {
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

typedef struct MailingList {
    Subscriber subscribers[MAX_SUBSCRIBERS];
    int count;
} MailingList;

void initMailingList(MailingList *list) {
    list->count = 0;
}

int addSubscriber(MailingList *list, const char *email) {
    if (list->count >= MAX_SUBSCRIBERS) {
        printf("Alas! The list is already filled with glorious emails!\n");
        return -1;
    }
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            printf("Verily, this email hath already been entered in the scrolls!\n");
            return -1;
        }
    }
    strncpy(list->subscribers[list->count].email, email, MAX_EMAIL_LENGTH);
    list->count++;
    printf("Huzzah! The email \"%s\" hath been added to our sacred list.\n", email);
    return 0;
}

int removeSubscriber(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            printf("Farewell! The email \"%s\" hath been banished from our noble list.\n", email);
            for (int j = i; j < list->count - 1; j++) {
                list->subscribers[j] = list->subscribers[j + 1];
            }
            list->count--;
            return 0;
        }
    }
    printf("Alas! The email \"%s\" could not be found in our scrolls.\n", email);
    return -1;
}

void sendMessage(const MailingList *list, const char *message) {
    printf("A message hath been composed:\n%s\n", message);
    printf("Sending forth the missive to the following brave souls:\n");
    for (int i = 0; i < list->count; i++) {
        printf(" - To: %s\n", list->subscribers[i].email);
    }
    printf("The message hath been sent to all subscribers!\n");
}

void displaySubscribers(const MailingList *list) {
    if (list->count == 0) {
        printf("Our list of subscribers is currently barren...\n");
        return;
    }
    printf("Behold the roster of subscribers:\n");
    for (int i = 0; i < list->count; i++) {
        printf(" - %s\n", list->subscribers[i].email);
    }
}

int main() {
    MailingList list;
    initMailingList(&list);

    char command[10];
    char email[MAX_EMAIL_LENGTH];
    char message[MAX_MESSAGE_LENGTH];

    while (1) {
        printf("\nEnter a command (add, remove, send, show, exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter the email to add: ");
            scanf("%s", email);
            addSubscriber(&list, email);
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter the email to remove: ");
            scanf("%s", email);
            removeSubscriber(&list, email);
        } else if (strcmp(command, "send") == 0) {
            printf("Compose your message (up to 512 characters): ");
            getchar(); // Consume the newline from previous input
            fgets(message, MAX_MESSAGE_LENGTH, stdin);
            message[strcspn(message, "\n")] = 0; // Remove newline character
            sendMessage(&list, message);
        } else if (strcmp(command, "show") == 0) {
            displaySubscribers(&list);
        } else if (strcmp(command, "exit") == 0) {
            printf("Retreating from our noble quest...\n");
            break;
        } else {
            printf("Alas! That command is unknown in our tomes.\n");
        }
    }

    return 0;
}