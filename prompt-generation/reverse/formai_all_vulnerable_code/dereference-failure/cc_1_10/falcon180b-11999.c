//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a node in the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the structure of a stack
typedef struct stack {
    Node* top;
} Stack;

// Define a function to push an element onto the stack
void push(Stack* s, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}

// Define a function to pop an element from the stack
int pop(Stack* s) {
    int data = s->top->data;
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    return data;
}

// Define a function to print the stack
void printStack(Stack* s) {
    Node* temp = s->top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Define a function to reverse a string
char* reverse(char* str) {
    int len = strlen(str);
    char* reversed = (char*)malloc(len + 1);
    char* start = str + len - 1;
    char* end = reversed;
    while (start >= str) {
        *end++ = *start--;
    }
    *end = '\0';
    return reversed;
}

// Define the main function
int main() {
    Stack s;
    s.top = NULL;

    // Push some elements onto the stack
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    // Print the stack
    printStack(&s);

    // Pop an element from the stack
    int popped = pop(&s);
    printf("Popped element: %d\n", popped);

    // Reverse a string
    char* str = "Sherlock Holmes";
    char* reversed = reverse(str);
    printf("Reversed string: %s\n", reversed);

    return 0;
}