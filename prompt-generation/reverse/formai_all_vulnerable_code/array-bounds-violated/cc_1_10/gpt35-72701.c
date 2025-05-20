//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: asynchronous
#include <stdio.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <string.h>
#include <stdlib.h>

void generate_keys(RSA **pub, RSA **priv) { // Generate public and private keys
    RSA *rsa = RSA_generate_key(2048, RSA_F4, NULL, NULL);

    *pub = RSAPublicKey_dup(rsa); // Duplicate the generated key for public and private keys
    *priv = RSAPrivateKey_dup(rsa);

    RSA_free(rsa);
}

void encrypt_decrypt(RSA *pub, RSA *priv) { // Encrypt and then decrypt the message
    char *original_message = "This is a secret message.";
    unsigned char ciphertext[256];
    unsigned char decryptedtext[256];
    int ciphertext_length, decryptedtext_length;

    // Encrypt the message using public key
    ciphertext_length = RSA_public_encrypt(strlen(original_message), (unsigned char*)original_message, ciphertext, pub, RSA_PKCS1_OAEP_PADDING);
    if (ciphertext_length == -1) {
        printf("Encryption failed\n");
        return;
    }

    // Decrypt the message using private key
    decryptedtext_length = RSA_private_decrypt(ciphertext_length, ciphertext, decryptedtext, priv, RSA_PKCS1_OAEP_PADDING);
    if (decryptedtext_length == -1) {
        printf("Decryption failed\n");
        return;
    }

    decryptedtext[decryptedtext_length] = '\0';

    printf("Original message: %s\n", original_message);
    printf("Decrypted message: %s\n", decryptedtext);
}

int main() {
    RSA *pub = NULL, *priv = NULL;

    generate_keys(&pub, &priv);

    encrypt_decrypt(pub, priv);

    RSA_free(pub);
    RSA_free(priv);

    return 0;
}