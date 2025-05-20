#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void compress(char *input) {
    char buffer[10];
    int i, count = 0;

    for (i = 0; input[i] != '\0'; i++) {
        if (i > 9) break;
        buffer[i] = input[i];
        count++;
    }

    buffer[i] = '\0'; // Always null-terminate the buffer
    printf("Compressed data: %s\n", buffer);
    // Note: This is a very naive compression algorithm
}

int main() {
    char input[1000];

    printf("Enter data to compress: ");
    fgets(input, sizeof(input), stdin);
    compress(input);

    // Now let's add some deliberate buffer overflow
    char overflow_data[1] = {'A'};
    strcat(input, overflow_data); // This will overwrite the local buffer
    compress(input); // This will cause a segmentation fault

    return 0;
}
