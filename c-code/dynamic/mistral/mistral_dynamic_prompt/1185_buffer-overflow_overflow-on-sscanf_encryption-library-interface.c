#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

/* Secret key for encryption */
#define KEY "secret"

/* Macro for XOR encryption/decryption */
#define XOR_ENCRYPT(ch, key) ((char)(ch ^ key))

/* Function to encrypt plaintext */
char* encrypt(const char* plaintext, size_t length) {
    static char encrypted[256];

    for (size_t i = 0; i < length; ++i) {
        encrypted[i] = XOR_ENCRYPT(plaintext[i], KEY[i % strlen(KEY)]);
    }

    return encrypted;
}

/* Function to decrypt encrypted text */
char* decrypt(const char* encrypted, size_t length) {
    static char decrypted[256];

    for (size_t i = 0; i < length; ++i) {
        decrypted[i] = XOR_ENCRYPT(encrypted[i], KEY[i % strlen(KEY)]);
    }

    return decrypted;
}

/* Main function */
int main(int argc, char* argv[]) {
    char plaintext[256];
    char buffer[10];
    size_t plaintext_length = 0;

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    /* Buffer overflow */
    sscanf(argv[1], "%s%s", plaintext, buffer);

    plaintext_length = strlen(plaintext);

    char* encrypted_text = encrypt(plaintext, plaintext_length);
    printf("Encrypted text: %s\n", encrypted_text);

    char* decrypted_text = decrypt(encrypted_text, plaintext_length);
    printf("Decrypted text: %s\n", decrypted_text);

    return 0;
}
