#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* my_malloc(size_t size) {
    return malloc(size);
}

void my_free(void* ptr) {
    free(ptr);
}

int main() {
    int* p = (int*)my_malloc(sizeof(int));
    *p = 42;
    my_free(p);

    if (*p == 42) { // Use-after-free vulnerability
        printf("Use after free\n");
    } else {
        printf("No use after free\n");
    }

    return 0;
}
