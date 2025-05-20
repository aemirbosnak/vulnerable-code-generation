//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

/* This program uses the OpenSSL library to generate cryptographic hashes
 * of user-provided input strings. The user can choose from several available
 * hash algorithms, such as SHA-256, SHA-384, and SHA-512.
 */ 

// Print a menu of hash algorithms supported by OpenSSL
void print_menu() {
    printf("Choose a hash algorithm:\n");
    printf("1. SHA-256\n");
    printf("2. SHA-384\n");
    printf("3. SHA-512\n");
}

// Read a user-provided string from standard input
char* read_string() {
    char buffer[100];
    printf("Enter a string to hash: ");
    fgets(buffer, 100, stdin);
    buffer[strcspn(buffer, "\n")] = 0;    // remove newline character
    char* str = (char*)malloc(strlen(buffer) + 1);
    strcpy(str, buffer);
    return str;
}

// Compute a cryptographic hash of a given string using the specified algorithm
void compute_hash(char* str, int algorithm, unsigned char** hash, unsigned int* hash_len) {
    EVP_MD_CTX* mdctx;
    const EVP_MD* md;

    switch(algorithm) {
        case 1:
            md = EVP_sha256();
            break;
        case 2:
            md = EVP_sha384();
            break;
        case 3:
            md = EVP_sha512();
            break;
        default:
            printf("Invalid algorithm\n");
            return;
    }

    mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, md, NULL);
    EVP_DigestUpdate(mdctx, str, strlen(str));
    EVP_DigestFinal_ex(mdctx, *hash, hash_len);
    EVP_MD_CTX_free(mdctx);
}

int main() {
    print_menu();

    int algorithm;
    scanf("%d", &algorithm);
    getchar();    // remove the newline character from input buffer

    char* str = read_string();

    unsigned char* hash = (unsigned char*)malloc(EVP_MAX_MD_SIZE);
    unsigned int hash_len;

    compute_hash(str, algorithm, &hash, &hash_len);

    printf("Hash of \"%s\":\n", str);
    for(int i = 0; i < hash_len; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    free(str);
    free(hash);

    return 0;
}