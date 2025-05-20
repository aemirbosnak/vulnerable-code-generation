//Code Llama-13B DATASET v1.0 Category: Mailing list manager ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

// Structure to represent a mailing list
struct mailing_list {
    char* name;
    char* email;
    int subscribed;
    struct mailing_list* next;
};

// Function to add a new mailing list
void add_mailing_list(struct mailing_list** head, char* name, char* email) {
    struct mailing_list* new_mailing_list = malloc(sizeof(struct mailing_list));
    new_mailing_list->name = strdup(name);
    new_mailing_list->email = strdup(email);
    new_mailing_list->subscribed = 0;
    new_mailing_list->next = *head;
    *head = new_mailing_list;
}

// Function to print the mailing list
void print_mailing_list(struct mailing_list* head) {
    printf("Mailing list: \n");
    struct mailing_list* current = head;
    while (current != NULL) {
        printf("%s: %s (%s)\n", current->name, current->email, current->subscribed ? "subscribed" : "not subscribed");
        current = current->next;
    }
}

// Function to subscribe to a mailing list
void subscribe_mailing_list(struct mailing_list** head, char* name) {
    struct mailing_list* current = *head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            current->subscribed = 1;
            break;
        }
        current = current->next;
    }
}

// Function to unsubscribe from a mailing list
void unsubscribe_mailing_list(struct mailing_list** head, char* name) {
    struct mailing_list* current = *head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            current->subscribed = 0;
            break;
        }
        current = current->next;
    }
}

// Function to send a message to the subscribed members of a mailing list
void send_message_mailing_list(struct mailing_list* head, char* message) {
    struct mailing_list* current = head;
    while (current != NULL) {
        if (current->subscribed) {
            printf("%s: %s\n", current->name, message);
        }
        current = current->next;
    }
}

int main() {
    struct mailing_list* head = NULL;

    // Add a few mailing lists
    add_mailing_list(&head, "John Doe", "johndoe@example.com");
    add_mailing_list(&head, "Jane Doe", "janedoe@example.com");
    add_mailing_list(&head, "Bob Smith", "bobsmith@example.com");

    // Print the mailing list
    print_mailing_list(head);

    // Subscribe John Doe to the mailing list
    subscribe_mailing_list(&head, "John Doe");

    // Unsubscribe Bob Smith from the mailing list
    unsubscribe_mailing_list(&head, "Bob Smith");

    // Print the mailing list again
    print_mailing_list(head);

    // Send a message to the subscribed members of the mailing list
    send_message_mailing_list(head, "Hello, this is a test message");

    return 0;
}