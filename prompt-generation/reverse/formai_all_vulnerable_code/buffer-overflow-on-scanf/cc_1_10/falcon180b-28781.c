//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 1000
#define MAX_EMAIL_LEN 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

void add_subscriber(char* name, char* email) {
    if (num_subscribers >= MAX_SUBSCRIBERS) {
        printf("Error: Maximum number of subscribers reached.\n");
        return;
    }

    strncpy(subscribers[num_subscribers].name, name, MAX_NAME_LEN);
    strncpy(subscribers[num_subscribers].email, email, MAX_EMAIL_LEN);
    num_subscribers++;

    printf("Subscriber added successfully.\n");
}

void remove_subscriber(char* email) {
    int i;
    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            memmove(&subscribers[i], &subscribers[i+1], sizeof(Subscriber) * (num_subscribers - i - 1));
            num_subscribers--;
            printf("Subscriber removed successfully.\n");
            return;
        }
    }

    printf("Subscriber not found.\n");
}

void list_subscribers() {
    int i;
    for (i = 0; i < num_subscribers; i++) {
        printf("%d. %s <%s>\n", i+1, subscribers[i].name, subscribers[i].email);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add Subscriber\n");
        printf("2. Remove Subscriber\n");
        printf("3. List Subscribers\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", subscribers[num_subscribers].name);
                printf("Enter email: ");
                scanf("%s", subscribers[num_subscribers].email);
                add_subscriber(subscribers[num_subscribers].name, subscribers[num_subscribers].email);
                break;
            case 2:
                printf("Enter email to remove: ");
                scanf("%s", subscribers[num_subscribers].email);
                remove_subscriber(subscribers[num_subscribers].email);
                break;
            case 3:
                list_subscribers();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}