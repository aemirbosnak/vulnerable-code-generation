//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define MAX_EMAIL_LENGTH 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} subscriber;

subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

void add_subscriber() {
    printf("Enter name: ");
    scanf("%s", subscribers[num_subscribers].name);

    printf("Enter email: ");
    scanf("%s", subscribers[num_subscribers].email);

    num_subscribers++;
}

void send_email() {
    printf("Enter subject: ");
    char subject[100];
    scanf("%s", subject);

    printf("Enter message: ");
    char message[1000];
    scanf("%[^\n]s", message);

    printf("Enter recipient email: ");
    char recipient[MAX_EMAIL_LENGTH];
    scanf("%s", recipient);

    printf("Email sent to %s\n", recipient);
}

void view_subscribers() {
    printf("Name\tEmail\n");
    for (int i = 0; i < num_subscribers; i++) {
        printf("%s\t%s\n", subscribers[i].name, subscribers[i].email);
    }
}

int main() {
    int choice;

    do {
        printf("\n1. Add subscriber\n2. Send email\n3. View subscribers\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_subscriber();
                break;
            case 2:
                send_email();
                break;
            case 3:
                view_subscribers();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}