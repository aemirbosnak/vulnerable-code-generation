//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void print_list(Node* head) {
    while (head!= NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int is_empty(Node* head) {
    return head == NULL;
}

void push(Node** head_ref, int new_data) {
    Node* new_node = create_node(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void pop(Node** head_ref) {
    Node* temp = *head_ref;
    *head_ref = temp->next;
    free(temp);
}

int peek(Node* head) {
    return head->data;
}

int main() {
    Node* head = NULL;

    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);

    printf("Linked List: ");
    print_list(head);

    printf("Peek: %d\n", peek(head));

    pop(&head);
    printf("Linked List after popping first element: ");
    print_list(head);

    pop(&head);
    printf("Linked List after popping second element: ");
    print_list(head);

    pop(&head);
    printf("Linked List after popping third element: ");
    print_list(head);

    pop(&head);
    printf("Linked List after popping fourth element: ");
    print_list(head);

    pop(&head);
    printf("Linked List after popping fifth element: ");
    print_list(head);

    return 0;
}