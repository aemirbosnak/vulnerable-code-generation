//Code Llama-13B DATASET v1.0 Category: Mailing list manager ; Style: rigorous
/* mailing_list.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function prototypes
void add_to_list(char* name, char* email, bool* is_subscribed);
void remove_from_list(char* name, char* email, bool* is_subscribed);
void subscribe_to_list(char* name, char* email, bool* is_subscribed);
void unsubscribe_from_list(char* name, char* email, bool* is_subscribed);
void print_list();

// Global variables
char* names[100];
char* emails[100];
bool is_subscribed[100];
int num_names = 0;

int main() {
    // Add some sample data
    add_to_list("Alice", "alice@example.com", true);
    add_to_list("Bob", "bob@example.com", true);
    add_to_list("Charlie", "charlie@example.com", false);

    // Demonstrate various operations
    printf("Before removal:\n");
    print_list();
    remove_from_list("Charlie", "charlie@example.com", false);
    printf("After removal:\n");
    print_list();
    subscribe_to_list("David", "david@example.com", false);
    printf("After subscription:\n");
    print_list();
    unsubscribe_from_list("Alice", "alice@example.com", true);
    printf("After unsubscription:\n");
    print_list();

    return 0;
}

// Function definitions
void add_to_list(char* name, char* email, bool* is_subscribed) {
    if (num_names < 100) {
        names[num_names] = name;
        emails[num_names] = email;
        is_subscribed[num_names] = is_subscribed;
        num_names++;
    }
}

void remove_from_list(char* name, char* email, bool* is_subscribed) {
    int i;
    for (i = 0; i < num_names; i++) {
        if (strcmp(names[i], name) == 0 && strcmp(emails[i], email) == 0 && is_subscribed[i] == is_subscribed) {
            names[i] = names[num_names - 1];
            emails[i] = emails[num_names - 1];
            is_subscribed[i] = is_subscribed[num_names - 1];
            num_names--;
            break;
        }
    }
}

void subscribe_to_list(char* name, char* email, bool* is_subscribed) {
    int i;
    for (i = 0; i < num_names; i++) {
        if (strcmp(names[i], name) == 0 && strcmp(emails[i], email) == 0) {
            is_subscribed[i] = true;
            break;
        }
    }
}

void unsubscribe_from_list(char* name, char* email, bool* is_subscribed) {
    int i;
    for (i = 0; i < num_names; i++) {
        if (strcmp(names[i], name) == 0 && strcmp(emails[i], email) == 0) {
            is_subscribed[i] = false;
            break;
        }
    }
}

void print_list() {
    int i;
    for (i = 0; i < num_names; i++) {
        printf("%s < %s > %s\n", names[i], emails[i], is_subscribed[i] ? "subscribed" : "unsubscribed");
    }
}