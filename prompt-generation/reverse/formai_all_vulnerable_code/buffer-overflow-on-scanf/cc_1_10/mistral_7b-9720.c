//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SUBSCRIBERS 1000

typedef struct {
    char name[50];
    char email[100];
} Subscriber;

void add_subscriber(Subscriber subscribers[], int *count, char *name, char *email);
void remove_subscriber(Subscriber subscribers[], int *count, char *name);
void print_subscribers(Subscriber subscribers[], int count);

int main() {
    Subscriber mad_scientist_subscribers[MAX_SUBSCRIBERS];
    int subscriber_count = 0;

    printf("Welcome, mad scientist!\n");
    printf("Your very own mailing list manager is now at your service!\n");
    printf("Let's add some unsuspecting victims, I mean, subscribers...\n");

    while (true) {
        char command[20];
        char name[50];
        char email[100];

        printf("Enter a command (add, remove, print, or quit): ");
        scanf("%s", command);

        switch (command[0]) {
            case 'a':
                printf("Enter a name: ");
                scanf("%s", name);
                printf("Enter an email: ");
                scanf("%s", email);
                add_subscriber(mad_scientist_subscribers, &subscriber_count, name, email);
                break;

            case 'r':
                printf("Enter a name to remove: ");
                scanf("%s", name);
                remove_subscriber(mad_scientist_subscribers, &subscriber_count, name);
                break;

            case 'p':
                printf("Here are the current subscribers:\n");
                print_subscribers(mad_scientist_subscribers, subscriber_count);
                break;

            case 'q':
                printf("Quitting the program...\n");
                exit(0);

            default:
                printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}

void add_subscriber(Subscriber subscribers[], int *count, char *name, char *email) {
    if (*count >= MAX_SUBSCRIBERS) {
        printf("Maximum number of subscribers reached!\n");
        return;
    }

    strcpy(subscribers[*count].name, name);
    strcpy(subscribers[*count].email, email);
    (*count)++;
    printf("Subscriber %s added successfully!\n", name);
}

void remove_subscriber(Subscriber subscribers[], int *count, char *name) {
    int i;

    for (i = 0; i < *count; i++) {
        if (strcmp(subscribers[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                subscribers[j] = subscribers[j+1];
            }
            (*count)--;
            printf("Subscriber %s removed successfully!\n", name);
            return;
        }
    }

    printf("Subscriber %s not found.\n", name);
}

void print_subscribers(Subscriber subscribers[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%s (%s)\n", subscribers[i].name, subscribers[i].email);
    }
}