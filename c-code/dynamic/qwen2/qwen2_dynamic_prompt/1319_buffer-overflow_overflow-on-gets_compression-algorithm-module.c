#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress(char *data, int size) {
    char buffer[10];
    gets(buffer); // Vulnerable to buffer overflow
}

int main() {
    char input[200];
    printf("Enter data to compress: ");
    fgets(input, sizeof(input), stdin);
    compress(input, strlen(input));
    return 0;
}
