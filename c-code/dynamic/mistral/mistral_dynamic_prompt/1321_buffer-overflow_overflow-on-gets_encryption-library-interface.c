#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[32];
    char algorithm[16];
    char key[256];
} EncryptionLibrary;

void initialize(EncryptionLibrary *library, const char *name, const char *algo, const char *key) {
    strcpy(library->name, name);
    strcpy(library->algorithm, algo);
    strcpy(library->key, key);
}

char *encrypt(const EncryptionLibrary *library, const char *plaintext, int *ciphertext_len) {
    char *ciphertext = malloc(*plaintext * sizeof(char));
    printf("Encrypting using '%s'...\n", library->algorithm);
    memset(ciphertext, 0, *plaintext * sizeof(char));
    gets(ciphertext); // Buffer overflow vulnerability here
    *ciphertext_len = *plaintext * sizeof(char);
    printf("Encrypted data: %s\n", ciphertext);
    return ciphertext;
}

void free_encrypt_data(char *data) {
    free(data);
}

int main() {
    EncryptionLibrary lib;
    initialize(&lib, "My Secure Library v1.0", "AES-256", "ThisIsASecretKey1234");

    char plaintext[] = "Attack at dawn!";
    int plaintext_len = sizeof(plaintext) / sizeof(plaintext[0]);
    char *ciphertext;
    int ciphertext_len;

    ciphertext = encrypt(&lib, plaintext, &ciphertext_len);

    // Perform some analysis on the encrypted data...

    free_encrypt_data(ciphertext);

    return 0;
}
