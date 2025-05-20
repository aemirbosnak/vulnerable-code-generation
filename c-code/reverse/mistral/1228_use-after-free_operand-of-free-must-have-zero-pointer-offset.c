#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void free_protected(void* ptr) {
    void* temp = ptr;
    free(ptr);
    printf("Accessing freed memory: %p\n", temp);
}

int main() {
    int* data = malloc(sizeof(int));
    *data = 42;
    free_protected(data);
    printf("Value of data: %d\n", *data);
    return 0;
}
