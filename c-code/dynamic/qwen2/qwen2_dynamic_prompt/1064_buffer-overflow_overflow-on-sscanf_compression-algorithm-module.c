#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress_data(const char *input) {
    char buffer[10];
    int data;

    // Vulnerable line: buffer overflow due to insufficient space in buffer
    sscanf(input, "%d", &data);
    sprintf(buffer, "%d", data);

    printf("Compressed data: %s\n", buffer);
}

int main() {
    const char *large_input = "12345678901234567890";
    compress_data(large_input);
    return 0;
}
