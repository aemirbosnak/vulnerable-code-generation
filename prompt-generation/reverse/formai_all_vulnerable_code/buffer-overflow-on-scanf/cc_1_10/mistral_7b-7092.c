//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SUBSCRIBERS 1000
#define LINE_LENGTH 256

typedef struct Subscriber {
    char name[LINE_LENGTH];
    char email[LINE_LENGTH];
    struct Subscriber *next;
} Subscriber;

Subscriber *mailing_list = NULL;
int num_subscribers = 0;

bool add_subscriber(char *name, char *email) {
    Subscriber *new_subscriber = (Subscriber *) malloc(sizeof(Subscriber));

    if (new_subscriber == NULL) {
        printf("Error: Out of memory!\n");
        return false;
    }

    strcpy(new_subscriber->name, name);
    strcpy(new_subscriber->email, email);
    new_subscriber->next = mailing_list;
    mailing_list = new_subscriber;
    num_subscribers++;

    return true;
}

void remove_subscriber(char *email) {
    Subscriber *current = mailing_list;
    Subscriber *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (previous == NULL) {
                mailing_list = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            num_subscribers--;
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Error: Subscriber not found!\n");
}

void print_mailing_list() {
    Subscriber *current = mailing_list;

    printf("Mailing List:\n");
    while (current != NULL) {
        printf("%s (%s)\n", current->name, current->email);
        current = current->next;
    }
}

int main() {
    int choice;
    char name[LINE_LENGTH], email[LINE_LENGTH];

    while (true) {
        printf("\n1. Add Subscriber\n");
        printf("2. Remove Subscriber\n");
        printf("3. Print Mailing List\n");
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
                printf("Enter email to remove: ");
                scanf("%s", email);
                remove_subscriber(email);
                break;
            case 3:
                print_mailing_list();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}