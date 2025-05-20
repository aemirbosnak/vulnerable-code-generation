//Falcon-180B DATASET v1.0 Category: Memory management ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom memory management functions
void *my_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Error: Out of memory!\n");
        exit(1);
    }
    return ptr;
}

void my_free(void *ptr) {
    free(ptr);
}

int main() {
    // Allocate some memory
    char *str = my_malloc(100);
    int *int_arr = my_malloc(10 * sizeof(int));
    float *float_arr = my_malloc(5 * sizeof(float));

    // Use the memory
    strcpy(str, "Hello, world!");
    for (int i = 0; i < 10; i++) {
        int_arr[i] = i * 2;
    }
    for (int i = 0; i < 5; i++) {
        float_arr[i] = 3.14 * i;
    }

    // Print the memory contents
    printf("String: %s\n", str);
    for (int i = 0; i < 10; i++) {
        printf("%d ", int_arr[i]);
    }
    printf("\n");
    for (int i = 0; i < 5; i++) {
        printf("%.2f ", float_arr[i]);
    }
    printf("\n");

    // Free the memory
    my_free(str);
    my_free(int_arr);
    my_free(float_arr);

    return 0;
}