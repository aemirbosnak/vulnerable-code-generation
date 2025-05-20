//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Node {
    char data;
    struct Node *next;
};

struct Node *create_node(char data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_end(struct Node **head_ref, char data) {
    struct Node *new_node = create_node(data);
    struct Node *last_node = *head_ref;

    if (*head_ref == NULL) {
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }

    while (last_node->next!= NULL) {
        last_node = last_node->next;
    }

    last_node->next = new_node;
    new_node->next = NULL;
}

void print_list(struct Node *node) {
    while (node!= NULL) {
        printf("%c ", node->data);
        node = node->next;
    }
}

struct Node *search_list(struct Node *head, char search_char) {
    struct Node *current_node = head;

    while (current_node!= NULL) {
        if (current_node->data == search_char) {
            return current_node;
        }
        current_node = current_node->next;
    }

    return NULL;
}

int main() {
    struct Node *head = NULL;

    insert_at_end(&head, 'a');
    insert_at_end(&head, 'b');
    insert_at_end(&head, 'c');
    insert_at_end(&head, 'd');
    insert_at_end(&head, 'e');

    printf("\nList after insertion: ");
    print_list(head);

    struct Node *search_result = search_list(head, 'c');

    if (search_result!= NULL) {
        printf("\nSearch result: %c", search_result->data);
    } else {
        printf("\nSearch result: Not found");
    }

    return 0;
}