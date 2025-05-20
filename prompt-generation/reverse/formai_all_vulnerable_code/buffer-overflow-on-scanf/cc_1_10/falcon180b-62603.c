//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAILS 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
} Subscriber;

Subscriber subscribers[MAX_EMAILS];
int num_subscribers = 0;

void add_subscriber() {
    printf("Enter name: ");
    scanf("%s", subscribers[num_subscribers].name);
    printf("Enter email: ");
    scanf("%s", subscribers[num_subscribers].email);
    num_subscribers++;
}

void send_email(char* message) {
    printf("Sending email to %d subscribers...\n", num_subscribers);
    for (int i = 0; i < num_subscribers; i++) {
        printf("Sending email to %s (%s)\n", subscribers[i].name, subscribers[i].email);
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Add subscriber\n2. Send email\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_subscriber();
                break;
            case 2:
                send_email("Hello, world!");
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}