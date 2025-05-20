//Falcon-180B DATASET v1.0 Category: Recursive ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

typedef struct {
    char data;
    struct node* next;
} Node;

Node* stack[MAX_SIZE];
int top = -1;

void push(char data) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = (Node*)malloc(sizeof(Node));
    stack[top]->data = data;
    stack[top]->next = NULL;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    char data = stack[top]->data;
    Node* temp = stack[top];
    stack[top] = stack[top]->next;
    free(temp);
    return data;
}

void printStack() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    Node* temp = stack[top];
    while (temp!= NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverseString(char* str) {
    int len = strlen(str);
    char* newStr = (char*)malloc((len + 1) * sizeof(char));
    if (newStr == NULL) {
        printf("Memory error\n");
        return;
    }
    Node* stack[MAX_SIZE];
    int top = -1;
    for (int i = 0; i < len; i++) {
        push(str[i]);
    }
    for (int i = 0; i < len; i++) {
        newStr[i] = pop();
    }
    newStr[len] = '\0';
    printf("Reversed string: %s\n", newStr);
    free(newStr);
}

int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", str);
    reverseString(str);
    return 0;
}