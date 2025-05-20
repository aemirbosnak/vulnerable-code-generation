#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress_data(char *data) {
    // Simulate compression by replacing each character with its ASCII value
    int i;
    for (i = 0; data[i] != '\0'; i++) {
        data[i] = (char)data[i];
    }
}

int main() {
    char *buffer = (char *)malloc(100);
    if (buffer == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Fill buffer with some data
    for (int i = 0; i < 99; i++) {
        buffer[i] = 'A';
    }
    buffer[99] = '\0';

    // Compress the data
    compress_data(buffer);

    // Use-after-free vulnerability: accessing freed memory
    printf("%s\n", buffer); // This line will cause undefined behavior

    free(buffer);

    return 0;
}
