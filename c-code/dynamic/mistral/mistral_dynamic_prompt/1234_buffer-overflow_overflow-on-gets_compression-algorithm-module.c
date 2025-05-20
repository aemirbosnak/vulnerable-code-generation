#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void compress_data(char* data, int size) {
    char buffer[10];

    printf("Enter data to compress: ");
    gets(buffer); // vulnerable code: buffer overflow vulnerability

    // ... (simulate compression logic)

    strcat(data, buffer);
}

int main() {
    char data[1000];
    compress_data(data, sizeof(data));

    printf("Compressed data: %s\n", data);

    return 0;
}
