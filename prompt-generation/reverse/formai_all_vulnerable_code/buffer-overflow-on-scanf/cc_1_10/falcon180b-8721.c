//Falcon-180B DATASET v1.0 Category: Educational ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *create_list(int n) {
    Node *head = NULL, *tail = NULL;
    int i;
    for (i = 0; i < n; i++) {
        Node *new_node = (Node *) malloc(sizeof(Node));
        new_node->data = i;
        new_node->next = NULL;
        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }
    return head;
}

void print_list(Node *head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void reverse_list(Node *head) {
    Node *prev = NULL, *curr = head;
    while (curr!= NULL) {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int main() {
    int n;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    Node *head = create_list(n);
    printf("Original list:\n");
    print_list(head);
    reverse_list(head);
    printf("Reversed list:\n");
    print_list(head);
    return 0;
}