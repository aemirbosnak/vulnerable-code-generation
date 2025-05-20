//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Struct to hold each subscriber's information
typedef struct subscriber {
    char name[50];
    char email[100];
} Subscriber;

// Function to add a new subscriber
void add_subscriber(Subscriber *list, int *num_subscribers) {
    Subscriber new_subscriber;
    printf("Enter name: ");
    scanf("%s", new_subscriber.name);
    printf("Enter email: ");
    scanf("%s", new_subscriber.email);

    // Check if email is valid
    int i;
    for (i = 0; i < strlen(new_subscriber.email); i++) {
        if (!isalpha(new_subscriber.email[i]) &&!isdigit(new_subscriber.email[i]) && new_subscriber.email[i]!= '.' && new_subscriber.email[i]!= '_' && new_subscriber.email[i]!= '-') {
            printf("Invalid email format.\n");
            return;
        }
    }

    // Add new subscriber to list
    (*num_subscribers)++;
    list = realloc(list, sizeof(Subscriber) * (*num_subscribers));
    memcpy(&list[*num_subscribers - 1], &new_subscriber, sizeof(Subscriber));
}

// Function to remove a subscriber by email
void remove_subscriber(Subscriber *list, int *num_subscribers, char *email) {
    int i;
    for (i = 0; i < *num_subscribers; i++) {
        if (strcmp(list[i].email, email) == 0) {
            // Remove subscriber from list
            (*num_subscribers)--;
            memmove(&list[i], &list[i+1], sizeof(Subscriber) * (*num_subscribers - i - 1));
            break;
        }
    }
}

// Function to print subscriber list
void print_subscriber_list(Subscriber *list, int num_subscribers) {
    int i;
    for (i = 0; i < num_subscribers; i++) {
        printf("Name: %s\nEmail: %s\n", list[i].name, list[i].email);
    }
}

// Main function
int main() {
    Subscriber *list = NULL;
    int num_subscribers = 0;

    // Initialize list with example subscribers
    add_subscriber(list, &num_subscribers);
    add_subscriber(list, &num_subscribers);

    // Print initial subscriber list
    print_subscriber_list(list, num_subscribers);

    // Remove a subscriber by email
    char email[100];
    printf("Enter email to remove: ");
    scanf("%s", email);
    remove_subscriber(list, &num_subscribers, email);

    // Print updated subscriber list
    print_subscriber_list(list, num_subscribers);

    // Free memory
    free(list);

    return 0;
}