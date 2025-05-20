//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define MAX_EMAIL_SIZE 100

typedef struct {
    char email[MAX_EMAIL_SIZE];
} Subscriber;

typedef struct {
    Subscriber subscribers[MAX_SUBSCRIBERS];
    int count;
} MailingList;

void initMailingList(MailingList* list) {
    list->count = 0;
}

int addSubscriber(MailingList* list, const char* email) {
    if (list->count >= MAX_SUBSCRIBERS) {
        printf("Mailing list is full!\n");
        return -1;
    }
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            printf("Email already subscribed!\n");
            return -1;
        }
    }
    strcpy(list->subscribers[list->count].email, email);
    list->count++;
    printf("Added %s to the mailing list.\n", email);
    return 0;
}

int removeSubscriber(MailingList* list, const char* email) {
    int index = -1;
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Email not found in the mailing list.\n");
        return -1; 
    }
    for (int i = index; i < list->count - 1; i++) {
        list->subscribers[i] = list->subscribers[i + 1];
    }
    list->count--;
    printf("Removed %s from the mailing list.\n", email);
    return 0;
}

void displaySubscribers(const MailingList* list) {
    if (list->count == 0) {
        printf("No subscribers in the list.\n");
        return;
    }
    printf("Current Subscribers:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%s\n", list->subscribers[i].email);
    }
}

void processCommands(MailingList* list) {
    char command[10];
    char email[MAX_EMAIL_SIZE];
    
    while (1) {
        printf("\nEnter command (add, remove, display, exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter email to add: ");
            scanf("%s", email);
            addSubscriber(list, email);
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter email to remove: ");
            scanf("%s", email);
            removeSubscriber(list, email);
        } else if (strcmp(command, "display") == 0) {
            displaySubscribers(list);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Unknown command. Please try again.\n");
        }
    }
}

int main() {
    MailingList mailingList;
    initMailingList(&mailingList);
    
    processCommands(&mailingList);
    
    return 0;
}