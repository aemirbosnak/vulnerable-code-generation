#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = NULL;
    ptr = (int *)malloc(10);
    if (ptr == NULL) {
        return 1;
    }

    // Accessing memory beyond the allocated space, leading to dereference failure
    *ptr = 10;

    free(ptr);
    return 0;
}
