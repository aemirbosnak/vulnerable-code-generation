//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: modular
#include <stdio.h>

#define MAX_SIZE 1024

void bitwise_operations(int arr[], int size) {
    int i;
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Bitwise operations:\n");
    bitwise_operations(arr, size);

    // Bitwise AND
    printf("Bitwise AND:\n");
    int result = 0;
    for(int i = 0; i < size; i++) {
        result |= arr[i];
    }
    bitwise_operations(arr, size);
    printf("Result: %d\n", result);

    // Bitwise OR
    printf("Bitwise OR:\n");
    result = 0;
    for(int i = 0; i < size; i++) {
        result |= arr[i];
    }
    bitwise_operations(arr, size);
    printf("Result: %d\n", result);

    // Bitwise XOR
    printf("Bitwise XOR:\n");
    result = 0;
    for(int i = 0; i < size; i++) {
        result ^= arr[i];
    }
    bitwise_operations(arr, size);
    printf("Result: %d\n", result);

    // Bitwise NOT
    printf("Bitwise NOT:\n");
    for(int i = 0; i < size; i++) {
        arr[i] = ~arr[i];
    }
    bitwise_operations(arr, size);

    // Bitwise shift left
    printf("Bitwise shift left:\n");
    for(int i = 0; i < size; i++) {
        arr[i] <<= 2;
    }
    bitwise_operations(arr, size);

    // Bitwise shift right
    printf("Bitwise shift right:\n");
    for(int i = 0; i < size; i++) {
        arr[i] >>= 2;
    }
    bitwise_operations(arr, size);

    return 0;
}