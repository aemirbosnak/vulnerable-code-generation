#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress(char *data, int size) {
    char output[10];
    int i;
    for (i = 0; i < size; i++) {
        output[i % 10] += data[i];
    }
    printf("Compressed: %s\n", output);
}

int main() {
    char input[200];
    printf("Enter data to compress: ");
    scanf("%s", input); // Vulnerable to buffer overflow
    compress(input, strlen(input));
    return 0;
}
