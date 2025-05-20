#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress_data(char *data, int size) {
    char buffer[10];
    for (int i = 0; i <= size; i++) { // Out of bounds write vulnerability
        buffer[i] = data[i];
    }
}

int main() {
    char input[] = "This is a test string";
    compress_data(input, sizeof(input));
    printf("Compressed data: %s\n", input);
    return 0;
}
