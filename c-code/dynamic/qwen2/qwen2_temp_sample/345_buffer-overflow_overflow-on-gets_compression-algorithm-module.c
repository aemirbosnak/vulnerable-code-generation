#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress(char* input) {
    char compressed[10];
    int i = 0;
    int j = 0;

    while (input[i] != '\0') {
        compressed[j++] = input[i++];
    }
    compressed[j] = '\0';

    printf("Compressed: %s\n", compressed);
}

int main() {
    char input[20];

    printf("Enter data to compress: ");
    gets(input); // This intentionally contains a buffer overflow vulnerability

    compress(input);

    return 0;
}
