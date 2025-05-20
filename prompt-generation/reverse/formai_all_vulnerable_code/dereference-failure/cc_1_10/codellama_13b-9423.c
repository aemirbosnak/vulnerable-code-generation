//Code Llama-13B DATASET v1.0 Category: Memory management ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

void push(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void pop() {
    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }

    Node *temp = head;
    head = head->next;
    free(temp);
}

void display() {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push(1);
    push(2);
    push(3);
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    return 0;
}