//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Subscriber structure
typedef struct Subscriber {
    char name[50];
    char email[100];
    struct Subscriber *next;
} Subscriber;

// Linked list for managing subscribers
Subscriber *mailing_list = NULL;

// Function to add a new subscriber to the list
void add_subscriber(char *name, char *email) {
    Subscriber *new_subscriber = (Subscriber *)malloc(sizeof(Subscriber));
    strcpy(new_subscriber->name, name);
    strcpy(new_subscriber->email, email);
    new_subscriber->next = mailing_list;
    mailing_list = new_subscriber;
}

// Function to remove a subscriber from the list by name
void remove_subscriber(char *name) {
    Subscriber *current = mailing_list;
    Subscriber *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                mailing_list = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

// Function to display all subscribers in the list
void display_subscribers() {
    Subscriber *current = mailing_list;

    printf("\n---- Mailing List ----\n");
    while (current != NULL) {
        printf("%s (%s)\n", current->name, current->email);
        current = current->next;
    }
}

int main() {
    char name[50], email[100];
    int choice;

    while (1) {
        printf("\n1. Add Subscriber\n");
        printf("2. Remove Subscriber\n");
        printf("3. Display Subscribers\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                add_subscriber(name, email);
                break;
            case 2:
                printf("Enter name to remove: ");
                scanf("%s", name);
                remove_subscriber(name);
                break;
            case 3:
                display_subscribers();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}