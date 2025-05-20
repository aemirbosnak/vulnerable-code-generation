//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} node_t;

typedef struct {
    node_t* head;
    int size;
} linked_list_t;

void init_linked_list(linked_list_t* list) {
    list->head = NULL;
    list->size = 0;
}

void add_element(linked_list_t* list, int data) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        node_t* temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    list->size++;
}

void remove_element(linked_list_t* list, int data) {
    node_t* temp = list->head;
    node_t* prev = NULL;

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found\n");
        return;
    }

    if (prev == NULL) {
        list->head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    list->size--;
}

void print_linked_list(linked_list_t* list) {
    node_t* temp = list->head;

    printf("Linked List:\n");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main() {
    linked_list_t list;
    init_linked_list(&list);

    add_element(&list, 1);
    add_element(&list, 2);
    add_element(&list, 3);

    print_linked_list(&list);

    remove_element(&list, 2);

    print_linked_list(&list);
}