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

void my_init(void* ptr, int value, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        ((char*)ptr)[i] = value;
    }
}

int main() {
    char* ptr = my_malloc(10);
    my_init(ptr, 'A', 10);
    printf("%s\n", ptr);

    my_free(ptr);
    ptr = my_malloc(10); // Use-after-free vulnerability
    my_init(ptr, 'B', 10);
    printf("%s\n", ptr);

    my_free(ptr);
    return 0;
}
