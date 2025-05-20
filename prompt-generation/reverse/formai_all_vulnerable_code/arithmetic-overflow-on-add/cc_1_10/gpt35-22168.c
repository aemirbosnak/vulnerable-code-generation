//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define KEY_SIZE 32
#define IV_SIZE 12
#define ENCRYPT_SIZE 256

int main()
{
    // Initialize input and encryption buffers
    unsigned char plaintext[256], ciphertext[ENCRYPT_SIZE], decryptedtext[256];

    // Generate a random key and IV 
    unsigned char key[KEY_SIZE], iv[IV_SIZE];
    RAND_bytes(key, KEY_SIZE);
    RAND_bytes(iv, IV_SIZE);

    // Define the encryption context
    EVP_CIPHER_CTX *ctx;
    ctx = EVP_CIPHER_CTX_new();
    EVP_CIPHER_CTX_init(ctx);

    // Set the encryption algorithm
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    // Get the plaintext input from the user
    printf("Enter plaintext: ");
    fgets(plaintext, 256, stdin);
    plaintext[strcspn(plaintext, "\n")] = 0; // remove newline character

    // Encrypt the plaintext
    int ciphertext_len, plaintext_len = strlen(plaintext);
    EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, plaintext, plaintext_len);
    EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &ciphertext_len);

    // Print the ciphertext
    printf("Ciphertext: ");
    for(int i=0; i<ciphertext_len+16; i++)
        printf("%02x", ciphertext[i]);
    printf("\n");

    // Set the decryption algorithm
    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    // Decrypt the ciphertext
    int decryptedtext_len;
    EVP_DecryptUpdate(ctx, decryptedtext, &decryptedtext_len, ciphertext, ciphertext_len);
    EVP_DecryptFinal_ex(ctx, decryptedtext + decryptedtext_len, &decryptedtext_len);

    // Print the decrypted plaintext
    printf("Decrypted text: %s\n", decryptedtext);

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
    return 0;
}