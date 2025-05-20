//GEMINI-pro DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>

RSA *generate_rsa_key(int bits) {
    RSA *rsa = RSA_new();
    BIGNUM *bn = BN_new();
    BN_set_word(bn, RSA_F4);
    RSA_generate_key_ex(rsa, bits, bn, NULL);
    BN_free(bn);
    return rsa;
}

void save_public_key(RSA *rsa, char *filename) {
    FILE *fp = fopen(filename, "w");
    PEM_write_RSA_PUBKEY(fp, rsa);
    fclose(fp);
}

RSA *load_public_key(char *filename) {
    FILE *fp = fopen(filename, "r");
    RSA *rsa = PEM_read_RSA_PUBKEY(fp, NULL, NULL, NULL);
    fclose(fp);
    return rsa;
}

int encrypt(RSA *rsa, unsigned char *message, unsigned char *encrypted) {
    int size = RSA_size(rsa);
    return RSA_public_encrypt(strlen(message), message, encrypted, rsa, RSA_PKCS1_OAEP_PADDING);
}

int decrypt(RSA *rsa, unsigned char *encrypted, unsigned char *message) {
    int size = RSA_size(rsa);
    return RSA_public_decrypt(size, encrypted, message, rsa, RSA_PKCS1_OAEP_PADDING);
}

int main() {
    RSA *rsa = generate_rsa_key(2048);
    save_public_key(rsa, "public.pem");
    RSA *rsa_public = load_public_key("public.pem");
    unsigned char message[] = "Hello, world!";
    unsigned char encrypted[RSA_size(rsa)];
    int size = encrypt(rsa_public, message, encrypted);
    unsigned char decrypted[size];
    decrypt(rsa_public, encrypted, decrypted);
    printf("Message: %s\n", message);
    printf("Encrypted: ");
    for (int i = 0; i < size; i++) {
        printf("%02X", encrypted[i]);
    }
    printf("\nDecrypted: %s\n", decrypted);
    RSA_free(rsa);
    RSA_free(rsa_public);
    return 0;
}