//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

int main(int argc, char *argv[]) {
    // Check if inputs are correct
    if (argc < 4) {
        printf("Error: Insufficient inputs provided.\n");
        printf("Usage: crypto -<hash/md5/sha256> <string/file name>\n");
        return EXIT_FAILURE;
    }
    if (strcmp(argv[1], "-hash") != 0 && strcmp(argv[1], "-md5") != 0 
        && strcmp(argv[1], "-sha256") != 0) {
        printf("Error: Invalid hash algorithm specified.\n");
        printf("Usage: crypto -<hash/md5/sha256> <string/file name>\n");
        return EXIT_FAILURE;
    }
    
    EVP_MD_CTX *md_ctx = EVP_MD_CTX_new();
    const EVP_MD *md;
    
    // Initialize hash algorithm
    if (strcmp(argv[1], "-hash") == 0) {
        md = EVP_sha1();
    } else if (strcmp(argv[1], "-md5") == 0) {
        md = EVP_md5();
    } else {
        md = EVP_sha256();
    }
    
    // Handle file input
    if (strstr(argv[2], ".txt") != NULL) {
        FILE *input_file = fopen(argv[2], "r");
        if (input_file == NULL) {
            printf("Error: Invalid file input. File does not exist or cannot be opened.\n");
            return EXIT_FAILURE;
        }
        
        char *input_text = NULL;
        size_t len = 0;
        ssize_t read;
        while ((read = getline(&input_text, &len, input_file)) != -1) {}
        fclose(input_file);
        
        input_text[strcspn(input_text, "\n")] = 0;
        unsigned char *hash = (unsigned char *) malloc(EVP_MAX_MD_SIZE);
        unsigned int hash_len;
        
        EVP_DigestInit_ex(md_ctx, md, NULL);
        EVP_DigestUpdate(md_ctx, input_text, strlen(input_text));
        EVP_DigestFinal_ex(md_ctx, hash, &hash_len);
        EVP_MD_CTX_free(md_ctx);

        printf("Hash for '%s': ", input_text);
        for (int i = 0; i < hash_len; i++) {
            printf("%02x", hash[i]);
        }
        printf("\n");
    } else {
        // Handle string input
        unsigned char *hash = (unsigned char *) malloc(EVP_MAX_MD_SIZE);
        unsigned int hash_len;
        
        EVP_DigestInit_ex(md_ctx, md, NULL);
        EVP_DigestUpdate(md_ctx, argv[2], strlen(argv[2]));
        EVP_DigestFinal_ex(md_ctx, hash, &hash_len);
        EVP_MD_CTX_free(md_ctx);

        printf("Hash for '%s': ", argv[2]);
        for (int i = 0; i < hash_len; i++) {
            printf("%02x", hash[i]);
        }
        printf("\n");
    }
    
    return EXIT_SUCCESS;
}