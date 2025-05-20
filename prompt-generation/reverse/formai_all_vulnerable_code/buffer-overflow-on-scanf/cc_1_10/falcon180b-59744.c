//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 1000
#define SUBSCRIBER_NAME_LENGTH 100
#define EMAIL_LENGTH 100

typedef struct {
    char name[SUBSCRIBER_NAME_LENGTH];
    char email[EMAIL_LENGTH];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int numSubscribers;

void addSubscriber() {
    char name[SUBSCRIBER_NAME_LENGTH];
    char email[EMAIL_LENGTH];

    printf("Enter subscriber name: ");
    scanf("%s", name);

    printf("Enter subscriber email: ");
    scanf("%s", email);

    strcpy(subscribers[numSubscribers].name, name);
    strcpy(subscribers[numSubscribers].email, email);

    numSubscribers++;
}

void removeSubscriber() {
    char email[EMAIL_LENGTH];

    printf("Enter subscriber email to remove: ");
    scanf("%s", email);

    int i;
    for (i = 0; i < numSubscribers; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            break;
        }
    }

    if (i == numSubscribers) {
        printf("Subscriber not found.\n");
    } else {
        numSubscribers--;
        subscribers[i] = subscribers[numSubscribers];
    }
}

void sendEmail() {
    char subject[100];
    char body[1000];

    printf("Enter email subject: ");
    scanf("%s", subject);

    printf("Enter email body: ");
    scanf("%[^\n]", body);

    int i;
    for (i = 0; i < numSubscribers; i++) {
        sprintf(body + strlen(body), "\n\nTo: %s <%s>\n", subscribers[i].name, subscribers[i].email);
    }

    system("mail -s \"$subject\" \"$body\"");
}

int main() {
    int choice;

    do {
        printf("\nMailing List Manager\n");
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. Send email\n");
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
                sendEmail();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}