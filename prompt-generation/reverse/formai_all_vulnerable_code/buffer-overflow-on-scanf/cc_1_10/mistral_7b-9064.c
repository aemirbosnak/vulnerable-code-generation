//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void print_list_recursive(Node* node) {
    if (node == NULL) {
        printf("Empty List\n");
        return;
    }

    printf("%d -> ", node->data);
    print_list_recursive(node->next);
}

Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node* insert_at_beginning_recursive(Node* head, Node* new_node) {
    if (head == NULL) {
        head = new_node;
        return head;
    } else {
        head->next = insert_at_beginning_recursive(head->next, new_node);
        return head;
    }
}

void free_list_recursive(Node* node) {
    if (node == NULL) {
        return;
    }

    free_list_recursive(node->next);
    free(node);
}

int fibonacci_recursive(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int main() {
    int num, i, fib_num;
    Node* head = NULL;

    printf("Enter number of elements in linked list: ");
    scanf("%d", &num);

    printf("Enter elements:\n");
    for (i = 0; i < num; i++) {
        int data;
        scanf("%d", &data);
        Node* new_node = create_node(data);
        head = insert_at_beginning_recursive(head, new_node);
    }

    printf("List: ");
    print_list_recursive(head);
    printf("\n");

    printf("Enter a number for fibonacci: ");
    scanf("%d", &num);
    fib_num = fibonacci_recursive(num);
    printf("Fibonacci of %d is %d\n", num, fib_num);

    free_list_recursive(head);

    return 0;
}