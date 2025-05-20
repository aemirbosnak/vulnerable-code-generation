//FormAI DATASET v1.0 Category: Mailing list manager ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char email[50];
    struct node *next;
} Node;

Node *make_node(char *email) {
    Node *new_node = malloc(sizeof(Node));
    strcpy(new_node->email, email);
    new_node->next = NULL;
    return new_node;
}

void add_to_list(char *email, Node **list) {
    if (*list == NULL) {
        *list = make_node(email);
    } else {
        Node *current = *list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = make_node(email);
    }
}

void print_list(Node *list) {
    Node *current = list;
    while (current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

void remove_from_list(char *email, Node **list) {
    Node *current = *list;
    Node *previous = NULL;

    while (current != NULL && strcmp(current->email, email) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Email not found in list.\n");
    } else if (previous == NULL) {
        *list = current->next;
        free(current);
    } else {
        previous->next = current->next;
        free(current);
    }
}

void free_list(Node **list) {
    Node *current = *list;
    Node *temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    *list = NULL;
}

int main() {
    Node *list = NULL;
    int choice;
    char email[50];

    while (1) {
        printf("1. Add email\n");
        printf("2. Remove email\n");
        printf("3. Print list\n");
        printf("4. Quit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter email: ");
                scanf("%s", email);
                add_to_list(email, &list);
                break;
            case 2:
                printf("Enter email: ");
                scanf("%s", email);
                remove_from_list(email, &list);
                break;
            case 3:
                print_list(list);
                break;
            case 4:
                free_list(&list);
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}