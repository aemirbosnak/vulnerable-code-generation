#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void compress(char *input) {
    char buffer[10];
    int count = 0;

    while (*input) {
        sprintf(buffer, "%d", *input++);
        count += strlen(buffer);
    }

    printf("Compressed size: %s\n", buffer);
    printf("Compressed data: %s\n", input);
}

int main() {
    char input[1024];

    printf("Enter data to compress (up to 1024 characters):\n");
    fgets(input, sizeof(input), stdin);

    compress(input);

    return 0;
}
