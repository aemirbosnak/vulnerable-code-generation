//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000

typedef struct {
    int *data;
    int size;
} Array;

void newArray(Array *array) {
    array->data = (int *) malloc(MAX_SIZE * sizeof(int));
    array->size = 0;
}

void freeArray(Array *array) {
    free(array->data);
}

void push(Array *array, int element) {
    if (array->size == MAX_SIZE) {
        printf("Error: Array is full!\n");
        return;
    }
    array->data[array->size++] = element;
}

int pop(Array *array) {
    if (array->size == 0) {
        printf("Error: Array is empty!\n");
        return -1;
    }
    return array->data[--array->size];
}

int peek(Array *array) {
    if (array->size == 0) {
        printf("Error: Array is empty!\n");
        return -1;
    }
    return array->data[array->size - 1];
}

void display(Array *array) {
    int i;
    for (i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int main() {
    Array stack;
    newArray(&stack);

    int choice, element;
    while (1) {
        printf("Enter your choice:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(&stack, element);
                break;
            case 2:
                element = pop(&stack);
                if (element!= -1) {
                    printf("Popped element: %d\n", element);
                }
                break;
            case 3:
                element = peek(&stack);
                if (element!= -1) {
                    printf("Top element: %d\n", element);
                }
                break;
            case 4:
                display(&stack);
                break;
            case 5:
                freeArray(&stack);
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}