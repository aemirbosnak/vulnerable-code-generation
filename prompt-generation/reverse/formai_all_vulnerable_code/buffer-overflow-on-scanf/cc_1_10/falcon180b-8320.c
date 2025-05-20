//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 1000

typedef struct {
    char name[50];
    char email[100];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

void add_subscriber() {
    printf("Enter name: ");
    scanf("%s", subscribers[num_subscribers].name);
    printf("Enter email: ");
    scanf("%s", subscribers[num_subscribers].email);
    num_subscribers++;
    printf("Subscriber added.\n");
}

void remove_subscriber() {
    printf("Enter email to remove: ");
    char email[100];
    scanf("%s", email);
    int i;
    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            memmove(&subscribers[i], &subscribers[i+1], sizeof(Subscriber) * (num_subscribers - i - 1));
            num_subscribers--;
            printf("Subscriber removed.\n");
            return;
        }
    }
    printf("Subscriber not found.\n");
}

void send_email() {
    printf("Enter subject: ");
    char subject[100];
    scanf("%s", subject);
    printf("Enter message: ");
    char message[1000];
    scanf("%[^\n]", message);
    int i;
    for (i = 0; i < num_subscribers; i++) {
        printf("Sending email to %s (%s)...\n", subscribers[i].name, subscribers[i].email);
    }
}

int main() {
    int choice;
    while (1) {
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