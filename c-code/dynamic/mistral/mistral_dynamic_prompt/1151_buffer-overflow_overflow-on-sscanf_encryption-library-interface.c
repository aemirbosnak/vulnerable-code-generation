#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_KEY_LEN 50
#define KEY_BUFFER_SIZE (MAX_KEY_LEN * 2)

void encrypt(const char *input, char *output) {
    char key[KEY_BUFFER_SIZE];

    // Example: Reading a key from stdin using sscanf which may result in a buffer overflow if a very long key is entered
    printf("Enter encryption key: ");
    scanf("%s", key);

    // Encryption logic (just for the sake of having some code here, it doesn't encrypt anything)
    for (size_t i = 0; i < strlen(input); i++) {
        output[i] = input[i] ^ key[i % MAX_KEY_LEN];
    }
}

int main() {
    char input[100];
    char output[100];

    printf("Please enter plaintext: ");
    scanf("%s", input);

    encrypt(input, output);

    printf("Encrypted text: %s\n", output);

    return 0;
}
