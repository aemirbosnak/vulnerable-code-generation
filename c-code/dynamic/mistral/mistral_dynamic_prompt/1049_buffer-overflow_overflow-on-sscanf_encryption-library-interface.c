#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

// Simulated Encryption Library
typedef struct {
    char key[256];
    char iv[256];
} AES256;

void init(AES256* enc, char* key, char* iv) {
    strcpy(enc->key, key);
    strcpy(enc->iv, iv);
}

void encrypt(AES256* enc, char* message, char* ciphertext, int* len) {
    char buffer[10];
    *len = sscanf(message, "%s%n", buffer, (int*)len);
    strcat(ciphertext, buffer);
    // Unchecked buffer overflow here!
    strcat(ciphertext, message + *len);
}

int main() {
    AES256 aes;
    char key[] = "SecretKey";
    char iv[] = "InitVector";
    char message[1024];
    char ciphertext[4096];
    int len;

    init(&aes, key, iv);
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    encrypt(&aes, message, ciphertext, &len);

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
