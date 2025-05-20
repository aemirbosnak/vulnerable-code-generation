#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Node** top, int data) {
    Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

int pop(Node** top) {
    if (*top == NULL) {
        printf("Stack underflow\n");
        exit(1);
    }
    Node* temp = *top;
    int data = temp->data;
    *top = temp->next;
    free(temp);
    return data;
}

void towerOfHanoi(int n, Node** source, Node** target, Node** auxiliary) {
    if (n == 1) {
        push(target, pop(source));
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, target);
    push(target, pop(source));
    towerOfHanoi(n - 1, auxiliary, target, source);
}

int main() {
    int n = 3;
    Node* source = NULL;
    Node* target = NULL;
    Node* auxiliary = NULL;

    for (int i = n; i > 0; i--) {
        push(&source, i);
    }

    towerOfHanoi(n, &source, &target, &auxiliary);

    while (target != NULL) {
        printf("%d ", pop(&target));
    }

    return 0;
}
