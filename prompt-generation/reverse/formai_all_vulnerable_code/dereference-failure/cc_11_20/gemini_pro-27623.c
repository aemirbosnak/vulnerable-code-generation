//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: visionary
// Embracing the Enigmatic: A Tale of Modern Encryption

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

// A somber night, the shadows dance, secrets whispered in the wind.
// A clandestine rendezvous, a message concealed from prying eyes.

// A journey into the realm of modern encryption, a symphony of bits and bytes.
int main() {

    // 1. Cipher selection: A strategic choice between algorithms.
    const EVP_CIPHER *cipher = EVP_aes_256_cbc();
    // Cipher strength: 256-bit key length, Cipher Block Chaining (CBC) mode for added security.

    // 2. Key generation: A touch of randomness, a sprinkle of unpredictability.
    unsigned char key[EVP_CIPHER_key_length(cipher)];
    if (RAND_bytes(key, EVP_CIPHER_key_length(cipher)) <= 0) {
        printf("Failed to generate random key.");
        return EXIT_FAILURE;
    }

    // 3. Initialization vector: A beacon guiding encryption's dance.
    unsigned char iv[EVP_CIPHER_iv_length(cipher)];
    if (RAND_bytes(iv, EVP_CIPHER_iv_length(cipher)) <= 0) {
        printf("Failed to generate initialization vector.");
        return EXIT_FAILURE;
    }

    // 4. Context creation: A stage set for encryption's grand performance.
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (ctx == NULL) {
        printf("Failed to create encryption context.");
        return EXIT_FAILURE;
    }

    // 5. Encryption commencement: Transforming plaintext into an enigmatic dance.
    if (EVP_EncryptInit_ex(ctx, cipher, NULL, key, iv) != 1) {
        printf("Failed to initialize encryption.");
        return EXIT_FAILURE;
    }

    // Message to be encrypted: A secret to be concealed, safeguarded from harm.
    const unsigned char *plaintext = "Message to be encrypted";

    // 6. Encryption process: A magical transformation, obscuring the message's essence.
    size_t ciphertext_len = 0;
    unsigned char ciphertext[strlen(plaintext) + 1];
    if (EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, plaintext, strlen(plaintext)) != 1) {
        printf("Failed to encrypt plaintext.");
        return EXIT_FAILURE;
    }

    // 7. Final encryption steps: Completing the spell, sealing the secrets within.
    if (EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &ciphertext_len) != 1) {
        printf("Failed to finalize encryption.");
        return EXIT_FAILURE;
    }

    // 8. Decryption commencement: Unveiling the secrets, revealing the encrypted message.
    EVP_CIPHER_CTX *dctx = EVP_CIPHER_CTX_new();
    if (dctx == NULL) {
        printf("Failed to create decryption context.");
        return EXIT_FAILURE;
    }

    if (EVP_DecryptInit_ex(dctx, cipher, NULL, key, iv) != 1) {
        printf("Failed to initialize decryption.");
        return EXIT_FAILURE;
    }

    // 9. Decryption process: A dance in reverse, unmasking the hidden message.
    size_t decryptedtext_len = 0;
    unsigned char decryptedtext[strlen(ciphertext) + 1];
    if (EVP_DecryptUpdate(dctx, decryptedtext, &decryptedtext_len, ciphertext, ciphertext_len) != 1) {
        printf("Failed to decrypt ciphertext.");
        return EXIT_FAILURE;
    }

    if (EVP_DecryptFinal_ex(dctx, decryptedtext + decryptedtext_len, &decryptedtext_len) != 1) {
        printf("Failed to finalize decryption.");
        return EXIT_FAILURE;
    }

    // 10. Message revelation: Unveiling the secrets, revealing the decrypted message.
    printf("Decrypted Message: %s", decryptedtext);

    // Cleanup: A symphony's end, instruments laid to rest.
    EVP_CIPHER_CTX_free(ctx);
    EVP_CIPHER_CTX_free(dctx);

    return EXIT_SUCCESS;
}