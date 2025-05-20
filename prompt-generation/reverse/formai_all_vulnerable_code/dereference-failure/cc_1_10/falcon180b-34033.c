//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void add_node(Node** head_ref, int data) {
    Node* new_node = create_node(data);
    Node* temp = *head_ref;
    if (*head_ref == NULL) {
        new_node->next = NULL;
        *head_ref = new_node;
    } else {
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void print_list(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    add_node(&head, 4);

    print_list(head);

    Node* temp = head;
    while (temp!= NULL) {
        if (temp->data == 3) {
            Node* next_node = temp->next;
            free(temp);
            temp = next_node;
        } else {
            temp = temp->next;
        }
    }

    print_list(head);

    return 0;
}