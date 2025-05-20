//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: invasive
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

void add_subscriber(MailingList *list, const char *email) {
    if (list->count >= MAX_SUBSCRIBERS) {
        printf("Mailing list is full!\n");
        return;
    }
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            printf("This email is already subscribed: %s\n", email);
            return;
        }
    }
    strcpy(list->subscribers[list->count].email, email);
    list->count++;
    printf("Successfully added: %s\n", email);
}

void remove_subscriber(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            for (int j = i; j < list->count - 1; j++) {
                list->subscribers[j] = list->subscribers[j + 1];
            }
            list->count--;
            printf("Successfully removed: %s\n", email);
            return;
        }
    }
    printf("Email not found: %s\n", email);
}

void display_subscribers(const MailingList *list) {
    if (list->count == 0) {
        printf("No subscribers in the mailing list.\n");
        return;
    }
    printf("Current Subscribers:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s\n", i + 1, list->subscribers[i].email);
    }
}

void display_menu() {
    printf("\nMailing List Manager\n");
    printf("1. Add Subscriber\n");
    printf("2. Remove Subscriber\n");
    printf("3. Display Subscribers\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    MailingList ml = {.count = 0};
    int choice;
    char email[EMAIL_LENGTH];

    while (1) {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                scanf("%s", email);
                add_subscriber(&ml, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                scanf("%s", email);
                remove_subscriber(&ml, email);
                break;
            case 3:
                display_subscribers(&ml);
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