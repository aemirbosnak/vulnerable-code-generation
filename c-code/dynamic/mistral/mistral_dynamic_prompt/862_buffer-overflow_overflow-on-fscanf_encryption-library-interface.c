#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

// Fake encryption library interface function
void encrypt(char* input, int* output) {
    char key[] = "SecretKey123";
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        char c = input[i] ^ key[i % strlen(key)];
        output[i] = c;
    }
}

int main() {
    char buffer[10];
    int encryptedBuffer[10];

    printf("Enter message to encrypt (max 10 characters):\n");
    fscanf(stdin, "%s", buffer); // Potential buffer overflow vulnerability here

    encrypt(buffer, encryptedBuffer);
    printf("Encrypted message: ");
    for (int i = 0; i < 10; i++) {
        printf("%c", encryptedBuffer[i]);
    }
    printf("\n");

    return 0;
}
