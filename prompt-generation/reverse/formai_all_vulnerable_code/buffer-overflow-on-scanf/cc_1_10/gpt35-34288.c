//FormAI DATASET v1.0 Category: Mailing list manager ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Subscriber {
    char email[50];
    struct Subscriber* next;
} Subscriber;

Subscriber* head = NULL;
Subscriber* tail = NULL;

void addSubscriber() {
    char email[50];
    printf("Enter email: ");
    scanf("%s", email);

    Subscriber* newSubscriber = (Subscriber*) malloc(sizeof(Subscriber));

    if (newSubscriber == NULL) {
        printf("Error: Memory allocation failed.");
        exit(1);
    }

    strcpy(newSubscriber->email, email);
    newSubscriber->next = NULL;

    if (head == NULL) {
        head = newSubscriber;
        tail = newSubscriber;
    } else {
        tail->next = newSubscriber;
        tail = newSubscriber;
    }

    printf("Subscriber added successfully.\n");
}

void viewSubscribers() {
    if (head == NULL) {
        printf("No subscribers yet.\n");
        return;
    }

    printf("Subscribers:\n");

    Subscriber* currentSubscriber = head;

    while (currentSubscriber != NULL) {
        printf("%s\n", currentSubscriber->email);
        currentSubscriber = currentSubscriber->next;
    }
}

void removeSubscriber() {
    if (head == NULL) {
        printf("No subscribers to remove.\n");
        return;
    }

    char email[50];
    printf("Enter email of subscriber to remove: ");
    scanf("%s", email);

    Subscriber* currentSubscriber = head;
    Subscriber* previousSubscriber = NULL;

    while (currentSubscriber != NULL) {
        if (strcmp(currentSubscriber->email, email) == 0) {
            if (currentSubscriber == head) {
                head = currentSubscriber->next;
            } else if (currentSubscriber == tail) {
                tail = previousSubscriber;
                previousSubscriber->next = NULL;
            } else {
                previousSubscriber->next = currentSubscriber->next;
            }

            free(currentSubscriber);
            printf("Subscriber removed successfully.\n");
            return;
        }

        previousSubscriber = currentSubscriber;
        currentSubscriber = currentSubscriber->next;
    }

    printf("Subscriber not found.\n");
}

void clearList() {
    Subscriber* currentSubscriber = head;
    Subscriber* nextSubscriber = NULL;

    while (currentSubscriber != NULL) {
        nextSubscriber = currentSubscriber->next;
        free(currentSubscriber);
        currentSubscriber = nextSubscriber;
    }

    head = NULL;
    tail = NULL;

    printf("List cleared successfully.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Add subscriber\n");
        printf("2. View subscribers\n");
        printf("3. Remove subscriber\n");
        printf("4. Clear list\n");
        printf("5. Exit\n");
        printf("> ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSubscriber();
                break;
            case 2:
                viewSubscribers();
                break;
            case 3:
                removeSubscriber();
                break;
            case 4:
                clearList();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}