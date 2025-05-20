//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100

typedef struct {
    char name[50];
    char email[100];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

void add_subscriber(char *name, char *email) {
    if (num_subscribers >= MAX_SUBSCRIBERS) {
        printf("Mailing list is full.\n");
        return;
    }
    strcpy(subscribers[num_subscribers].name, name);
    strcpy(subscribers[num_subscribers].email, email);
    num_subscribers++;
}

void remove_subscriber(char *email) {
    int i;
    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            memmove(&subscribers[i], &subscribers[i+1], (num_subscribers - i - 1) * sizeof(Subscriber));
            num_subscribers--;
            break;
        }
    }
}

void print_subscribers() {
    int i;
    printf("Subscribers:\n");
    for (i = 0; i < num_subscribers; i++) {
        printf("%s <%s>\n", subscribers[i].name, subscribers[i].email);
    }
}

int main() {
    char name[50], email[100];
    int choice, i;

    while (1) {
        printf("\n1. Add subscriber\n2. Remove subscriber\n3. Print subscribers\n4. Exit\n");
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
                printf("Enter email of subscriber to remove: ");
                scanf("%s", email);
                remove_subscriber(email);
                break;
            case 3:
                print_subscribers();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}