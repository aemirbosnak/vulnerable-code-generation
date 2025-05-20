//Falcon-180B DATASET v1.0 Category: Error handling ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *ptr;
    int size;
} Array;

void init_array(Array *arr, int size) {
    arr->ptr = malloc(size * sizeof(int));
    if (arr->ptr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    arr->size = size;
}

void free_array(Array *arr) {
    free(arr->ptr);
    arr->ptr = NULL;
}

int main() {
    Array arr;
    int i, choice;

    init_array(&arr, 10);

    while (true) {
        printf("1. Add element\n");
        printf("2. Remove element\n");
        printf("3. Print array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter element to add: ");
            scanf("%d", arr.ptr + arr.size);
            arr.size++;
            break;
        case 2:
            printf("Enter element to remove: ");
            scanf("%d", &i);
            for (int j = 0; j < arr.size; j++) {
                if (arr.ptr[j] == i) {
                    for (int k = j; k < arr.size - 1; k++) {
                        arr.ptr[k] = arr.ptr[k + 1];
                    }
                    arr.size--;
                    break;
                }
            }
            break;
        case 3:
            for (int j = 0; j < arr.size; j++) {
                printf("%d ", arr.ptr[j]);
            }
            printf("\n");
            break;
        case 4:
            free_array(&arr);
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}