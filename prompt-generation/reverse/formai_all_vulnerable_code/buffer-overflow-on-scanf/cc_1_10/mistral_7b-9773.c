//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void scalable_add(int *arr, int size, int num);
void scalable_subtract(int *arr, int size, int num);
void scalable_multiply(int *arr, int size, int num);
void scalable_divide(int *arr, int size, int num);

int main() {
    int arr[MAX_SIZE];
    int i, size, num, choice;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\nChoose an operation:\n");
        printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number to add: ");
                scanf("%d", &num);
                scalable_add(arr, size, num);
                break;
            case 2:
                printf("Enter the number to subtract: ");
                scanf("%d", &num);
                scalable_subtract(arr, size, num);
                break;
            case 3:
                printf("Enter the number to multiply: ");
                scanf("%d", &num);
                scalable_multiply(arr, size, num);
                break;
            case 4:
                printf("Enter the number to divide: ");
                scanf("%d", &num);
                scalable_divide(arr, size, num);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }

        printf("\nArray elements after the operation:\n");
        for (i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } while (choice != 5);

    return 0;
}

void scalable_add(int *arr, int size, int num) {
    for (int i = 0; i < size; i++) {
        arr[i] += num;
    }
}

void scalable_subtract(int *arr, int size, int num) {
    for (int i = 0; i < size; i++) {
        arr[i] -= num;
    }
}

void scalable_multiply(int *arr, int size, int num) {
    for (int i = 0; i < size; i++) {
        arr[i] *= num;
    }
}

void scalable_divide(int *arr, int size, int num) {
    for (int i = 0; i < size; i++) {
        if (num == 0) {
            printf("Error! Division by zero is not allowed.\n");
            exit(1);
        }
        arr[i] /= num;
    }
}