#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_BUFFER 256

void compress(char *input) {
    char output[MAX_BUFFER];
    strcpy(output, "Compressed data: ");
    strcat(output, input);
}

int main() {
    char buffer[10];

    printf("Enter data to compress (max 10 characters):\n");
    gets(buffer);

    compress(buffer);
    printf("Compressed data: %s\n", buffer);

    return 0;
}
