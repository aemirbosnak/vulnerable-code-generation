//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

int main(int argc, char* argv[]) {

    // check if command line arguments are correct
    if(argc != 4) {
        printf("Error! Usage: crypto <plaintext> <key> <iv>\n");
        return 1;
    }

    char* plaintext = argv[1];
    char* key_string = argv[2];
    char* iv_string = argv[3];

    // convert key and iv strings to byte arrays
    unsigned char* key = (unsigned char*) key_string;
    unsigned char* iv = (unsigned char*) iv_string;

    // initialize cipher object with key info
    EVP_CIPHER_CTX* cipher_context = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(cipher_context, EVP_aes_256_cbc(), NULL, key, iv);

    // allocate memory for ciphertext
    int plaintext_length = strlen(plaintext);
    int ciphertext_length = plaintext_length + EVP_MAX_BLOCK_LENGTH;
    unsigned char* ciphertext = (unsigned char*) malloc(ciphertext_length * sizeof(unsigned char));

    int output_length;
    EVP_EncryptUpdate(cipher_context, ciphertext, &output_length, (unsigned char*) plaintext, plaintext_length);

    int final_length;
    EVP_EncryptFinal_ex(cipher_context, ciphertext + output_length, &final_length);

    int actual_ciphertext_length = output_length + final_length;

    // output ciphertext
    for(int i=0; i<actual_ciphertext_length; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // clean up
    free(ciphertext);
    EVP_CIPHER_CTX_free(cipher_context);

    return 0;
}