//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: interoperable
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>
#include<openssl/evp.h>
#include<openssl/rand.h>
#include<openssl/md5.h>

// function to generate random hex string
void random_hex_string(uint8_t *string, size_t len)
{
    RAND_bytes(string, len);
    for(size_t i = 0; i < len; i++){
        sprintf((char *) string + (2 * i), "%02x", string[i]);
    }
}

// function to generate MD5 hash of input string
void md5_hash(uint8_t *input, uint8_t *output)
{
    uint8_t digest[MD5_DIGEST_LENGTH];
    MD5(input, strlen((char*)input), digest);
    for(int i = 0; i < MD5_DIGEST_LENGTH; i++){
        sprintf((char *) output + (2 * i), "%02x", digest[i]);
    }
}

int main(int argc, char **argv)
{
    // Message to be encrypted
    uint8_t *plaintextMessage = (uint8_t *)"Hello World!";

    // Generate random key
    uint8_t key[EVP_MAX_KEY_LENGTH];
    random_hex_string(key, EVP_MAX_KEY_LENGTH);

    // Generate random IV
    uint8_t iv[EVP_MAX_IV_LENGTH];
    random_hex_string(iv, EVP_MAX_IV_LENGTH);

    // Initialize OpenSSL cipher context with AES-256-CBC
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    // Get the cipher block size and allocate memory for the ciphertext
    int cipher_block_size = EVP_CIPHER_CTX_block_size(ctx);
    uint8_t *ciphertext = malloc(sizeof(uint8_t) * (strlen((char*)plaintextMessage) + cipher_block_size));

    // Encrypt the message
    int ciphertext_len;
    EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, plaintextMessage, strlen((char*)plaintextMessage));
    int ciphertext_final_len;
    EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &ciphertext_final_len);

    // Concatenate ciphertext with key and IV
    uint8_t *encrypted_message = malloc(sizeof(uint8_t) * (ciphertext_len + ciphertext_final_len + EVP_MAX_KEY_LENGTH + EVP_MAX_IV_LENGTH));
    memcpy(encrypted_message, key, EVP_MAX_KEY_LENGTH);
    memcpy(encrypted_message + EVP_MAX_KEY_LENGTH, iv, EVP_MAX_IV_LENGTH);
    memcpy(encrypted_message + EVP_MAX_KEY_LENGTH + EVP_MAX_IV_LENGTH, ciphertext, ciphertext_len + ciphertext_final_len);

    // Generate MD5 hash of the encrypted message
    uint8_t md5_digest[MD5_DIGEST_LENGTH];
    md5_hash(encrypted_message, md5_digest);

    // Print the encrypted message in hex format along with the MD5 hash
    printf("Encrypted Message: ");
    for(int i = 0; i < ciphertext_len + ciphertext_final_len + EVP_MAX_KEY_LENGTH + EVP_MAX_IV_LENGTH; i++){
        printf("%02x", encrypted_message[i]);
    }
    printf("\nMD5 Hash: ");
    for(int i = 0; i < MD5_DIGEST_LENGTH; i++){
        printf("%02x", md5_digest[i]);
    }
    printf("\n");

    // Clean up
    free(ciphertext);
    free(encrypted_message);
    EVP_CIPHER_CTX_free(ctx);

    return 0;
}