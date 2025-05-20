//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
} Subscriber;

Subscriber list[MAX_LIST_SIZE];
int num_subscribers = 0;

void add_subscriber() {
    Subscriber new_subscriber;
    printf("Enter name: ");
    scanf("%s", new_subscriber.name);
    printf("Enter email: ");
    scanf("%s", new_subscriber.email);

    if (num_subscribers == MAX_LIST_SIZE) {
        printf("Sorry, list is full.\n");
        return;
    }

    list[num_subscribers] = new_subscriber;
    num_subscribers++;

    printf("Subscriber added successfully.\n");
}

void remove_subscriber() {
    char name[MAX_NAME_LENGTH];
    printf("Enter name to remove: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(list[i].name, name) == 0) {
            printf("Subscriber removed successfully.\n");
            num_subscribers--;
            return;
        }
    }

    printf("Subscriber not found.\n");
}

void send_email() {
    char subject[MAX_NAME_LENGTH];
    char message[MAX_NAME_LENGTH];

    printf("Enter subject: ");
    scanf("%s", subject);
    printf("Enter message: ");
    scanf("%s", message);

    printf("Sending email to %d subscribers...\n", num_subscribers);

    int i;
    for (i = 0; i < num_subscribers; i++) {
        printf("Sending email to %s (%s)...\n", list[i].name, list[i].email);
    }
}

int main() {
    int choice;

    do {
        printf("\nMailing List Manager\n");
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. Send email\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_subscriber();
                break;
            case 2:
                remove_subscriber();
                break;
            case 3:
                send_email();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}