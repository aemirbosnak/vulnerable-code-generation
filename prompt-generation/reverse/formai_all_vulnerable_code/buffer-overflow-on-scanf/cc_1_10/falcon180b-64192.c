//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define HASH_LENGTH 64

// Function to convert hexadecimal to binary
void hex_to_bin(char* hex, char* bin) {
    int i, j = 0;
    for(i = 0; hex[i]!= '\0'; i++) {
        if(hex[i] >= '0' && hex[i] <= '9') {
            bin[j++] = hex[i];
        } else if(hex[i] >= 'A' && hex[i] <= 'F') {
            bin[j++] = hex[i] - 'A' + 10;
        } else if(hex[i] >= 'a' && hex[i] <= 'f') {
            bin[j++] = hex[i] - 'a' + 10;
        } else {
            break;
        }
    }
    bin[j] = '\0';
}

// Function to generate hash from input string
void generate_hash(char* input, char* hash) {
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, input, strlen(input));
    SHA256_Final(hash, &ctx);
}

// Function to convert binary to hexadecimal
void bin_to_hex(char* bin, char* hex) {
    int i, j = 0;
    for(i = 0; i < HASH_LENGTH; i++) {
        sprintf(&hex[j], "%02x", bin[i]);
        j += 2;
    }
    hex[j] = '\0';
}

int main() {
    char input[100];
    char hash[HASH_LENGTH];
    char hex[HASH_LENGTH*2+1];
    printf("Enter input string: ");
    scanf("%s", input);
    generate_hash(input, hash);
    bin_to_hex(hash, hex);
    printf("Hash: %s\n", hex);
    return 0;
}