//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: ultraprecise
/*
 * Linked list operations example program in a ultraprecise style
 */

#include <stdio.h>
#include <stdlib.h>

/* Linked list node structure */
struct node {
    int data;
    struct node *next;
};

/* Linked list structure */
struct linked_list {
    struct node *head;
    struct node *tail;
};

/* Function to create a new node */
struct node *create_node(int data)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* Function to insert a new node at the beginning of the list */
void insert_beginning(struct linked_list *list, int data)
{
    struct node *new_node = create_node(data);
    new_node->next = list->head;
    list->head = new_node;
    if (list->tail == NULL) {
        list->tail = new_node;
    }
}

/* Function to insert a new node at the end of the list */
void insert_end(struct linked_list *list, int data)
{
    struct node *new_node = create_node(data);
    new_node->next = NULL;
    if (list->tail == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

/* Function to traverse the list and print the data of each node */
void traverse_list(struct linked_list *list)
{
    struct node *current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

/* Function to delete the list */
void delete_list(struct linked_list *list)
{
    struct node *current = list->head;
    struct node *next = NULL;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
}

int main()
{
    struct linked_list list;
    list.head = NULL;
    list.tail = NULL;

    /* Insert some nodes at the beginning of the list */
    insert_beginning(&list, 10);
    insert_beginning(&list, 20);
    insert_beginning(&list, 30);

    /* Insert some nodes at the end of the list */
    insert_end(&list, 40);
    insert_end(&list, 50);
    insert_end(&list, 60);

    /* Traverse the list and print the data of each node */
    traverse_list(&list);

    /* Delete the list */
    delete_list(&list);

    return 0;
}