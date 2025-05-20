//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define MAX_BUFFER_SIZE 1024

int main(void) {
    // Initialization of variables
    int i, inputLen, outputLen;
    unsigned char input[MAX_BUFFER_SIZE], output[MAX_BUFFER_SIZE];
    unsigned char key[EVP_MAX_KEY_LENGTH], iv[EVP_MAX_IV_LENGTH];
    char * cipherName = "aes-256-cbc"; // cipher name
    char * message = "Hello Cryptography!"; // the message to be encrypted
    EVP_CIPHER_CTX * ctx; // the cipher context

    // Generate key and initialization vector
    EVP_BytesToKey(EVP_get_cipherbyname(cipherName), EVP_sha256(), NULL, (unsigned char *) "password", 8, 1, key, iv);

    // Initialize the cipher context
    ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_get_cipherbyname(cipherName), NULL, key, iv);

    // Encrypt the message
    EVP_EncryptUpdate(ctx, output, &outputLen, (unsigned char *) message, strlen(message));
    EVP_EncryptFinal_ex(ctx, output + outputLen, &i);

    // Print the encrypted message
    printf("Encrypted Message: ");
    for (i = 0; i < outputLen + 16; i++) {
        printf("%02x", output[i]);
    }
    printf("\n");

    // Decrypt the message
    EVP_DecryptInit_ex(ctx, EVP_get_cipherbyname(cipherName), NULL, key, iv);
    EVP_DecryptUpdate(ctx, input, &inputLen, output, outputLen);
    EVP_DecryptFinal_ex(ctx, input + inputLen, &i);

    // Null terminate the decrypted message
    input[inputLen] = '\0';

    // Print the decrypted message
    printf("Decrypted Message: %s\n", input);

    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    return 0;
}