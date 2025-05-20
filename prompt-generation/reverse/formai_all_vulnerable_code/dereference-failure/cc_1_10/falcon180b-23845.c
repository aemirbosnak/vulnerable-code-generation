//Falcon-180B DATASET v1.0 Category: Memory management ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// Custom memory allocation function
void* my_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    return ptr;
}

// Custom memory deallocation function
void my_free(void* ptr) {
    free(ptr);
}

// Function to demonstrate memory allocation and deallocation
void test_memory() {
    int* arr1 = my_malloc(10 * sizeof(int));
    int* arr2 = my_malloc(20 * sizeof(int));
    int* arr3 = my_malloc(30 * sizeof(int));

    // Initialize arrays
    for (int i = 0; i < 10; i++) {
        arr1[i] = i;
    }
    for (int i = 0; i < 20; i++) {
        arr2[i] = i;
    }
    for (int i = 0; i < 30; i++) {
        arr3[i] = i;
    }

    // Print arrays
    printf("Array 1:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    printf("Array 2:\n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    printf("Array 3:\n");
    for (int i = 0; i < 30; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    // Deallocate arrays
    my_free(arr1);
    my_free(arr2);
    my_free(arr3);
}

int main() {
    test_memory();
    return 0;
}