//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: invasive
/*
 * A unique C Data structures visualization example program
 * in an invasive style
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct list {
    struct node *head;
};

void insert_beginning(struct list *list, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
}

void insert_end(struct list *list, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        struct node *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void print_list(struct list *list) {
    struct node *current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct list list;
    list.head = NULL;

    insert_beginning(&list, 1);
    insert_beginning(&list, 2);
    insert_end(&list, 3);
    insert_end(&list, 4);
    insert_beginning(&list, 5);

    print_list(&list);

    return 0;
}