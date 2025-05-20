//Code Llama-13B DATASET v1.0 Category: Database Indexing System ; Style: recursive
// Unique C Database Indexing System example program in a recursive style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char* key;
    void* data;
    struct node* next;
};

struct node* create_node(char* key, void* data) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->key = key;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_node(struct node* head, struct node* new_node) {
    if (head == NULL) {
        head = new_node;
    } else if (strcmp(head->key, new_node->key) > 0) {
        new_node->next = head;
        head = new_node;
    } else {
        insert_node(head->next, new_node);
    }
}

void print_node(struct node* head) {
    if (head == NULL) {
        return;
    }
    printf("%s: %s\n", head->key, (char*)head->data);
    print_node(head->next);
}

int main() {
    struct node* head = NULL;
    struct node* new_node1 = create_node("apple", "red");
    struct node* new_node2 = create_node("banana", "yellow");
    struct node* new_node3 = create_node("orange", "orange");

    insert_node(head, new_node1);
    insert_node(head, new_node2);
    insert_node(head, new_node3);

    print_node(head);

    return 0;
}