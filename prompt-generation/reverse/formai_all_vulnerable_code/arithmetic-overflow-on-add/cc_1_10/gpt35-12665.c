//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

void handleErrors(void)
{
    printf("An error occurred.\n");
    abort();
}

void print_hex(const char* prefix, const unsigned char* bytes, int len)
{
    printf("%s:", prefix);

    for (int i = 0; i < len; i++)
        printf("%02x", bytes[i]);

    printf("\n");
}

int main(void)
{
    EVP_MD_CTX* mdctx;
    const EVP_MD* md;
    unsigned char digest[EVP_MAX_MD_SIZE];
    unsigned int digest_len;
    char message[] = "Hello, world!";
    char password[] = "supersecret";

    // SHA-256
    md = EVP_get_digestbyname("sha256");
    if (md == NULL) handleErrors();

    mdctx = EVP_MD_CTX_new();
    if (mdctx == NULL) handleErrors();

    if (EVP_DigestInit_ex(mdctx, md, NULL) != 1) handleErrors();

    if (EVP_DigestUpdate(mdctx, message, strlen(message)) != 1) handleErrors();

    if (EVP_DigestFinal_ex(mdctx, digest, &digest_len) != 1) handleErrors();

    EVP_MD_CTX_free(mdctx);

    print_hex("SHA-256 hash", digest, digest_len);

    // AES-256-CBC
    const unsigned char* plaintext = (const unsigned char*) message;
    int plaintext_len = strlen(message);

    // Generate random iv
    unsigned char iv[EVP_MAX_IV_LENGTH];
    if (RAND_bytes(iv, 16) != 1) handleErrors();

    print_hex("Random iv", iv, 16);

    // Derive key from password
    const EVP_CIPHER* cipher = EVP_aes_256_cbc();
    unsigned char key[EVP_MAX_KEY_LENGTH];
    int key_len;

    if (EVP_BytesToKey(cipher, md, iv, (const unsigned char*) password, strlen(password), 1, key, NULL) != 1) handleErrors();

    key_len = EVP_CIPHER_key_length(cipher);

    print_hex("Derived key", key, key_len);

    // Encrypt
    int ciphertext_len;
    unsigned char* ciphertext = malloc(plaintext_len + EVP_MAX_BLOCK_LENGTH);

    EVP_CIPHER_CTX* ctx;

    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if (EVP_EncryptInit_ex(ctx, cipher, NULL, key, iv) != 1) handleErrors();

    if (EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, plaintext, plaintext_len) != 1) handleErrors();

    if (EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &ciphertext_len) != 1) handleErrors();

    ciphertext_len += plaintext_len;

    EVP_CIPHER_CTX_free(ctx);

    print_hex("Ciphertext", ciphertext, ciphertext_len);

    // Decrypt
    unsigned char* decrypted = malloc(ciphertext_len + EVP_MAX_BLOCK_LENGTH);

    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if (EVP_DecryptInit_ex(ctx, cipher, NULL, key, iv) != 1) handleErrors();

    if (EVP_DecryptUpdate(ctx, decrypted, &ciphertext_len, ciphertext, ciphertext_len) != 1) handleErrors();

    if (EVP_DecryptFinal_ex(ctx, decrypted + ciphertext_len, &ciphertext_len) != 1) handleErrors();

    plaintext_len = ciphertext_len;

    EVP_CIPHER_CTX_free(ctx);

    print_hex("Decrypted plaintext", decrypted, plaintext_len);

    // Clean up
    free(ciphertext);
    free(decrypted);

    return 0;
}