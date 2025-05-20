//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

void handleErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}

// Function to generate RSA keys
void generate_keys(RSA **public_key, RSA **private_key) {
    int bits = 2048;
    unsigned long e = RSA_F4;

    *private_key = RSA_generate_key(bits, e, NULL, NULL);
    if (*private_key == NULL) {
        handleErrors();
    }

    BIO *bp_public = BIO_new(BIO_s_mem());
    BIO *bp_private = BIO_new(BIO_s_mem());

    if (PEM_write_bio_RSAPublicKey(bp_public, *private_key) != 1) {
        handleErrors();
    }
    if (PEM_write_bio_RSAPrivateKey(bp_private, *private_key, NULL, NULL, 0, NULL, NULL) != 1) {
        handleErrors();
    }

    *public_key = PEM_read_bio_RSAPublicKey(bp_public, NULL, NULL, NULL);
    if (*public_key == NULL) {
        handleErrors();
    }

    BIO_free_all(bp_public);
    BIO_free_all(bp_private);
}

// Function to encrypt a message
int encrypt_message(RSA *public_key, unsigned char *message, unsigned char *encrypted_message) {
    int result = RSA_public_encrypt(strlen((const char *)message), message, encrypted_message, public_key, RSA_PKCS1_OAEP_PADDING);
    if (result == -1) {
        handleErrors();
    }
    return result;
}

// Function to decrypt a message
int decrypt_message(RSA *private_key, unsigned char *encrypted_message, unsigned char *decrypted_message) {
    int result = RSA_private_decrypt(RSA_size(private_key), encrypted_message, decrypted_message, private_key, RSA_PKCS1_OAEP_PADDING);
    if (result == -1) {
        handleErrors();
    }
    return result;
}

int main() {
    RSA *public_key = NULL;
    RSA *private_key = NULL;
	
    generate_keys(&public_key, &private_key);

    unsigned char *message = (unsigned char *)"Hello, this is a secret message.";
    unsigned char encrypted_message[256];
    unsigned char decrypted_message[256];

    printf("Original message: %s\n", message);

    int encrypted_length = encrypt_message(public_key, message, encrypted_message);
    printf("Encrypted message length: %d bytes\n", encrypted_length);

    int decrypted_length = decrypt_message(private_key, encrypted_message, decrypted_message);
    decrypted_message[decrypted_length] = '\0'; // Null-terminate the decrypted string
    printf("Decrypted message: %s\n", decrypted_message);

    RSA_free(public_key);
    RSA_free(private_key);

    return 0;
}