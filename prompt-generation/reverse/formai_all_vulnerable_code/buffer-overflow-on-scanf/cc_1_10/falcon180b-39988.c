//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define HASH_SIZE 64

// Function to convert hexadecimal string to binary string
void hexToBin(char* hex, char* bin) {
    int len = strlen(hex);
    for(int i = 0; i < len; i++) {
        char c = hex[i];
        if(c >= '0' && c <= '9') {
            bin[i] = c;
        } else if(c >= 'A' && c <= 'F') {
            bin[i] = c - 'A' + 10;
        } else if(c >= 'a' && c <= 'f') {
            bin[i] = c - 'a' + 10;
        } else {
            bin[i] = 0;
        }
    }
    bin[len] = 0;
}

// Function to calculate SHA-256 hash of a string
void hash(char* input, char* output) {
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, input, strlen(input));
    SHA256_Final(output, &ctx);
}

// Function to convert binary string to hexadecimal string
void binToHex(char* bin, char* hex) {
    int len = strlen(bin);
    for(int i = 0; i < len; i++) {
        char c = bin[i];
        if(c >= 0 && c <= 9) {
            hex[i] = c + '0';
        } else if(c >= 10 && c <= 15) {
            hex[i] = c - 10 + 'A';
        } else {
            hex[i] = 0;
        }
    }
    hex[len] = 0;
}

int main() {
    char input[1000];
    printf("Enter input string: ");
    scanf("%s", input);
    char output[HASH_SIZE];
    hash(input, output);
    printf("SHA-256 hash of input string: ");
    for(int i = 0; i < HASH_SIZE; i++) {
        printf("%02x", output[i]);
    }
    printf("\n");
    char binary[HASH_SIZE*2];
    hexToBin(output, binary);
    printf("Binary representation of hash: ");
    for(int i = 0; i < HASH_SIZE*2; i++) {
        printf("%c", binary[i]);
    }
    printf("\n");
    char hex[HASH_SIZE*2+1];
    binToHex(binary, hex);
    printf("Hexadecimal representation of hash: ");
    for(int i = 0; i < HASH_SIZE*2; i++) {
        printf("%c", hex[i]);
    }
    printf("\n");
    return 0;
}