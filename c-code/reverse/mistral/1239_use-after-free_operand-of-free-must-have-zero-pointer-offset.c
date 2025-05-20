#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *a = malloc(5 * sizeof(int));
    if (!a) {
        fprintf(stderr, "Failed to allocate memory for array a\n");
        return 1;
    }

    for (size_t i = 0; i < 5; ++i) {
        a[i] = i * i;
        printf("a[%zu] = %d\n", i, a[i]);
    }

    int *b = calloc(3, sizeof(int));
    if (!b) {
        fprintf(stderr, "Failed to allocate memory for array b\n");
        free(a);
        return 1;
    }

    for (size_t i = 0; i < 3; ++i) {
        b[i] = i * 10;
        printf("b[%zu] = %d\n", i, b[i]);
    }

    printf("\nReallocating array a to hold 10 integers...\n");
    a = realloc(a, 10 * sizeof(int));
    if (!a) {
        fprintf(stderr, "Failed to reallocate memory for array a\n");
        free(b);
        return 1;
    }

    for (size_t i = 5; i < 10; ++i) {
        a[i] = i * 100;
        printf("a[%zu] = %d\n", i, a[i]);
    }

    printf("\nFreeing dynamically allocated memory...\n");
    free(a);
    free(b);

    return 0;
}
