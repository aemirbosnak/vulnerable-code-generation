//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct subscriber {
    char name[50];
    char email[100];
    struct subscriber *next;
} subscriber;

subscriber *head = NULL;

void displayList() {
    subscriber *current = head;
    printf("\nSubscribers:\n");
    while (current != NULL) {
        printf("Name: %s, Email: %s\n", current->name, current->email);
        current = current->next;
    }
}

void addSubscriber(char *name, char *email) {
    subscriber *newSubscriber = (subscriber *)malloc(sizeof(subscriber));
    strcpy(newSubscriber->name, name);
    strcpy(newSubscriber->email, email);
    newSubscriber->next = head;
    head = newSubscriber;
}

void removeSubscriber(char *email) {
    subscriber *current = head;
    subscriber *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            break;
        } else {
            previous = current;
            current = current->next;
        }
    }
}

int main() {
    char name[50], email[100];
    int choice;

    while (true) {
        printf("\n1. Add Subscriber\n2. Remove Subscriber\n3. Display Subscribers\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                addSubscriber(name, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                scanf("%s", email);
                removeSubscriber(email);
                break;
            case 3:
                displayList();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}