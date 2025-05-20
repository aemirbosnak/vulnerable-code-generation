#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

void encrypt(char *input, char *key) {
    int keyLen = strlen(key);
    for (int i = 0; input[i] != '\0'; ++i) {
        input[i] += key[i % keyLen];
    }
}

int main() {
    char input[BUFFER_SIZE];
    char key[BUFFER_SIZE];
    
    printf("Enter plaintext: ");
    fgets(input, BUFFER_SIZE, stdin);

    printf("Enter key: ");
    fgets(key, BUFFER_SIZE, stdin);
    
    // Remove newline character from input and key
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
    len = strlen(key);
    if (len > 0 && key[len - 1] == '\n') {
        key[len - 1] = '\0';
    }

    encrypt(input, key);
    printf("Encrypted: %s\n", input);
    return 0;
}
