//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/sha.h>

// Function to convert hexadecimal string to binary string
char* hex_to_bin(char* hex) {
    int len = strlen(hex);
    char* bin = malloc(len*2 + 1);
    for(int i=0; i<len; i++) {
        if(hex[i] >= '0' && hex[i] <= '9') {
            bin[i*2] = hex[i];
        }
        else if(hex[i] >= 'A' && hex[i] <= 'F') {
            bin[i*2] = hex[i] - 55;
        }
        else if(hex[i] >= 'a' && hex[i] <= 'f') {
            bin[i*2] = hex[i] - 87;
        }
        else {
            printf("Invalid hexadecimal string\n");
            exit(1);
        }
    }
    bin[len*2] = '\0';
    return bin;
}

// Function to calculate SHA256 hash of a binary string
char* sha256(char* bin) {
    unsigned char digest[SHA256_DIGEST_LENGTH];
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, bin, strlen(bin));
    SHA256_Final(digest, &ctx);
    char* hex = malloc(SHA256_DIGEST_LENGTH*2+1);
    for(int i=0; i<SHA256_DIGEST_LENGTH; i++) {
        sprintf(&hex[i*2], "%02x", digest[i]);
    }
    hex[SHA256_DIGEST_LENGTH*2] = '\0';
    return hex;
}

int main() {
    // User input for the message to be hashed
    char message[1000];
    printf("Enter a message to be hashed: ");
    scanf("%s", message);

    // Convert user input to binary string
    char* bin = hex_to_bin(message);

    // Calculate SHA256 hash of the binary string
    char* hash = sha256(bin);

    // Print the hash
    printf("SHA256 hash of the message: %s\n", hash);
    return 0;
}