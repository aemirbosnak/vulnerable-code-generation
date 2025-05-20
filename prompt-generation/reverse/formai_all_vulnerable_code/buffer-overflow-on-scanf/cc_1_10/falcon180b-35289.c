//Falcon-180B DATASET v1.0 Category: Memory management ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void allocate_memory(int *arr, int size) {
    if (size <= 0 || size > MAX) {
        printf("Invalid size!\n");
        return;
    }
    arr = (int *) malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("Memory allocated successfully.\n");
}

void free_memory(int *arr) {
    free(arr);
    printf("Memory freed successfully.\n");
}

void resize_memory(int *arr, int old_size, int new_size) {
    int *temp = (int *) malloc(new_size * sizeof(int));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i < old_size; i++) {
        temp[i] = arr[i];
    }
    free(arr);
    arr = temp;
}

int main() {
    int size = 0;
    int *arr = NULL;
    printf("Enter the size of the array (0 to exit): ");
    scanf("%d", &size);
    while (size > 0) {
        allocate_memory(arr, size);
        printf("Enter the elements of the array:\n");
        for (int i = 0; i < size; i++) {
            scanf("%d", &arr[i]);
        }
        printf("Enter the new size of the array (0 to exit): ");
        scanf("%d", &size);
        if (size > 0) {
            resize_memory(arr, size, size);
        }
    }
    free_memory(arr);
    return 0;
}