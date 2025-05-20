//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: genious
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int index;
} Node;

Node arr[MAX_SIZE];
int top = -1;

void push(int data) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    arr[top].data = data;
    arr[top].index = top;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    int data = arr[top].data;
    int index = arr[top].index;
    top--;
    return data;
}

int peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return arr[top].data;
}

int search(int data) {
    int i;
    for (i = top; i >= 0; i--) {
        if (arr[i].data == data) {
            printf("Element found at position %d\n", arr[i].index);
            return arr[i].index;
        }
    }
    printf("Element not found in the stack\n");
    return -1;
}

int main() {
    int choice, data, result;
    do {
        printf("Enter your choice:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the element to push:\n");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            data = pop();
            if (data!= -1)
                printf("Popped element is %d\n", data);
            break;
        case 3:
            data = peek();
            if (data!= -1)
                printf("Top element is %d\n", data);
            break;
        case 4:
            printf("Enter the element to search:\n");
            scanf("%d", &data);
            result = search(data);
            if (result!= -1)
                printf("Element found at position %d\n", result);
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice!= 5);
    return 0;
}