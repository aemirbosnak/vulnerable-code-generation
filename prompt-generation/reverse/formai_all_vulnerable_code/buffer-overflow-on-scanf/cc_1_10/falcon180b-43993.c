//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAIL_LEN 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    struct node *next;
} node;

node *head = NULL;

void add_node(node *new_node) {
    if (head == NULL) {
        head = new_node;
        return;
    }

    node *curr_node = head;
    while (curr_node->next!= NULL) {
        curr_node = curr_node->next;
    }

    curr_node->next = new_node;
}

void print_list() {
    node *curr_node = head;
    while (curr_node!= NULL) {
        printf("Name: %s\n", curr_node->name);
        printf("Email: %s\n\n", curr_node->email);
        curr_node = curr_node->next;
    }
}

int main() {
    char input[100];

    while (1) {
        printf("Enter 'a' to add a contact, 'p' to print the list, or 'q' to quit: ");
        scanf("%s", input);

        if (strcmp(input, "a") == 0) {
            node *new_node = (node *) malloc(sizeof(node));

            printf("Enter name: ");
            scanf("%s", new_node->name);

            printf("Enter email: ");
            scanf("%s", new_node->email);

            add_node(new_node);
        } else if (strcmp(input, "p") == 0) {
            print_list();
        } else if (strcmp(input, "q") == 0) {
            break;
        } else {
            printf("Invalid input.\n");
        }
    }

    return 0;
}