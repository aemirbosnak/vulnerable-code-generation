#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

// Fake compression functions
void compress(unsigned char* data, int size) {
    int i;
    for (i = 0; i < size; ++i) {
        if (data[i] == 'A') {
            data[i] = 'Z';
        }
    }
}

void decompress(unsigned char* data, int size) {
    int i;
    for (i = 0; i < size; ++i) {
        if (data[i] == 'Z') {
            data[i] = 'A';
        }
    }
}

int main() {
    unsigned char text[] = "A sample string for testing.";
    unsigned char compressed[sizeof(text)];

    compress(text, sizeof(text));
    decompress(compressed, sizeof(compressed));

    printf("Compressed data: ");
    int i;
    for (i = 0; i < sizeof(text); ++i) {
        printf("%c", compressed[i]);
    }
    printf("\n");

    unsigned char* null_ptr = NULL;
    int some_value = *null_ptr; // Null pointer dereference

    return 0;
}
