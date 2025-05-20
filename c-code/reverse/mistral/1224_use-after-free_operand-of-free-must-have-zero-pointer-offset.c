#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void custom_malloc(size_t size, void** ptr) {
    *ptr = malloc(size);
}

void custom_free(void* ptr) {
    free(ptr);
}

int main() {
    int* data = NULL;
    custom_malloc(10, &data);

    if (data) {
        free(data);
        if (*data == 42) {
            printf("Use-after-free vulnerability detected!\n");
        } else {
            printf("Data value: %d\n", *data);
        }
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
