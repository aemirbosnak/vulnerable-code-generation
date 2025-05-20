//Falcon-180B DATASET v1.0 Category: Recursive ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int arr[MAX_SIZE];
int size = 0;

void insert(int data) {
    if (size == MAX_SIZE) {
        printf("Error: Stack Overflow\n");
        exit(0);
    }
    arr[size++] = data;
}

int pop() {
    if (size == 0) {
        printf("Error: Stack Underflow\n");
        exit(0);
    }
    return arr[--size];
}

int peek() {
    if (size == 0) {
        printf("Error: Stack Underflow\n");
        exit(0);
    }
    return arr[size - 1];
}

void print_stack() {
    if (size == 0) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

void recursive_bubble_sort(int n) {
    if (n == 1) {
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    recursive_bubble_sort(n - 1);
}

int main() {
    srand(time(NULL));
    int choice, data;
    while (1) {
        printf("1. Insert\n2. Delete\n3. Display\n4. Sort\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insert(data);
            break;
        case 2:
            if (size == 0) {
                printf("Stack is empty\n");
            } else {
                data = pop();
                printf("Deleted element is: %d\n", data);
            }
            break;
        case 3:
            print_stack();
            break;
        case 4:
            recursive_bubble_sort(size);
            printf("Sorted stack elements are: ");
            for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}