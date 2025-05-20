//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    struct node* next;
} node;

node* create_node(int data);
void add_node(node** head, int data);
int search_node(node* head, int data);

int main() {
    node* head = NULL;

    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    add_node(&head, 4);

    int search_data = 3;
    int result = search_node(head, search_data);

    if (result == 1) {
        printf("Node found!\n");
    } else {
        printf("Node not found.\n");
    }

    return 0;
}

node* create_node(int data) {
    node* new_node = (node*) malloc(sizeof(node));

    if (new_node == NULL) {
        printf("Memory error.\n");
        exit(1);
    }

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

void add_node(node** head, int data) {
    node* new_node = create_node(data);

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    node* temp = *head;

    while (temp->next!= NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
}

int search_node(node* head, int data) {
    node* temp = head;

    while (temp!= NULL) {
        if (temp->data == data) {
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}