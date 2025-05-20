//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBSCRIBERS 100
#define SUBSCRIBER_NAME_LENGTH 50

// Structure for a subscriber
typedef struct {
    char name[SUBSCRIBER_NAME_LENGTH];
    int next;
} Subscriber;

// Global variables
Subscriber list[MAX_SUBSCRIBERS];
int current_size = 0;

// Function prototypes
void display_help();
void add_subscriber();
void remove_subscriber();
void view_subscribers();
void print_subscriber(int index);

// Main function
int main() {
    char command[20];

    while (1) {
        printf("ListIntrospect v1.0\n"
               "--------------------\n"
               "Commands:\n"
               "  add <name>\n"
               "  remove <name>\n"
               "  view\n"
               "  help\n"
               "  quit\n"
               "Enter command: ");
        scanf("%s", command);

        // Remove newline character left in stdin by scanf
        getchar();

        if (strcmp(command, "add") == 0) {
            add_subscriber();
        } else if (strcmp(command, "remove") == 0) {
            char name[SUBSCRIBER_NAME_LENGTH];
            printf("Enter name to remove: ");
            scanf("%s", name);
            remove_subscriber(name);
        } else if (strcmp(command, "view") == 0) {
            view_subscribers();
        } else if (strcmp(command, "help") == 0) {
            display_help();
        } else if (strcmp(command, "quit") == 0) {
            printf("Quitting ListIntrospect...\n");
            break;
        } else {
            printf("Invalid command. Try again.\n");
        }
    }

    return 0;
}

// Function to display help message
void display_help() {
    printf("Help:\n"
           "  This command displays available commands and their usage.\n");
}

// Function to add a new subscriber
void add_subscriber() {
    if (current_size >= MAX_SUBSCRIBERS) {
        printf("Mailing list is full. Cannot add subscriber.\n");
        return;
    }

    printf("Enter name of new subscriber: ");
    scanf("%s", list[current_size].name);

    list[current_size].next = -1; // Mark this subscriber as the last one
    current_size++;

    printf("Subscriber added successfully.\n");
}

// Function to remove a subscriber by name
void remove_subscriber(char name[SUBSCRIBER_NAME_LENGTH]) {
    int i, j;

    for (i = 0; i < current_size; i++) {
        if (strcmp(list[i].name, name) == 0) {
            for (j = i; j < current_size - 1; j++) {
                list[j] = list[j + 1];
            }
            current_size--;
            printf("Subscriber removed successfully.\n");
            return;
        }
    }

    printf("Subscriber not found in the mailing list.\n");
}

// Function to display all subscribers in the mailing list
void view_subscribers() {
    int i;

    printf("Subscribers in the mailing list:\n");

    for (i = 0; i < current_size; i++) {
        print_subscriber(i);
    }
}

// Function to print a single subscriber's information
void print_subscriber(int index) {
    printf("%d. %s\n", index + 1, list[index].name);
}