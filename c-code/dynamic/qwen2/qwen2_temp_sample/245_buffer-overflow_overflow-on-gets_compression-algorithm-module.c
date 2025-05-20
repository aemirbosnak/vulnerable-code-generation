#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress(char* input) {
    char buffer[10];
    gets(buffer); // Vulnerability: uses gets() which does not check buffer size
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return 1;
    }
    compress(argv[1]);
    printf("Compression successful!\n");
    return 0;
}
