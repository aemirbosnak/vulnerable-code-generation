//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 1000
#define MAX_EMAIL_LENGTH 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    int subscribed;
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

void add_subscriber() {
    printf("Enter subscriber name: ");
    scanf("%s", subscribers[num_subscribers].name);
    printf("Enter subscriber email: ");
    scanf("%s", subscribers[num_subscribers].email);
    subscribers[num_subscribers].subscribed = 1;
    num_subscribers++;
}

void remove_subscriber() {
    printf("Enter subscriber email to remove: ");
    char email[MAX_EMAIL_LENGTH];
    scanf("%s", email);
    int i;
    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            subscribers[i].subscribed = 0;
            break;
        }
    }
}

void send_email() {
    printf("Enter email subject: ");
    char subject[MAX_EMAIL_LENGTH];
    scanf("%s", subject);
    printf("Enter email body: ");
    char body[MAX_EMAIL_LENGTH];
    scanf("%s", body);
    int i;
    for (i = 0; i < num_subscribers; i++) {
        if (subscribers[i].subscribed) {
            sprintf(subject, "To: %s\r\nSubject: %s\r\n\r\n%s", subscribers[i].email, subject, body);
            system(subject);
        }
    }
}

void view_subscribers() {
    printf("Name\tEmail\tSubscribed\n");
    int i;
    for (i = 0; i < num_subscribers; i++) {
        printf("%s\t%s\t%d\n", subscribers[i].name, subscribers[i].email, subscribers[i].subscribed);
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Add subscriber\n2. Remove subscriber\n3. Send email\n4. View subscribers\n5. Exit\n");
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
                view_subscribers();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}