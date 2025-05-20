//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SUBSCRIBERS 100

typedef struct Subscriber {
    char name[50];
    char email[100];
} Subscriber;

Subscriber list[MAX_SUBSCRIBERS];
int num_subscribers = 0;

void add_subscriber(Subscriber new_subscriber) {
    if (num_subscribers >= MAX_SUBSCRIBERS) {
        printf("Mailing list is full. Cannot add subscriber.\n");
        return;
    }
    list[num_subscribers] = new_subscriber;
    num_subscribers++;
}

void remove_subscriber(int index) {
    if (index < 0 || index >= num_subscribers) {
        printf("Invalid index. Cannot remove subscriber.\n");
        return;
    }
    memmove(&list[index], &list[index + 1], (num_subscribers - index - 1) * sizeof(Subscriber));
    num_subscribers--;
}

void view_subscribers() {
    int i;
    printf("\nMailing List:\n");
    for (i = 0; i < num_subscribers; i++) {
        printf("%s (%s)\n", list[i].name, list[i].email);
    }
}

int main() {
    char name[50];
    char email[100];
    int choice, index;

    while (1) {
        printf("\nMailing List Manager:\n");
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. View subscribers\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter subscriber name: ");
                scanf("%s", name);
                printf("Enter subscriber email: ");
                scanf("%s", email);
                Subscriber new_subscriber = {.name = name, .email = email};
                add_subscriber(new_subscriber);
                break;
            case 2:
                printf("Enter index of subscriber to remove: ");
                scanf("%d", &index);
                remove_subscriber(index);
                break;
            case 3:
                view_subscribers();
                break;
            case 4:
                printf("Exiting mailing list manager.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}