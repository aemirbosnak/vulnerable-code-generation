//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 1000
#define MAX_EMAIL_LEN 100

typedef struct {
    char email[MAX_EMAIL_LEN];
    int subscribed;
} subscriber;

subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

void add_subscriber(char* email) {
    int i;
    for(i = 0; i < num_subscribers; i++) {
        if(strcmp(subscribers[i].email, email) == 0) {
            printf("Subscriber already exists.\n");
            return;
        }
    }
    strcpy(subscribers[num_subscribers].email, email);
    subscribers[num_subscribers].subscribed = 1;
    num_subscribers++;
    printf("Subscriber added.\n");
}

void remove_subscriber(char* email) {
    int i;
    for(i = 0; i < num_subscribers; i++) {
        if(strcmp(subscribers[i].email, email) == 0) {
            subscribers[i].subscribed = 0;
            printf("Subscriber removed.\n");
            return;
        }
    }
    printf("Subscriber not found.\n");
}

void send_email(char* email) {
    int i;
    for(i = 0; i < num_subscribers; i++) {
        if(strcmp(subscribers[i].email, email) == 0 && subscribers[i].subscribed == 1) {
            printf("Email sent to %s.\n", email);
        }
    }
}

int main() {
    int choice;
    char email[MAX_EMAIL_LEN];

    do {
        printf("1. Add subscriber\n2. Remove subscriber\n3. Send email\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter email: ");
                scanf("%s", email);
                add_subscriber(email);
                break;
            case 2:
                printf("Enter email: ");
                scanf("%s", email);
                remove_subscriber(email);
                break;
            case 3:
                printf("Enter email: ");
                scanf("%s", email);
                send_email(email);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 4);

    return 0;
}