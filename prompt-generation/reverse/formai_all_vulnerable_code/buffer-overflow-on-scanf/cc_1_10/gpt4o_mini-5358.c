//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#define BLOCK_SIZE 16
#define MAX_INPUT_SIZE 256

void handleErrors() {
    fprintf(stderr, "An error occurred.\n");
    exit(EXIT_FAILURE);
}

void encrypt_aes(const unsigned char *plaintext, const unsigned char *key, unsigned char *encrypted) {
    AES_KEY encryptKey;
    if (AES_set_encrypt_key(key, 128, &encryptKey) < 0) {
        handleErrors();
    }

    unsigned char iv[AES_BLOCK_SIZE];
    if (!RAND_bytes(iv, sizeof(iv))) {
        handleErrors();
    }

    // Copy IV to the beginning of the output
    memcpy(encrypted, iv, AES_BLOCK_SIZE);

    AES_cbc_encrypt(plaintext, encrypted + AES_BLOCK_SIZE, BLOCK_SIZE, &encryptKey, iv, AES_ENCRYPT);
}

void decrypt_aes(const unsigned char *encrypted, const unsigned char *key, unsigned char *decrypted) {
    AES_KEY decryptKey;
    if (AES_set_decrypt_key(key, 128, &decryptKey) < 0) {
        handleErrors();
    }

    unsigned char iv[AES_BLOCK_SIZE];
    memcpy(iv, encrypted, AES_BLOCK_SIZE); // Get IV from the beginning of encrypted data

    AES_cbc_encrypt(encrypted + AES_BLOCK_SIZE, decrypted, BLOCK_SIZE, &decryptKey, iv, AES_DECRYPT);
}

void get_aes_key(unsigned char *key) {
    if (!RAND_bytes(key, BLOCK_SIZE)) {
        handleErrors();
    }
}

int main() {
    unsigned char key[BLOCK_SIZE];
    get_aes_key(key);

    char operation;
    printf("Enter 'e' to encrypt or 'd' to decrypt: ");
    scanf(" %c", &operation);
    
    if (operation != 'e' && operation != 'd') {
        printf("Invalid operation. Use 'e' or 'd'.\n");
        return EXIT_FAILURE;
    }

    unsigned char input[MAX_INPUT_SIZE], output[MAX_INPUT_SIZE + AES_BLOCK_SIZE];
    memset(output, 0, sizeof(output));

    if (operation == 'e') {
        printf("Enter the message to encrypt: ");
        getchar(); // To consume the newline character
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Remove the newline character

        encrypt_aes((unsigned char *)input, key, output);

        printf("Encrypted output (in hex): ");
        for (int i = 0; i < MAX_INPUT_SIZE + AES_BLOCK_SIZE; i++) {
            printf("%02x", output[i]);
        }
        printf("\n");
        
    } else if (operation == 'd') {
        printf("Enter the hex-encoded encrypted message: ");
        getchar(); // To consume the newline character

        for (int i = 0; i < MAX_INPUT_SIZE + AES_BLOCK_SIZE; i++) {
            unsigned int byte;
            scanf("%2x", &byte);
            output[i] = (unsigned char)byte;
        }

        unsigned char decrypted[MAX_INPUT_SIZE] = {0};
        decrypt_aes(output, key, decrypted);

        printf("Decrypted message: %s\n", decrypted);
    }

    return EXIT_SUCCESS;
}