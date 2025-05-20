//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: calm
#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

// This function generates a random salt
void generate_salt(unsigned char* salt, int salt_len)
{
    FILE* fp;
    fp = fopen("/dev/urandom", "r");
    fread(salt, salt_len, 1, fp);
    fclose(fp);
}

int main()
{
    // Plaintext message to be encrypted
    unsigned char plaintext[] = "This is a top secret message.";
    
    // Generate a random salt of length 8
    unsigned char salt[8];
    generate_salt(salt, 8);
    
    // Password used for key derivation
    const char* password = "myverystrongpassword";
    
    // Key derived from password and salt using PBKDF2
    unsigned char key[EVP_MAX_KEY_LENGTH];
    const EVP_CIPHER* cipher = EVP_aes_256_cbc();
    int key_len = EVP_BytesToKey(cipher, EVP_sha256(), salt, (unsigned char*) password, strlen(password), 1000, key, NULL);
    
    // IV (initialization vector)
    unsigned char iv[EVP_MAX_IV_LENGTH];
    const unsigned char default_iv[EVP_MAX_IV_LENGTH] = {0};
    memcpy(iv, default_iv, EVP_MAX_IV_LENGTH);
    
    // Size of the ciphertext buffer
    int ciphertext_len = strlen((const char*) plaintext) + EVP_CIPHER_block_size(cipher);
    
    // Ciphertext buffer
    unsigned char ciphertext[ciphertext_len];
    
    // Encryption
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, cipher, NULL, key, iv);
    int len;
    EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, strlen((const char*) plaintext));
    int ciphertext_len2;
    EVP_EncryptFinal_ex(ctx, ciphertext + len, &ciphertext_len2);
    EVP_CIPHER_CTX_free(ctx);
    ciphertext_len += ciphertext_len2;
    
    // Output
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: ");
    for (int i = 0; i < ciphertext_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");
    
    return 0;
}