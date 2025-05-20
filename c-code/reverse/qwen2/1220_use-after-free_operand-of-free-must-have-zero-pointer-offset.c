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

void vulnerable_function(int* data) {
    if (*data == 42) {
        printf("Data is 42\n");
    } else {
        printf("Data is not 42\n");
    }
}

int main() {
    int* ptr = (int*)my_malloc(sizeof(int));
    *ptr = 42;
    my_free(ptr);

    // Use-after-free vulnerability
    vulnerable_function(ptr);

    return 0;
}
