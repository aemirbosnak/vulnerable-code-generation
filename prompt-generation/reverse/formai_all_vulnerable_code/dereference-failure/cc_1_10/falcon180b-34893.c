//Falcon-180B DATASET v1.0 Category: Memory management ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node* next;
} node_t;

void* my_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(1);
    }
    return ptr;
}

void my_free(void* ptr) {
    free(ptr);
}

node_t* create_node(int data) {
    node_t* new_node = my_malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void add_node(node_t** head, int data) {
    node_t* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node_t* curr_node = *head;
    while (curr_node->next!= NULL) {
        curr_node = curr_node->next;
    }
    curr_node->next = new_node;
}

void print_list(node_t* head) {
    node_t* curr_node = head;
    while (curr_node!= NULL) {
        printf("%d -> ", curr_node->data);
        curr_node = curr_node->next;
    }
    printf("NULL\n");
}

int main() {
    node_t* head = NULL;
    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    print_list(head);

    node_t* curr_node = head;
    while (curr_node!= NULL) {
        if (curr_node->data == 2) {
            node_t* temp_node = curr_node->next;
            my_free(curr_node);
            curr_node = temp_node;
        } else {
            curr_node = curr_node->next;
        }
    }

    print_list(head);

    return 0;
}