//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: genius
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node* add_to_list(Node* head, int data) {
    Node* new_node = create_node(data);
    new_node->next = head;
    head = new_node;
    return head;
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    Node* head = NULL;
    int num, i;

    printf("Enter number of elements in the list: ");
    scanf("%d", &num);

    printf("Enter %d integers: ", num);

    for (i = 0; i < num; i++) {
        scanf("%d", &num);
        head = add_to_list(head, num);
    }

    printf("\nFactorial of each number: \n");

    Node* current = head;

    while (current != NULL) {
        printf("%d: %d\n", current->data, factorial(current->data));
        current = current->next;
    }

    return 0;
}