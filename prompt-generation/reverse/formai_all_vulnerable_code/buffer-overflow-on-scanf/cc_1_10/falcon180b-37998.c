//Falcon-180B DATASET v1.0 Category: Memory management ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define HEAP_SIZE 1000 // size of the heap

int heap[HEAP_SIZE]; // the heap
int top = -1; // index of the top element in the heap

// function to initialize the heap
void init() {
    top = -1;
}

// function to check if the heap is empty
int is_empty() {
    if (top == -1) {
        return 1;
    } else {
        return 0;
    }
}

// function to check if the heap is full
int is_full() {
    if (top == HEAP_SIZE - 1) {
        return 1;
    } else {
        return 0;
    }
}

// function to insert an element into the heap
void insert(int element) {
    if (is_full()) {
        printf("Heap is full\n");
        return;
    }
    top++;
    heap[top] = element;
}

// function to delete an element from the heap
int delete() {
    if (is_empty()) {
        printf("Heap is empty\n");
        return -1;
    }
    int element = heap[top];
    top--;
    return element;
}

// function to print the heap
void print_heap() {
    if (is_empty()) {
        printf("Heap is empty\n");
        return;
    }
    printf("Heap: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

// main function
int main() {
    init();
    int choice, element;
    while (1) {
        printf("Enter your choice:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Print\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            insert(element);
            break;
        case 2:
            element = delete();
            if (element!= -1) {
                printf("Deleted element: %d\n", element);
            }
            break;
        case 3:
            print_heap();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}