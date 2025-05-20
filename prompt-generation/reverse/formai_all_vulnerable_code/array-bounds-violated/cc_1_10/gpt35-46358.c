//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

#define KEY_SIZE 32

int main(int argc, char* argv[]) {
    // Initialize data and key variables
    unsigned char data[] = "Hello, world!";
    unsigned char key[KEY_SIZE] = "mysecretkey";
    unsigned char iv[EVP_MAX_IV_LENGTH] = "myinitialvector";
    unsigned char cipher_text[256];
    unsigned char decrypted_text[256];

    // Get the length of the data
    size_t data_len = strlen((char*)data);

    // Initialize Context and Cipher
    EVP_CIPHER_CTX *context;
    const EVP_CIPHER *cipher;

    // Allocate memory for the context
    context = EVP_CIPHER_CTX_new();

    // Get the cipher by name
    cipher = EVP_get_cipherbyname("aes-256-cbc");

    // Initialize the encryption operation
    EVP_EncryptInit_ex(context, cipher, NULL, key, iv);

    // Encrypt the data
    int len;
    EVP_EncryptUpdate(context, cipher_text, &len, data, data_len);

    // Finalize the encryption
    int cipher_len;
    EVP_EncryptFinal_ex(context, cipher_text + len, &cipher_len);

    // Set the total cipher length
    cipher_len += len;

    // Print the cipher text
    printf("Cipher Text: ");
    for (int i = 0; i < cipher_len; i++) {
        printf("%02x", cipher_text[i]);
    }
    printf("\n");

    // Initialize the decryption operation
    EVP_DecryptInit_ex(context, cipher, NULL, key, iv);

    // Decrypt the data
    EVP_DecryptUpdate(context, decrypted_text, &len, cipher_text, cipher_len);

    // Finalize the decryption
    int decrypted_len;
    EVP_DecryptFinal_ex(context, decrypted_text + len, &decrypted_len);

    // Set the total decrypted length
    decrypted_len += len;

    // Null terminate the decrypted text
    decrypted_text[decrypted_len] = '\0';

    // Print the decrypted text
    printf("Decrypted Text: %s\n", decrypted_text);

    // Cleanup
    EVP_CIPHER_CTX_free(context);

    return 0;
}