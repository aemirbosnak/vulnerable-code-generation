//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct stack {
    Node* top;
    int size;
} Stack;

void init_stack(Stack* s) {
    s->top = NULL;
    s->size = 0;
}

bool is_empty(Stack* s) {
    return s->size == 0;
}

bool is_full(Stack* s) {
    return s->size == MAX_SIZE;
}

void push(Stack* s, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (is_full(s)) {
        printf("Stack is full!\n");
        return;
    }

    if (is_empty(s)) {
        s->top = new_node;
    } else {
        s->top->next = new_node;
    }

    s->size++;
}

int pop(Stack* s) {
    if (is_empty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }

    int data = s->top->data;
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);

    s->size--;
    return data;
}

void print_stack(Stack* s) {
    if (is_empty(s)) {
        printf("Stack is empty!\n");
        return;
    }

    Node* curr = s->top;
    while (curr!= NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Stack s;
    init_stack(&s);

    for (int i = 0; i < 10; i++) {
        int rand_num = rand() % 100;
        push(&s, rand_num);
    }

    printf("Stack after pushing 10 random numbers:\n");
    print_stack(&s);

    for (int i = 0; i < 5; i++) {
        int popped_num = pop(&s);
        printf("Popped number: %d\n", popped_num);
    }

    printf("Stack after popping 5 numbers:\n");
    print_stack(&s);

    return 0;
}