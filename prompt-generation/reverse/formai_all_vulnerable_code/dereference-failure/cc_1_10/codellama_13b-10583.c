//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#define KEY_SIZE 32
#define IV_SIZE 16

// Generate a random key and IV
void generate_key_iv(unsigned char *key, unsigned char *iv) {
    if (RAND_bytes(key, KEY_SIZE) != 1) {
        fprintf(stderr, "Error generating key\n");
        exit(1);
    }
    if (RAND_bytes(iv, IV_SIZE) != 1) {
        fprintf(stderr, "Error generating IV\n");
        exit(1);
    }
}

// Encrypt a file using AES-256-CBC
void encrypt_file(FILE *infile, FILE *outfile, unsigned char *key, unsigned char *iv) {
    AES_KEY aes_key;
    AES_set_encrypt_key(key, KEY_SIZE * 8, &aes_key);

    unsigned char inbuf[1024];
    unsigned char outbuf[1024];
    int inlen;

    while ((inlen = fread(inbuf, 1, sizeof(inbuf), infile)) > 0) {
        AES_cbc_encrypt(inbuf, outbuf, inlen, &aes_key, iv, AES_ENCRYPT);
        fwrite(outbuf, 1, inlen, outfile);
    }
}

// Decrypt a file using AES-256-CBC
void decrypt_file(FILE *infile, FILE *outfile, unsigned char *key, unsigned char *iv) {
    AES_KEY aes_key;
    AES_set_decrypt_key(key, KEY_SIZE * 8, &aes_key);

    unsigned char inbuf[1024];
    unsigned char outbuf[1024];
    int inlen;

    while ((inlen = fread(inbuf, 1, sizeof(inbuf), infile)) > 0) {
        AES_cbc_encrypt(inbuf, outbuf, inlen, &aes_key, iv, AES_DECRYPT);
        fwrite(outbuf, 1, inlen, outfile);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <operation> <input file> <output file>\n", argv[0]);
        exit(1);
    }

    // Generate a random key and IV
    unsigned char key[KEY_SIZE];
    unsigned char iv[IV_SIZE];
    generate_key_iv(key, iv);

    // Open input and output files
    FILE *infile = fopen(argv[2], "rb");
    FILE *outfile = fopen(argv[3], "wb");

    if (infile == NULL || outfile == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    // Perform the requested operation
    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt_file(infile, outfile, key, iv);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decrypt_file(infile, outfile, key, iv);
    } else {
        fprintf(stderr, "Invalid operation\n");
        exit(1);
    }

    // Close input and output files
    fclose(infile);
    fclose(outfile);

    return 0;
}