//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    struct node *next;
} node;

node *head = NULL;

void add_node(char *name, char *email) {
    node *new_node = (node *)malloc(sizeof(node));
    strcpy(new_node->name, name);
    strcpy(new_node->email, email);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        node *current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void print_list() {
    node *current = head;
    while (current!= NULL) {
        printf("Name: %s\nEmail: %s\n", current->name, current->email);
        current = current->next;
    }
}

void delete_node(char *email) {
    node *current = head;
    node *previous = NULL;

    while (current!= NULL) {
        if (strcmp(current->email, email) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

int main() {
    char choice;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];

    do {
        printf("Enter 'a' to add a contact, 'p' to print the list, 'd' to delete a contact, or 'q' to quit: ");
        scanf("%c", &choice);

        switch (choice) {
            case 'a':
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                add_node(name, email);
                break;
            case 'p':
                print_list();
                break;
            case 'd':
                printf("Enter email to delete: ");
                scanf("%s", email);
                delete_node(email);
                break;
            case 'q':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 'q');

    return 0;
}