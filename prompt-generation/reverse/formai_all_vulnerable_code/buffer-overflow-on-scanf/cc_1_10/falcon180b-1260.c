//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAILS 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
} Subscriber;

Subscriber subscribers[MAX_EMAILS];
int num_subscribers = 0;

void add_subscriber() {
    if (num_subscribers >= MAX_EMAILS) {
        printf("Sorry, the mailing list is full.\n");
        return;
    }

    printf("Enter your name: ");
    scanf("%s", subscribers[num_subscribers].name);

    printf("Enter your email: ");
    scanf("%s", subscribers[num_subscribers].email);

    num_subscribers++;
    printf("Subscriber added successfully.\n");
}

void remove_subscriber() {
    if (num_subscribers == 0) {
        printf("The mailing list is empty.\n");
        return;
    }

    printf("Enter the name of the subscriber you want to remove: ");
    scanf("%s", subscribers[0].name);

    int i;
    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].name, subscribers[0].name) == 0) {
            strcpy(subscribers[i].name, "");
            strcpy(subscribers[i].email, "");
            num_subscribers--;
            printf("Subscriber removed successfully.\n");
            return;
        }
    }

    printf("Subscriber not found.\n");
}

void send_email() {
    if (num_subscribers == 0) {
        printf("The mailing list is empty.\n");
        return;
    }

    printf("Enter the subject of the email: ");
    scanf("%s", subscribers[0].email);

    printf("Enter the body of the email: ");
    scanf("%s", subscribers[0].email + strlen(subscribers[0].email));

    int i;
    for (i = 1; i < num_subscribers; i++) {
        strcat(subscribers[i].email, subscribers[0].email);
    }

    printf("Email sent to all subscribers.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add subscriber\n2. Remove subscriber\n3. Send email\n4. Exit\n");
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
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}