//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: shocked
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

void initializeList(MailingList *list) {
    list->count = 0;
}

void subscribe(MailingList *list, const char *email) {
    if (list->count >= MAX_SUBSCRIBERS) {
        printf("Oh no! Subscription limit reached! Can't add more subscribers!\n");
        return;
    }
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            printf("Oops! This email is already subscribed: %s\n", email);
            return;
        }
    }
    strncpy(list->subscribers[list->count].email, email, EMAIL_LENGTH);
    list->count++;
    printf("Wow! Successfully subscribed: %s\n", email);
}

void unsubscribe(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            printf("Yikes! Unsubscribing: %s\n", email);
            for (int j = i; j < list->count - 1; j++) {
                list->subscribers[j] = list->subscribers[j + 1];
            }
            list->count--;
            return;
        }
    }
    printf("Whoops! No such subscriber found: %s\n", email);
}

void listSubscribers(MailingList *list) {
    if (list->count == 0) {
        printf("Oh dear! No subscribers yet!\n");
        return;
    }
    printf("Current Subscribers:\n");
    for (int i = 0; i < list->count; i++) {
        printf(" - %s\n", list->subscribers[i].email);
    }
}

void freeList(MailingList *list) {
    // Not much to free in this case, but we keep it for structure!
    printf("Clearing the mailing list...\n");
    list->count = 0;
}

int main() {
    MailingList list;
    initializeList(&list);

    char email[EMAIL_LENGTH];
    int option;

    while (1) {
        printf("Choose an option:\n");
        printf("1. Subscribe\n");
        printf("2. Unsubscribe\n");
        printf("3. List Subscribers\n");
        printf("4. Exit\n");
        printf("Your choice: ");
        scanf("%d", &option);
        getchar(); // Clear the newline character

        switch (option) {
        case 1:
            printf("Enter email to subscribe: ");
            fgets(email, EMAIL_LENGTH, stdin);
            email[strcspn(email, "\n")] = 0; // Remove trailing newline character
            subscribe(&list, email);
            break;
        case 2:
            printf("Enter email to unsubscribe: ");
            fgets(email, EMAIL_LENGTH, stdin);
            email[strcspn(email, "\n")] = 0; // Remove trailing newline character
            unsubscribe(&list, email);
            break;
        case 3:
            listSubscribers(&list);
            break;
        case 4:
            printf("Exiting the mailing list manager... Bye now!\n");
            freeList(&list);
            exit(0);
        default:
            printf("Surprise! Invalid option! Try again!\n");
        }
    }

    return 0;
}