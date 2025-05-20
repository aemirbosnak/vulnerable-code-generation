//FormAI DATASET v1.0 Category: Cryptographic hash fucntionPassword management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define MAX_PASSWORD_LENGTH 1024

unsigned char* sha256_hash(const unsigned char* message, size_t message_len) {
    EVP_MD_CTX* mdctx;
    const EVP_MD* md;
    unsigned char* digest;
    unsigned int digest_len;
    
    mdctx = EVP_MD_CTX_new();
    md = EVP_sha256();
    
    if (mdctx == NULL || md == NULL) {
        return NULL;
    }
    
    EVP_DigestInit_ex(mdctx, md, NULL);
    EVP_DigestUpdate(mdctx, message, message_len);
    digest = (unsigned char*)malloc(EVP_MD_size(md));
    
    if (digest == NULL) {
        EVP_MD_CTX_free(mdctx);
        return NULL;
    }
    
    EVP_DigestFinal_ex(mdctx, digest, &digest_len);
    EVP_MD_CTX_free(mdctx);
    
    return digest;
}

int main() {
    char password[MAX_PASSWORD_LENGTH], confirm_password[MAX_PASSWORD_LENGTH];
    
    printf("Enter your password (max length %d): ", MAX_PASSWORD_LENGTH - 1);
    if (fgets(password, MAX_PASSWORD_LENGTH, stdin) == NULL) {
        printf("Error: Could not read password.\n");
        return EXIT_FAILURE;
    }
    
    size_t password_len = strlen(password) - 1;
    if (password[password_len] == '\n') {
        password[password_len] = '\0';
    }
    
    printf("Confirm your password: ");
    if (fgets(confirm_password, MAX_PASSWORD_LENGTH, stdin) == NULL) {
        printf("Error: Could not read password.\n");
        return EXIT_FAILURE;
    }
    
    size_t confirm_password_len = strlen(confirm_password) - 1;
    if (confirm_password[confirm_password_len] == '\n') {
        confirm_password[confirm_password_len] = '\0';
    }
    
    if (strcmp(password, confirm_password) != 0) {
        printf("Error: Passwords do not match.\n");
        return EXIT_FAILURE;
    }
    
    unsigned char* digest = sha256_hash((const unsigned char*)password, password_len);
    if (digest == NULL) {
        printf("Error: SHA-256 hashing failed.\n");
        return EXIT_FAILURE;
    }
    
    printf("Password hash (SHA-256): ");
    
    for (unsigned int i = 0; i < EVP_MD_size(EVP_sha256()); i++) {
        printf("%02x", digest[i]);
    }
    
    printf("\n");
    free(digest);
    return EXIT_SUCCESS;
}