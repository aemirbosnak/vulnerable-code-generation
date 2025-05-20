#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    char *buffer = NULL;
    size_t size = 0;

    // Allocate memory for the buffer
    buffer = malloc(1024);
    if (buffer == NULL) {
        return 1;
    }

    // Free the memory
    free(buffer);

    // Use the freed memory, causing a use after free vulnerability
    buffer[0] = 'A';

    // Print the contents of the buffer
    printf("%c", buffer[0]);

    return 0;
}
