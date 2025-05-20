//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

// Generate a random salt with a given length
void generate_salt(unsigned char* salt, int length) {
    RAND_bytes(salt, length);
}

// Generate a key from the password and salt
void generate_key(const char* password, unsigned char* salt, int salt_length, unsigned char* key, int key_length) {
    EVP_BytesToKey(EVP_aes_256_cbc(), EVP_sha256(), salt, (const unsigned char *) password, strlen(password), 1, key, NULL);
}

// Encrypt the data with the given key and iv
void encrypt(unsigned char *data, int data_length, unsigned char *key, unsigned char *iv, unsigned char *encrypted_data, int *encrypted_data_length) {
    EVP_CIPHER_CTX *ctx;
    int len, c_len;
    ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
    EVP_EncryptUpdate(ctx, encrypted_data, &len, data, data_length);
    *encrypted_data_length = len;
    EVP_EncryptFinal_ex(ctx, encrypted_data+len, &c_len);
    *encrypted_data_length += c_len;
    EVP_CIPHER_CTX_free(ctx);
}

// Decrypt the encrypted data with the given key and iv
void decrypt(unsigned char *encrypted_data, int encrypted_data_length, unsigned char *key, unsigned char *iv, unsigned char *decrypted_data, int *decrypted_data_length) {
    EVP_CIPHER_CTX *ctx;
    int len, p_len;
    ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
    EVP_DecryptUpdate(ctx, decrypted_data, &len, encrypted_data, encrypted_data_length);
    *decrypted_data_length = len;
    EVP_DecryptFinal_ex(ctx, decrypted_data+len, &p_len);
    *decrypted_data_length += p_len;
    EVP_CIPHER_CTX_free(ctx);
}

// Example usage
int main(int argc, char *argv[]) {
    const char *password = "my_password123";
    unsigned char salt[16];
    generate_salt(salt, sizeof(salt));

    unsigned char key[EVP_MAX_KEY_LENGTH];
    generate_key(password, salt, sizeof(salt), key, EVP_MAX_KEY_LENGTH);

    unsigned char iv[EVP_MAX_IV_LENGTH];
    RAND_bytes(iv, sizeof(iv));

    unsigned char data[] = "This is some plaintext data!";
    int data_length = strlen(data);

    unsigned char encrypted_data[EVP_ENCODE_LENGTH(sizeof(data))];
    int encrypted_data_length;
    encrypt(data, data_length, key, iv, encrypted_data, &encrypted_data_length);

    unsigned char decrypted_data[sizeof(data)];
    int decrypted_data_length;
    decrypt(encrypted_data, encrypted_data_length, key, iv, decrypted_data, &decrypted_data_length);

    decrypted_data[decrypted_data_length] = 0;
    printf("Decrypted data: %s\n", decrypted_data);
    return 0;
}