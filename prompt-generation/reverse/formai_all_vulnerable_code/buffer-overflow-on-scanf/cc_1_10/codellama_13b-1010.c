//Code Llama-13B DATASET v1.0 Category: Mailing list manager ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100

typedef struct {
    char name[50];
    char email[50];
} Subscriber;

Subscriber subscribers[MAX_EMAILS];
int num_subscribers = 0;

void add_subscriber(char* name, char* email) {
    if (num_subscribers < MAX_EMAILS) {
        strcpy(subscribers[num_subscribers].name, name);
        strcpy(subscribers[num_subscribers].email, email);
        num_subscribers++;
    } else {
        printf("Mailing list is full, unable to add subscriber.\n");
    }
}

void remove_subscriber(char* name) {
    int i;
    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].name, name) == 0) {
            memmove(&subscribers[i], &subscribers[i+1], sizeof(Subscriber) * (num_subscribers - i - 1));
            num_subscribers--;
            break;
        }
    }
}

void send_email(char* subject, char* body, char* recipient) {
    printf("Sending email to %s...\n", recipient);
    printf("Subject: %s\n", subject);
    printf("%s\n", body);
}

void mailing_list_manager() {
    char name[50];
    char email[50];
    char action;
    char subject[50];
    char body[100];
    char recipient[50];

    while (1) {
        printf("Enter name: ");
        scanf("%s", name);
        printf("Enter email: ");
        scanf("%s", email);
        printf("Enter action (a - add, r - remove, s - send): ");
        scanf(" %c", &action);
        switch (action) {
            case 'a':
                add_subscriber(name, email);
                break;
            case 'r':
                remove_subscriber(name);
                break;
            case 's':
                printf("Enter subject: ");
                scanf("%s", subject);
                printf("Enter body: ");
                scanf("%s", body);
                printf("Enter recipient: ");
                scanf("%s", recipient);
                send_email(subject, body, recipient);
                break;
            default:
                printf("Invalid action.\n");
                break;
        }
        printf("\n");
    }
}

int main() {
    mailing_list_manager();
    return 0;
}