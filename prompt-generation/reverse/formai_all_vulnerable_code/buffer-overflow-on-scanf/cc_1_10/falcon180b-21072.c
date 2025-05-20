//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 1000

typedef struct {
    char name[50];
    char email[100];
} Subscriber;

Subscriber mailingList[MAX_LIST_SIZE];
int numSubscribers = 0;

void addSubscriber() {
    Subscriber newSubscriber;
    printf("Enter name: ");
    scanf("%s", newSubscriber.name);
    printf("Enter email: ");
    scanf("%s", newSubscriber.email);

    for (int i = 0; i < numSubscribers; i++) {
        if (strcmp(newSubscriber.email, mailingList[i].email) == 0) {
            printf("Subscriber already exists.\n");
            return;
        }
    }

    strcpy(mailingList[numSubscribers].name, newSubscriber.name);
    strcpy(mailingList[numSubscribers].email, newSubscriber.email);
    numSubscribers++;

    printf("Subscriber added.\n");
}

void removeSubscriber() {
    printf("Enter email to remove: ");
    char email[100];
    scanf("%s", email);

    for (int i = 0; i < numSubscribers; i++) {
        if (strcmp(email, mailingList[i].email) == 0) {
            for (int j = i; j < numSubscribers - 1; j++) {
                strcpy(mailingList[j].name, mailingList[j+1].name);
                strcpy(mailingList[j].email, mailingList[j+1].email);
            }
            numSubscribers--;
            printf("Subscriber removed.\n");
            return;
        }
    }

    printf("Subscriber not found.\n");
}

void sendEmail() {
    printf("Enter email subject: ");
    char subject[100];
    scanf("%s", subject);

    printf("Enter email body: ");
    char body[500];
    scanf("%[^\n]", body);

    printf("Enter recipient email: ");
    char recipient[100];
    scanf("%s", recipient);

    for (int i = 0; i < numSubscribers; i++) {
        if (strcmp(recipient, mailingList[i].email) == 0) {
            printf("Sending email to %s...\n", mailingList[i].name);
        }
    }
}

int main() {
    int choice;

    do {
        printf("Mailing list manager\n");
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. Send email\n");
        printf("4. Exit\n");
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
                sendEmail();
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