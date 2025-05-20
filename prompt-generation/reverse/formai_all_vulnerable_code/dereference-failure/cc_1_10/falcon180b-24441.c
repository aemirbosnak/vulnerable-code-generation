//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of an email address and a name
#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

// Define the structure of a subscriber
typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Subscriber;

// Define the structure of a mailing list
typedef struct {
    int num_subscribers;
    Subscriber *subscribers;
} MailingList;

// Function to initialize a mailing list
MailingList *init_mailing_list() {
    MailingList *list = (MailingList *) malloc(sizeof(MailingList));
    list->num_subscribers = 0;
    list->subscribers = NULL;
    return list;
}

// Function to add a subscriber to a mailing list
void add_subscriber(MailingList *list, char *name, char *email) {
    Subscriber *sub = (Subscriber *) malloc(sizeof(Subscriber));
    strcpy(sub->name, name);
    strcpy(sub->email, email);
    list->subscribers = (Subscriber *) realloc(list->subscribers, list->num_subscribers * sizeof(Subscriber));
    list->subscribers[list->num_subscribers] = *sub;
    list->num_subscribers++;
}

// Function to remove a subscriber from a mailing list
void remove_subscriber(MailingList *list, char *email) {
    int i, j;
    for (i = 0; i < list->num_subscribers; i++) {
        if (!strcmp(list->subscribers[i].email, email)) {
            for (j = i; j < list->num_subscribers - 1; j++) {
                list->subscribers[j] = list->subscribers[j + 1];
            }
            list->num_subscribers--;
            break;
        }
    }
}

// Function to print a mailing list
void print_mailing_list(MailingList *list) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        printf("%s <%s>\n", list->subscribers[i].name, list->subscribers[i].email);
    }
}

// Function to send an email to all subscribers in a mailing list
void send_email(MailingList *list, char *subject, char *message) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        printf("Sending email to %s <%s>...\n", list->subscribers[i].name, list->subscribers[i].email);
    }
}

// Main function
int main() {
    MailingList *list = init_mailing_list();
    add_subscriber(list, "John Doe", "john.doe@example.com");
    add_subscriber(list, "Jane Doe", "jane.doe@example.com");
    print_mailing_list(list);
    remove_subscriber(list, "john.doe@example.com");
    print_mailing_list(list);
    send_email(list, "Test Email", "Hello, this is a test email!");
    return 0;
}