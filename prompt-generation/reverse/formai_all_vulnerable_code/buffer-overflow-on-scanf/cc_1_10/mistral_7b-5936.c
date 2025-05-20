//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

// Custom error message function with increasing levels of silliness
void custom_error(const char *format, ...) {
    static int silly_level = 0;
    va_list args;

    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    if (silly_level < 5) {
        silly_level++;
        custom_error("Error %d: %s\n", silly_level, format);
    } else {
        custom_error("Ridiculous Error: The universe is collapsing, and it's all your fault!\n");
    }
    exit(EXIT_FAILURE);
}

// Dynamic memory allocation function with custom error handling
void *my_malloc(size_t size) {
    void *ptr = malloc(size);

    if (ptr == NULL) {
        custom_error("Out of memory. Requested size: %zu\n", size);
    }

    return ptr;
}

// Recursive function to fill an array with random numbers
void fill_array_recursive(int arr[], int len, int start) {
    if (len <= 0) {
        return;
    }

    arr[start] = rand() % 100;
    fill_array_recursive(arr, len - 1, start + 1);
}

int main() {
    srand(time(NULL));
    int size, *arr;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    arr = my_malloc(size * sizeof(int));

    if (arr == NULL) {
        // This will trigger a custom error message with increasing silliness
        return 1;
    }

    fill_array_recursive(arr, size, 0);

    printf("Filled array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}