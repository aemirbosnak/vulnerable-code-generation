//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
    char name[50];
    char email[100];
} Subscriber;

Subscriber list[MAX_SIZE];
int count = 0;

bool isEmailValid(char *email) {
    // Email validation logic here
    // ...
    return true;
}

void addSubscriber() {
    Subscriber newSubscriber;
    printf("Enter subscriber name: ");
    scanf("%s", newSubscriber.name);
    printf("Enter subscriber email: ");
    scanf("%s", newSubscriber.email);

    // Check for duplicate entry
    for (int i = 0; i < count; i++) {
        if (strcmp(list[i].email, newSubscriber.email) == 0) {
            printf("Subscriber already exists!\n");
            return;
        }
    }

    // Add new subscriber
    list[count++] = newSubscriber;
    printf("Subscriber added successfully!\n");
}

void removeSubscriber() {
    char email[100];
    int index;

    printf("Enter email of subscriber to be removed: ");
    scanf("%s", email);

    // Search for subscriber with given email
    for (int i = 0; i < count; i++) {
        if (strcmp(list[i].email, email) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Subscriber not found!\n");
        return;
    }

    // Remove subscriber
    for (int i = index; i < count - 1; i++) {
        list[i] = list[i + 1];
    }

    count--;
    printf("Subscriber removed successfully!\n");
}

void viewSubscribers() {
    printf("Subscribers:\n");

    for (int i = 0; i < count; i++) {
        printf("%d. %s - %s\n", i + 1, list[i].name, list[i].email);
    }
}

int main() {
    int choice;

    while (true) {
        printf("\nMailing List Manager\n");
        printf("1. Add Subscriber\n");
        printf("2. Remove Subscriber\n");
        printf("3. View Subscribers\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSubscriber();
                break;
            case 2:
                removeSubscriber();
                break;
            case 3:
                viewSubscribers();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}