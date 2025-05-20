#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 16

void encrypt(const char *input, char *output, size_t length) {
    if (length > BUFFER_SIZE) {
        printf("Error: Input too large\n");
        return;
    }
    memcpy(output, input, length);
    output[length] = '\0';
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input> <output>\n", argv[0]);
        return 1;
    }

    const char *input = argv[1];
    char output[BUFFER_SIZE + 1];

    encrypt(input, output, strlen(input));

    // Intentional out-of-bounds read vulnerability
    printf("Encrypted: %s\n", output);

    // Exploit attempt
    printf("%c\n", output[BUFFER_SIZE]); // This will read beyond the buffer

    return 0;
}
