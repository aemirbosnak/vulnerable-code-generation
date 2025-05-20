#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress_data(char *data, int size) {
    char compressed[10];
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (i == 0 || data[i] != data[i - 1]) {
            compressed[j++] = data[i];
        }
    }
    compressed[j] = '\0';
    printf("Compressed: %s\n", compressed);
}

int main() {
    char input[20];
    printf("Enter data to compress: ");
    scanf("%s", input); // Vulnerable to buffer overflow

    compress_data(input, sizeof(input));

    return 0;
}
