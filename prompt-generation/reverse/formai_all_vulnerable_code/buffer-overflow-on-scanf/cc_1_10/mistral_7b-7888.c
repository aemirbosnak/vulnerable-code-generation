//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: careful
#include <stdio.h>
#include <stdlib.h>

void my_malloc(int *size, int **array) {
    int *temp;

    if (*size <= 0) {
        printf("Invalid size!\n");
        return;
    }

    temp = (int *)malloc(*size * sizeof(int));

    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    *array = temp;
}

void my_free(int *array, int size) {
    free(array);
}

int main() {
    int size, i;
    int *arr;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    my_malloc(&size, &arr);

    for (i = 0; i < size; i++) {
        arr[i] = i;
    }

    printf("Array elements:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    my_free(arr, size);

    printf("Memory freed successfully!\n");

    return 0;
}