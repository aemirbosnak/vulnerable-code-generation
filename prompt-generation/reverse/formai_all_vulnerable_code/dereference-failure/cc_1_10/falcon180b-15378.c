//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SUBSCRIBERS 1000
#define MAX_EMAIL_LENGTH 100

// Subscriber data structure
typedef struct {
    char name[MAX_EMAIL_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} subscriber;

// Mailing list data structure
typedef struct {
    subscriber *subscribers;
    int num_subscribers;
} mailing_list;

// Function to create a new subscriber
subscriber *create_subscriber(char *name, char *email) {
    subscriber *new_subscriber = (subscriber *)malloc(sizeof(subscriber));
    strncpy(new_subscriber->name, name, MAX_EMAIL_LENGTH);
    strncpy(new_subscriber->email, email, MAX_EMAIL_LENGTH);
    return new_subscriber;
}

// Function to create a new mailing list
mailing_list *create_mailing_list() {
    mailing_list *new_mailing_list = (mailing_list *)malloc(sizeof(mailing_list));
    new_mailing_list->subscribers = NULL;
    new_mailing_list->num_subscribers = 0;
    return new_mailing_list;
}

// Function to add a subscriber to the mailing list
void add_subscriber(mailing_list *mailing_list, char *name, char *email) {
    subscriber *new_subscriber = create_subscriber(name, email);
    mailing_list->subscribers = (subscriber *)realloc(mailing_list->subscribers, sizeof(subscriber) * (mailing_list->num_subscribers + 1));
    mailing_list->subscribers[mailing_list->num_subscribers] = *new_subscriber;
    mailing_list->num_subscribers++;
}

// Function to remove a subscriber from the mailing list
void remove_subscriber(mailing_list *mailing_list, char *email) {
    int i;
    for (i = 0; i < mailing_list->num_subscribers; i++) {
        if (strcmp(mailing_list->subscribers[i].email, email) == 0) {
            int j;
            for (j = i; j < mailing_list->num_subscribers - 1; j++) {
                mailing_list->subscribers[j] = mailing_list->subscribers[j + 1];
            }
            mailing_list->num_subscribers--;
            break;
        }
    }
}

// Function to send an email to all subscribers
void send_email(mailing_list *mailing_list, char *subject, char *message) {
    int i;
    for (i = 0; i < mailing_list->num_subscribers; i++) {
        printf("Sending email to %s (%s)\n", mailing_list->subscribers[i].name, mailing_list->subscribers[i].email);
    }
}

// Main function
int main() {
    mailing_list *mailing_list = create_mailing_list();
    add_subscriber(mailing_list, "John Doe", "john.doe@example.com");
    add_subscriber(mailing_list, "Jane Doe", "jane.doe@example.com");
    send_email(mailing_list, "Test Email", "This is a test email.");
    remove_subscriber(mailing_list, "john.doe@example.com");
    send_email(mailing_list, "Another Test Email", "This is another test email.");
    return 0;
}