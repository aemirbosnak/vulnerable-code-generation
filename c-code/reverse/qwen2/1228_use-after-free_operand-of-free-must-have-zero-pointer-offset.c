#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void free_protected(void *ptr) {
    free(ptr);
}

int main() {
    int *data = (int *)malloc(sizeof(int));
    if (data == NULL) return 1;
    *data = 42;

    free_protected(data);

    // Use-after-free vulnerability
    printf("Data: %d\n", *data); // Undefined behavior

    return 0;
}
