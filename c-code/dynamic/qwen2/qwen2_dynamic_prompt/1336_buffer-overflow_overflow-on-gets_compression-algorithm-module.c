#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress_data(char *data, int size) {
    char buffer[10];
    gets(buffer); // Vulnerability: buffer overflow
}

int main() {
    char input[200];
    printf("Enter data to compress: ");
    fgets(input, sizeof(input), stdin);
    compress_data(input, strlen(input));
    return 0;
}
