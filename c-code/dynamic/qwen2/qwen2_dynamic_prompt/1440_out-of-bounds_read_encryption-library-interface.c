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

int main() {
    char buffer[BUFFER_SIZE];
    char key[BUFFER_SIZE];
    char encrypted[BUFFER_SIZE];

    // Simulate user input
    strcpy(buffer, "This is a test");

    // Encrypt the data
    encrypt(buffer, encrypted, strlen(buffer));

    // Intentional out-of-bounds read vulnerability
    printf("Encrypted: %s\n", encrypted);
    printf("Out-of-bounds read: %c\n", encrypted[BUFFER_SIZE]);

    return 0;
}
