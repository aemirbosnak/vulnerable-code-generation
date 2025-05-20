#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *buf = NULL;
    int size = 0;

    // Allocate memory
    buf = malloc(size);

    // Use the memory after free
    free(buf);
    buf[0] = 'a';

    // Print the content of the memory
    printf("%c", buf[0]);

    return 0;
}
