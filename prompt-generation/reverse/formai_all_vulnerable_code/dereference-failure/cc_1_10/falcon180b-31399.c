//Falcon-180B DATASET v1.0 Category: Educational ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int next;
} node;

node *head = NULL;

void push(int data) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    node *temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void pop() {
    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }

    node *temp = head;
    head = head->next;
    free(temp);
}

void display() {
    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }

    node *temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);

    display();

    pop();
    pop();

    display();

    return 0;
}