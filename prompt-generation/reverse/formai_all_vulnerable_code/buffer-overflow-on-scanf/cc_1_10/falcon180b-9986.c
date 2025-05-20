//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Subscriber;

void add_subscriber(Subscriber *subscribers, int *num_subscribers) {
    printf("Enter your name: ");
    scanf("%s", (*subscribers).name);
    printf("Enter your email address: ");
    scanf("%s", (*subscribers).email);

    (*num_subscribers)++;
}

void remove_subscriber(Subscriber *subscribers, int *num_subscribers) {
    printf("Enter the email address of the subscriber you want to remove: ");
    scanf("%s", subscribers[*num_subscribers - 1].email);

    (*num_subscribers)--;
}

void send_email(Subscriber *subscribers, int num_subscribers) {
    printf("Sending email to %d subscribers...\n", num_subscribers);
    for (int i = 0; i < num_subscribers; i++) {
        printf("Sending email to %s <%s>\n", subscribers[i].name, subscribers[i].email);
    }
}

int main() {
    Subscriber subscribers[100];
    int num_subscribers = 0;

    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. Send email\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_subscribers >= 100) {
                printf("Sorry, the mailing list is full.\n");
                break;
            }
            add_subscriber(subscribers, &num_subscribers);
            break;
        case 2:
            if (num_subscribers == 0) {
                printf("Sorry, the mailing list is empty.\n");
                break;
            }
            remove_subscriber(subscribers, &num_subscribers);
            break;
        case 3:
            send_email(subscribers, num_subscribers);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}