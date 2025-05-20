#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress_data(char *input) {
    char buffer[10];
    printf("Compressing data...\n");
    gets(buffer); // Vulnerable to buffer overflow
}

int main() {
    char input[20];
    printf("Enter data to compress: ");
    fgets(input, sizeof(input), stdin);
    compress_data(input);
    return 0;
}
