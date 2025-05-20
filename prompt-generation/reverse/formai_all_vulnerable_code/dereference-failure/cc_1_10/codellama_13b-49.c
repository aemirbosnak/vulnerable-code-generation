//Code Llama-13B DATASET v1.0 Category: Mailing list manager ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store mailing list
typedef struct mailing_list {
    char name[50];
    char email[50];
    struct mailing_list *next;
} mailing_list_t;

// Function to add a new mailing list
void add_mailing_list(mailing_list_t **head, char *name, char *email) {
    mailing_list_t *new_mailing_list = (mailing_list_t *)malloc(sizeof(mailing_list_t));
    strcpy(new_mailing_list->name, name);
    strcpy(new_mailing_list->email, email);
    new_mailing_list->next = NULL;

    // If head is NULL, make new node the head
    if (*head == NULL) {
        *head = new_mailing_list;
    } else {
        // Otherwise, add new node to the end of the list
        mailing_list_t *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_mailing_list;
    }
}

// Function to remove a mailing list
void remove_mailing_list(mailing_list_t **head, char *name) {
    mailing_list_t *current = *head;
    mailing_list_t *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

// Function to search a mailing list
void search_mailing_list(mailing_list_t **head, char *name) {
    mailing_list_t *current = *head;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Name: %s\nEmail: %s\n", current->name, current->email);
            break;
        }
        current = current->next;
    }

    if (current == NULL) {
        printf("Name not found.\n");
    }
}

// Main function
int main() {
    mailing_list_t *head = NULL;

    // Add mailing lists
    add_mailing_list(&head, "John Doe", "johndoe@example.com");
    add_mailing_list(&head, "Jane Doe", "janedoe@example.com");
    add_mailing_list(&head, "Bob Smith", "bobsmith@example.com");

    // Search for a mailing list
    search_mailing_list(&head, "Jane Doe");

    // Remove a mailing list
    remove_mailing_list(&head, "Bob Smith");

    // Search for a mailing list again
    search_mailing_list(&head, "Bob Smith");

    return 0;
}