#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress_data(const char *input) {
    char buffer[10];
    int value;

    // Vulnerable to buffer overflow if input is too long
    sscanf(input, "%d", &value);
    sprintf(buffer, "Compressed: %d", value);

    printf("%s\n", buffer);
}

int main() {
    char input[200];

    printf("Enter data to compress: ");
    fgets(input, sizeof(input), stdin);

    compress_data(input);

    return 0;
}
