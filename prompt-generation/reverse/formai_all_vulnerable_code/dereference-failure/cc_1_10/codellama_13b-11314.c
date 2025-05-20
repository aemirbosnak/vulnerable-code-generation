//Code Llama-13B DATASET v1.0 Category: Mailing list manager ; Style: thoughtful
/*
 * mailinglist.c
 *
 * A simple mailing list manager program
 *
 * Usage: mailinglist [command] [arguments]
 *
 * Commands:
 *   - add [email] [name] [list]  Add a new subscriber to a list
 *   - remove [email] [list]    Remove a subscriber from a list
 *   - list [list]             List all subscribers in a list
 *   - help                    Display this help message
 *
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Struct to represent a subscriber
typedef struct {
    char email[100];
    char name[100];
    bool subscribed;
} Subscriber;

// Struct to represent a list
typedef struct {
    char name[100];
    Subscriber *subscribers;
    int num_subscribers;
} List;

// Function to add a subscriber to a list
void add_subscriber(List *list, Subscriber *subscriber) {
    list->subscribers[list->num_subscribers] = *subscriber;
    list->num_subscribers++;
}

// Function to remove a subscriber from a list
void remove_subscriber(List *list, char *email) {
    for (int i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            list->subscribers[i] = list->subscribers[list->num_subscribers - 1];
            list->num_subscribers--;
            return;
        }
    }
}

// Function to list all subscribers in a list
void list_subscribers(List *list) {
    for (int i = 0; i < list->num_subscribers; i++) {
        printf("%s (%s)\n", list->subscribers[i].name, list->subscribers[i].email);
    }
}

int main(int argc, char *argv[]) {
    // Initialize a list
    List list = { "My List", NULL, 0 };

    // Parse command line arguments
    if (argc < 3) {
        printf("Usage: mailinglist [command] [arguments]\n");
        return 1;
    }

    // Add a subscriber
    if (strcmp(argv[1], "add") == 0) {
        // Add a new subscriber
        Subscriber subscriber = { argv[2], argv[3], true };
        add_subscriber(&list, &subscriber);
    }

    // Remove a subscriber
    if (strcmp(argv[1], "remove") == 0) {
        // Remove a subscriber
        remove_subscriber(&list, argv[2]);
    }

    // List all subscribers
    if (strcmp(argv[1], "list") == 0) {
        // List all subscribers
        list_subscribers(&list);
    }

    // Display help message
    if (strcmp(argv[1], "help") == 0) {
        printf("Usage: mailinglist [command] [arguments]\n");
        printf("Commands:\n");
        printf("  add [email] [name] [list]  Add a new subscriber to a list\n");
        printf("  remove [email] [list]    Remove a subscriber from a list\n");
        printf("  list [list]             List all subscribers in a list\n");
        printf("  help                    Display this help message\n");
    }

    return 0;
}