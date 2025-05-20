//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: minimalist
/*
 * This program generates a secret key to be used for encryption and decryption of messages.
 * The key is generated using the SHA-256 hash function.
 * The user inputs a password which is used to derive the key, so the password must be kept secret.
 * The generated key is used to encrypt and decrypt messages using the AES-256 encryption algorithm.
 * 
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/sha.h>

#define KEY_LEN 32 // Length of AES-256 key in bytes
#define IV_LEN 16 // Length of initialization vector in bytes
#define SALT_LEN 16 // Length of salt for key derivation in bytes
#define STR_MAX_LEN 1024 // Maximum length of input string

// Function that generates an AES-256 secret key by deriving it from the password
int generate_key(unsigned char *key, unsigned char *salt, char *password, size_t password_len){

    // Derive key using PBKDF2 with SHA-256 hash function
    if(!PKCS5_PBKDF2_HMAC(password, password_len, salt, SALT_LEN, 10000, EVP_sha256(), KEY_LEN, key)) {
        return 0;
    }

    return 1;
}

// Function that encrypts a message using AES-256 with CBC mode
int aes_256_cbc_encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext){

    EVP_CIPHER_CTX *ctx;

    int len;
    int ciphertext_len;

    if(!(ctx = EVP_CIPHER_CTX_new())){
        return 0;
    }
    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)){
        return 0;
    }

    // Encrypt the plaintext
    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len)){
        return 0;
    }
    ciphertext_len = len;

    // Finalize the encryption
    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)){
        return 0;
    }
    ciphertext_len += len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

// Function that decrypts a message using AES-256 with CBC mode
int aes_256_cbc_decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext){

    EVP_CIPHER_CTX *ctx;

    int len;
    int plaintext_len;

    if(!(ctx = EVP_CIPHER_CTX_new())){
        return 0;
    }
    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)){
        return 0;
    }

    // Decrypt the ciphertext
    if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len)){
        return 0;
    }
    plaintext_len = len;

    // Finalize the decryption
    if(1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)){
        return 0;
    }
    plaintext_len += len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}

int main() {

    unsigned char key[KEY_LEN];
    unsigned char iv[IV_LEN];
    unsigned char salt[SALT_LEN];
    char password[STR_MAX_LEN];
    char plaintext[STR_MAX_LEN];
    unsigned char ciphertext[STR_MAX_LEN + EVP_MAX_BLOCK_LENGTH];

    // Initialize OpenSSL library
    OpenSSL_add_all_algorithms();

    // Generate a salt for key derivation
    if(!RAND_bytes(salt, SALT_LEN)){
        return 1;
    }

    // Prompt user for a password and input string
    printf("Enter a password (up to %d characters): ", STR_MAX_LEN);
    fgets(password, STR_MAX_LEN, stdin);
    password[strcspn(password, "\n")] = 0;
    printf("Enter a string to encrypt (up to %d characters): ", STR_MAX_LEN);
    fgets(plaintext, STR_MAX_LEN, stdin);
    plaintext[strcspn(plaintext, "\n")] = 0;

    // Generate the secret key
    if(!generate_key(key, salt, password, strlen(password))){
        return 1;
    }

    // Generate an initialization vector for AES-256 CBC mode
    if(!RAND_bytes(iv, IV_LEN)){
        return 1;
    }

    // Encrypt the plaintext using AES-256 CBC mode
    int ciphertext_len = aes_256_cbc_encrypt((unsigned char*) plaintext, strlen(plaintext), key, iv, ciphertext);
    if(ciphertext_len <= 0){
        return 1;
    }

    // Print out the salt, initialization vector, and ciphertext in hexadecimal format
    printf("Salt: ");
    for(int i = 0; i < SALT_LEN; i++){
        printf("%02x", salt[i]);
    }
    printf("\nIV: ");
    for(int i = 0; i < IV_LEN; i++){
        printf("%02x", iv[i]);
    }
    printf("\nCiphertext: ");
    for(int i = 0; i < ciphertext_len; i++){
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // Decrypt the ciphertext using AES-256 CBC mode
    unsigned char decrypted[STR_MAX_LEN];
    int decrypted_len = aes_256_cbc_decrypt(ciphertext, ciphertext_len, key, iv, decrypted);
    if(decrypted_len <= 0){
        return 1;
    }

    // Print out the decrypted plaintext
    printf("Decrypted plaintext: %s\n", decrypted);

    return 0;
}