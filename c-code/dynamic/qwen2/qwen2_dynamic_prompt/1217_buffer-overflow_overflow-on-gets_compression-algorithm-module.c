#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress_data(char *input, char *output) {
    int i = 0;
    while (input[i] != '\0') {
        output[i] = input[i];
        i++;
    }
}

int main() {
    char input[10];
    char output[10];

    printf("Enter data to compress: ");
    gets(input); // Vulnerable to buffer overflow

    compress_data(input, output);

    printf("Compressed data: %s\n", output);

    return 0;
}
