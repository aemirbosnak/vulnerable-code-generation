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

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <integer>\n", argv[0]);
        return 1;
    }

    compress_data(argv[1]);

    return 0;
}
