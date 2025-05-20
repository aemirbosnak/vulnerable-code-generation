//Falcon-180B DATASET v1.0 Category: Educational ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Node structure definition
typedef struct node {
    char data;
    struct node* next;
} Node;

// Stack structure definition
typedef struct stack {
    Node* top;
} Stack;

// Push function to add an element to the top of the stack
void push(Stack* stack, char value) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Stack overflow!\n");
        exit(0);
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Pop function to remove and return the top element from the stack
char pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack underflow!\n");
        exit(0);
    }
    char value = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return value;
}

// Function to check if the given string is a palindrome
int isPalindrome(char* str) {
    int length = strlen(str);
    Stack stack;
    stack.top = NULL;
    for (int i = 0; i < length; i++) {
        if (isalpha(str[i])) {
            push(&stack, tolower(str[i]));
        }
    }
    while (stack.top!= NULL) {
        if (pop(&stack)!= tolower(str[length - 1])) {
            return 0;
        }
        length--;
    }
    return 1;
}

int main() {
    char string[100];
    printf("Enter a string: ");
    scanf("%s", string);
    if (isPalindrome(string)) {
        printf("%s is a palindrome.\n", string);
    } else {
        printf("%s is not a palindrome.\n", string);
    }
    return 0;
}