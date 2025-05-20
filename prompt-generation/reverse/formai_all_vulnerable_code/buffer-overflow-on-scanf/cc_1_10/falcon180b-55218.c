//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 1000
#define MAX_EMAIL_LENGTH 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

int subscriberCount = 0;
Subscriber subscribers[MAX_SUBSCRIBERS];

void addSubscriber() {
    printf("Enter name: ");
    scanf("%s", subscribers[subscriberCount].name);

    printf("Enter email: ");
    scanf("%s", subscribers[subscriberCount].email);

    subscriberCount++;
}

void removeSubscriber() {
    int index;

    printf("Enter subscriber index to remove: ");
    scanf("%d", &index);

    if (index >= 0 && index < subscriberCount) {
        memmove(&subscribers[index], &subscribers[index + 1], sizeof(Subscriber) * (subscriberCount - index - 1));
        subscriberCount--;
    } else {
        printf("Invalid index.\n");
    }
}

void listSubscribers() {
    int i;

    for (i = 0; i < subscriberCount; i++) {
        printf("%d. %s (%s)\n", i + 1, subscribers[i].name, subscribers[i].email);
    }
}

void sendEmail() {
    int i;

    printf("Enter subject: ");
    char subject[MAX_EMAIL_LENGTH];
    scanf("%s", subject);

    printf("Enter message: ");
    char message[MAX_EMAIL_LENGTH];
    scanf("%s", message);

    for (i = 0; i < subscriberCount; i++) {
        sprintf(message, "%s %s,\n\n%s", subscribers[i].name, subscribers[i].email, message);
        printf("Sending email to %s (%s)\n", subscribers[i].name, subscribers[i].email);
    }
}

int main() {
    int choice;

    do {
        printf("\nMailing List Manager\n");
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. List subscribers\n");
        printf("4. Send email\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSubscriber();
                break;
            case 2:
                removeSubscriber();
                break;
            case 3:
                listSubscribers();
                break;
            case 4:
                sendEmail();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}