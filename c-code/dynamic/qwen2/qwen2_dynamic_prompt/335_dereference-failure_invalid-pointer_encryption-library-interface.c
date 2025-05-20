#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void encrypt(char *data, int length) {
    for (int i = 0; i < length; i++) {
        data[i] += 1;
    }
}

int main() {
    char *plaintext = "Hello, World!";
    int length = 13;

    printf("Plaintext: %s\n", plaintext);

    // Simulate an invalid pointer dereference
    char *encrypted_text = NULL;
    encrypted_text[0] = 'A'; // Dereferencing a null pointer

    encrypt(encrypted_text, length); // This line will cause a segmentation fault

    return 0;
}
