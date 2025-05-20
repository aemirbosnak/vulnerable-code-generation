//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct fib_node {
    int data;
    struct fib_node *next;
} fib_node;

void print_list(fib_node *head) {
    fib_node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void fibonacci(int n, fib_node **head) {
    if (n <= 0) {
        *head = NULL;
        return;
    }

    if (*head == NULL) {
        fib_node *new_node = (fib_node *)malloc(sizeof(fib_node));
        new_node->data = 0;
        new_node->next = NULL;
        *head = new_node;
    }

    if (n == 1) {
        fib_node *new_node = (fib_node *)malloc(sizeof(fib_node));
        new_node->data = 1;
        new_node->next = *head;
        *head = new_node;
        return;
    }

    fibonacci(n - 1, head);
    fib_node *new_node = (fib_node *)malloc(sizeof(fib_node));
    new_node->data = (*head)->data + ((*head)->next)->data;
    new_node->next = *head;
    (*head)->next = new_node;
    *head = new_node;
}

int main() {
    fib_node *head = NULL;
    int n;

    printf("Enter the number of Fibonacci numbers to generate: ");
    scanf("%d", &n);

    fibonacci(n, &head);
    print_list(head);

    fib_node *current = head;
    while (current != NULL) {
        fib_node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}