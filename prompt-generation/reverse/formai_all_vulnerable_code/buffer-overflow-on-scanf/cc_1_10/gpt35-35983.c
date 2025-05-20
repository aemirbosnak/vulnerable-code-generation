//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rsa.h>
#include <openssl/bio.h>
#include <openssl/pem.h>

int main()
{
    char message[100];
    RSA *pubkey = NULL;
    RSA *privkey = NULL;

    // Generate public key and private key
    pubkey = RSA_new();
    privkey = RSA_new();
    BIGNUM* exponent = BN_new();
    BN_set_word(exponent, RSA_F4);
    int key_len = 2048;

    if (!RSA_generate_key_ex(pubkey, key_len, exponent, NULL))
    {
        printf("Error generating public key\n");
        return -1;
    }

    if (!RSA_generate_key_ex(privkey, key_len, exponent, NULL))
    {
        printf("Error generating private key\n");
        return -1;
    }

    // Print the generated keys
    BIO *bp;
    bp = BIO_new(BIO_s_mem());
    PEM_write_bio_RSAPrivateKey(bp, privkey, NULL, NULL, 0, NULL, NULL);
    char *privkey_string;
    long privkey_size = BIO_get_mem_data(bp, &privkey_string);
    printf("Private Key:\n%s\n", privkey_string);

    bp = BIO_new(BIO_s_mem());
    PEM_write_bio_RSAPublicKey(bp, pubkey);
    char *pubkey_string;
    long pubkey_size = BIO_get_mem_data(bp, &pubkey_string);
    printf("Public Key:\n%s\n", pubkey_string);

    // Encrypt the message using public key
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);
    unsigned char encrypted_message[256];
    int encrypted_length = RSA_public_encrypt(strlen(message) + 1, (unsigned char *)message, encrypted_message, pubkey, RSA_PKCS1_PADDING);
    if (encrypted_length == -1)
    {
        printf("Error encrypting the message\n");
        return -1;
    }
    printf("Encrypted message:\n");
    for (int i = 0; i < encrypted_length; i++)
    {
        printf("%02X", encrypted_message[i]);
    }
    printf("\n");

    // Decrypt the message using private key
    unsigned char decrypted_message[256];
    int decrypted_length = RSA_private_decrypt(encrypted_length, encrypted_message, decrypted_message, privkey, RSA_PKCS1_PADDING);
    if (decrypted_length == -1)
    {
        printf("Error decrypting the message\n");
        return -1;
    }
    printf("Decrypted message: %s\n", decrypted_message);

    // Free the memory
    RSA_free(pubkey);
    RSA_free(privkey);

    return 0;
}