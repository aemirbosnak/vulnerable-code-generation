#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void free_and_use(void) {
    int *ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    *ptr = 42;
    printf("Value: %d\n", *ptr);
    free(ptr);
    // Use after free vulnerability
    printf("Value after free: %d\n", *ptr); // Undefined behavior
}

int main() {
    free_and_use();
    return 0;
}
