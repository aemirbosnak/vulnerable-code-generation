#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void encrypt(char *data, int length) {
    for (int i = 0; i <= length; i++) { // Dereference failure: array bounds violated
        data[i] += 1;
    }
}

int main() {
    char *buffer = (char *)malloc(10 * sizeof(char));
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize buffer with some values
    for (int i = 0; i < 9; i++) {
        buffer[i] = 'A' + i;
    }
    buffer[9] = '\0';

    printf("Original data: %s\n", buffer);

    encrypt(buffer, 10); // Intentional off-by-one error

    printf("Encrypted data: %s\n", buffer);

    free(buffer);
    return 0;
}
