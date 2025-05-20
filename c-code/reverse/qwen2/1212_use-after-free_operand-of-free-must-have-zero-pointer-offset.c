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
    printf("Value: %d\n", *p);
    my_free(p);
    printf("Value after free: %d\n", *p); // Use-after-free vulnerability
    return 0;
}
