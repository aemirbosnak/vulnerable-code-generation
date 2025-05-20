//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 1000000

typedef struct {
    int data;
    int index;
} element;

element arr[MAX_SIZE];
int top = -1;

void push(int data) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(0);
    }
    top++;
    arr[top].data = data;
    arr[top].index = top;
}

int pop() {
    if (top <= -1) {
        printf("Stack underflow\n");
        exit(0);
    }
    int data = arr[top].data;
    top--;
    return data;
}

element search(int data) {
    int i;
    for (i = 0; i <= top; i++) {
        if (arr[i].data == data) {
            return arr[i];
        }
    }
    return (element) {0, -1};
}

void display() {
    int i;
    for (i = top; i >= 0; i--) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}

int main() {
    int choice, data;
    while (true) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                data = pop();
                printf("Popped data: %d\n", data);
                break;
            case 3:
                printf("Enter the data to search: ");
                scanf("%d", &data);
                element result = search(data);
                if (result.data == 0) {
                    printf("Data not found\n");
                } else {
                    printf("Data found at index %d\n", result.index);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}