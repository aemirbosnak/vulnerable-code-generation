//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define EMAIL_LENGTH 50
#define FILENAME "subscribers.txt"

typedef struct {
    char email[EMAIL_LENGTH];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int subscriber_count = 0;

void load_subscribers() {
    FILE *file = fopen(FILENAME, "r");
    if (file != NULL) {
        while (fgets(subscribers[subscriber_count].email, EMAIL_LENGTH, file) && subscriber_count < MAX_SUBSCRIBERS) {
            subscribers[subscriber_count].email[strcspn(subscribers[subscriber_count].email, "\n")] = 0; // Remove newline
            subscriber_count++;
        }
        fclose(file);
    }
}

void save_subscribers() {
    FILE *file = fopen(FILENAME, "w");
    for (int i = 0; i < subscriber_count; i++) {
        fprintf(file, "%s\n", subscribers[i].email);
    }
    fclose(file);
}

void add_subscriber(const char *email) {
    if (subscriber_count < MAX_SUBSCRIBERS) {
        strcpy(subscribers[subscriber_count].email, email);
        subscriber_count++;
    } else {
        printf("Subscriber list is full!\n");
    }
}

void remove_subscriber(const char *email) {
    for (int i = 0; i < subscriber_count; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            for (int j = i; j < subscriber_count - 1; j++) {
                subscribers[j] = subscribers[j + 1];
            }
            subscriber_count--;
            printf("Subscriber removed: %s\n", email);
            return;
        }
    }
    printf("Subscriber not found: %s\n", email);
}

void list_subscribers() {
    printf("Subscribers List:\n");
    for (int i = 0; i < subscriber_count; i++) {
        printf("%d. %s\n", i + 1, subscribers[i].email);
    }
}

void display_menu() {
    printf("\nMailing List Manager\n");
    printf("1. Add Subscriber\n");
    printf("2. Remove Subscriber\n");
    printf("3. List Subscribers\n");
    printf("4. Exit\n");
}

int main() {
    char email[EMAIL_LENGTH];
    int choice;

    load_subscribers();

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline character

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline
                add_subscriber(email);
                save_subscribers();
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline
                remove_subscriber(email);
                save_subscribers();
                break;
            case 3:
                list_subscribers();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}