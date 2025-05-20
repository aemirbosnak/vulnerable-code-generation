//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LENGTH 256
#define MAX_NAME_LENGTH 50

typedef struct {
    char email[MAX_EMAIL_LENGTH];
    char name[MAX_NAME_LENGTH];
} Subscriber;

typedef struct {
    Subscriber subscribers[MAX_EMAILS];
    int count;
} MailingList;

void initialize_list(MailingList *list) {
    list->count = 0;
}

void add_subscriber(MailingList *list, const char *email, const char *name) {
    if (list->count < MAX_EMAILS) {
        strncpy(list->subscribers[list->count].email, email, MAX_EMAIL_LENGTH - 1);
        strncpy(list->subscribers[list->count].name, name, MAX_NAME_LENGTH - 1);
        list->subscribers[list->count].email[MAX_EMAIL_LENGTH - 1] = '\0'; 
        list->subscribers[list->count].name[MAX_NAME_LENGTH - 1] = '\0'; 
        list->count++;
        printf("Subscriber %s added.\n", name);
    } else {
        printf("Mailing list is full, cannot add more subscribers.\n");
    }
}

void remove_subscriber(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            for (int j = i; j < list->count - 1; j++) {
                list->subscribers[j] = list->subscribers[j + 1]; // Shift the last subscriber forward.
            }
            list->count--;
            printf("Subscriber with email %s removed.\n", email);
            return;
        }
    }
    printf("Subscriber with email %s not found.\n", email);
}

void list_subscribers(const MailingList *list) {
    printf("Current Subscribers:\n");
    for (int i = 0; i < list->count; i++) {
        printf("Name: %s, Email: %s\n", list->subscribers[i].name, list->subscribers[i].email);
    }
}

void send_message(const MailingList *list, const char *message) {
    printf("Sending message to subscribers:\n");
    for (int i = 0; i < list->count; i++) {
        printf("To: %s <%s>\nMessage: %s\n", list->subscribers[i].name, list->subscribers[i].email, message);
    }
}

int main() {
    MailingList myList;
    initialize_list(&myList);

    int choice;
    char email[MAX_EMAIL_LENGTH], name[MAX_NAME_LENGTH], message[512];

    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add Subscriber\n");
        printf("2. Remove Subscriber\n");
        printf("3. List Subscribers\n");
        printf("4. Send Message\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from buffer

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove trailing newline
                printf("Enter email: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove trailing newline
                add_subscriber(&myList, email, name);
                break;
            case 2:
                printf("Enter email of subscriber to remove: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove trailing newline
                remove_subscriber(&myList, email);
                break;
            case 3:
                list_subscribers(&myList);
                break;
            case 4:
                printf("Enter message to send: ");
                fgets(message, 512, stdin);
                message[strcspn(message, "\n")] = 0; // Remove trailing newline
                send_message(&myList, message);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}