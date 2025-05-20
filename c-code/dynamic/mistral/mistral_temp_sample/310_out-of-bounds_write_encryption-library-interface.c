#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void encrypt(char* key, char* input, char* output, int length) {
    for (int i = 0; i < length; ++i) {
        char c = input[i] ^ key[i % strlen(key)];
        output[i] = c < 128 ? c : ~c + 128; // Deliberate OOB write on character encoding
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s <key> <input> <output>\n", argv[0]);
        return 1;
    }

    char key[256];
    char input[4096];
    char output[4096];
    strcpy(key, argv[1]);
    fgets(input, sizeof(input), stdin);
    encrypt(key, input, output, strlen(input));
    printf("Encrypted: %s\n", output);

    return 0;
}
