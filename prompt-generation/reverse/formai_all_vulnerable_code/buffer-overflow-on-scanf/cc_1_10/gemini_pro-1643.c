//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

// Function to calculate the SHA-256 hash of a string
unsigned char* sha256(const unsigned char *str, size_t len) {
    unsigned char *hash = malloc(SHA256_DIGEST_LENGTH);
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str, len);
    SHA256_Final(hash, &sha256);
    return hash;
}

// Function to convert a byte array into a hex string
char* byte_to_hex(const unsigned char *bytes, size_t len) {
    char *hex = malloc(len * 2 + 1);
    for (size_t i = 0; i < len; i++) {
        sprintf(hex + i * 2, "%02x", bytes[i]);
    }
    hex[len * 2] = '\0';
    return hex;
}

// Function to perform a brute-force attack on a SHA-256 hash
void brute_force(const unsigned char *hash) {
    // Iterate over all possible 8-character strings
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < 26; k++) {
                for (int l = 0; l < 26; l++) {
                    for (int m = 0; m < 26; m++) {
                        for (int n = 0; n < 26; n++) {
                            for (int o = 0; o < 26; o++) {
                                for (int p = 0; p < 26; p++) {
                                    // Convert the string to bytes
                                    unsigned char *str = malloc(8);
                                    str[0] = 'a' + i;
                                    str[1] = 'a' + j;
                                    str[2] = 'a' + k;
                                    str[3] = 'a' + l;
                                    str[4] = 'a' + m;
                                    str[5] = 'a' + n;
                                    str[6] = 'a' + o;
                                    str[7] = 'a' + p;

                                    // Calculate the SHA-256 hash of the string
                                    unsigned char *hash_str = sha256(str, 8);

                                    // Check if the hash matches the given hash
                                    if (memcmp(hash_str, hash, SHA256_DIGEST_LENGTH) == 0) {
                                        // Print the string and exit
                                        printf("Found the string: %s\n", str);
                                        free(str);
                                        free(hash_str);
                                        return;
                                    }

                                    // Free the memory allocated for the string and hash
                                    free(str);
                                    free(hash_str);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // If no match is found, print an error message
    printf("No match found\n");
}

int main() {
    // Get the hash from the user
    unsigned char hash[SHA256_DIGEST_LENGTH];
    printf("Enter the hash: ");
    scanf("%s", hash);

    // Convert the hash to a hex string
    char *hex_hash = byte_to_hex(hash, SHA256_DIGEST_LENGTH);
    printf("Hash in hex: %s\n", hex_hash);

    // Perform a brute-force attack on the hash
    brute_force(hash);

    // Free the memory allocated for the hex string
    free(hex_hash);

    return 0;
}