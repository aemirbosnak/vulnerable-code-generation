//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <openssl/evp.h>
#include <string.h>

/* Function to generate a cryptographic hash of a given data using SHA-256 */
char* sha256_hash(const unsigned char* data, size_t data_len) {

    EVP_MD_CTX* md_ctx;
    const EVP_MD* md;
    int md_len;
    char* hash;
    int i;

    // Create a message digest context
    md_ctx = EVP_MD_CTX_new();

    // Set the digest algorithm to SHA-256
    md = EVP_sha256();

    // Initialise the message digest context with the chosen algorithm
    EVP_DigestInit_ex(md_ctx, md, NULL);

    // Update the message digest context with the input data
    EVP_DigestUpdate(md_ctx, data, data_len);

    // Finalise the message digest and get the resulting hash value
    md_len = EVP_MD_size(md);
    hash = (char*)malloc(md_len * 2 + 1);
    memset(hash, 0, md_len * 2 + 1);
    EVP_DigestFinal_ex(md_ctx, (unsigned char*)hash, NULL);

    // Convert the hash value to a printable string
    for (i = 0; i < md_len; i++) {
        sprintf(&hash[i * 2], "%02x", (unsigned int)(unsigned char)hash[i]);
    }

    // Clean up the message digest context
    EVP_MD_CTX_free(md_ctx);

    return hash;
}

int main()
{
    char* data = "This is a message to be hashed using SHA-256.";
    char* hash_value = sha256_hash((const unsigned char*)data, strlen(data));
    printf("Data:\n%s\n\nSHA-256 hash value:\n%s\n", data, hash_value);
    free(hash_value);
    return 0;
}