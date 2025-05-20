#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    char **buffer = NULL;
    int size = 0;

    // Allocate memory for the buffer
    buffer = malloc(sizeof(char *) * size);

    // Use the memory after freeing it
    free(buffer);
    buffer[0] = 'H';

    // Print the contents of the buffer
    printf("%c", buffer[0]);

    return 0;
}
