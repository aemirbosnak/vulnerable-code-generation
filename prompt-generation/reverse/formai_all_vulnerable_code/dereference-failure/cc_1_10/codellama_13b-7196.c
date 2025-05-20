//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void push(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void pop() {
    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

void peek() {
    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top of the stack: %d\n", head->data);
}

void display() {
    struct Node *temp = head;
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
    peek();
    pop();
    display();
    return 0;
}