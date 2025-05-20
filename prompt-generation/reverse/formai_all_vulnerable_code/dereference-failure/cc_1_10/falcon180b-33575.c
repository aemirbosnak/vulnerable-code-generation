//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *head = NULL;

// Function to insert a node at the end of the list
void insert(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        Node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Function to delete a node with the given data
void delete(int data) {
    Node *temp = head;
    Node *prev = NULL;

    if (temp!= NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to search for a node with the given data
Node *search(int data) {
    Node *temp = head;

    while (temp!= NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

// Function to print the list
void print_list() {
    Node *temp = head;

    while (temp!= NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    print_list();

    delete(3);

    print_list();

    Node *result = search(4);

    if (result!= NULL) {
        printf("Found node with data %d\n", result->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}