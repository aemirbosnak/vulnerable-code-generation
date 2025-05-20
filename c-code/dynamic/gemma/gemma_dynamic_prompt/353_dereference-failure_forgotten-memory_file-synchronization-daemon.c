#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *buffer = NULL;
    buffer = (char *)malloc(10);
    if (buffer == NULL) {
        return 1;
    }

    // Vulnerable code - dereference failure
    *buffer = 'A';

    // Free the memory
    free(buffer);

    return 0;
}
