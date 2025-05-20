//FormAI DATASET v1.0 Category: File Encyptor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* plaintext, char* key, char* ciphertext) {
    int textLen = strlen(plaintext);
    int keyLen = strlen(key);
    int i, j, k;
    for (i = 0; i < textLen; ++i) {
        j = i % keyLen;
        k = (plaintext[i] + key[j]) % 128;
        ciphertext[i] = k;
    }
}

int main(int argc, char *argv[]) {
    // Check for proper command line arguments
    if (argc != 3) {
        printf("Usage: encryptor infile outfile\n");
        exit(1);
    }

    // Open input and output files
    FILE *in, *out;
    in = fopen(argv[1], "r");
    out = fopen(argv[2], "w");

    if (!in || !out) {
        printf("Error opening files.\n");
        exit(1);
    }

    // Get the length of the input file
    fseek(in, 0, SEEK_END);
    int fileLength = ftell(in);
    fseek(in, 0, SEEK_SET);

    // Allocate memory for input and output file contents
    char* plaintext = (char*) calloc(fileLength+1, sizeof(char));
    char* ciphertext = (char*) calloc(fileLength+1, sizeof(char));

    // Read the plaintext from the input file
    fread(plaintext, 1, fileLength, in);
    fclose(in);

    // Generate random key
    int i;
    char* key = (char*) calloc(15, sizeof(char));
    srand(time(NULL));
    for (i = 0; i < 15; ++i) {
        key[i] = (rand() % 128) + 1; 
    }

    // Encrypt the plaintext with the key
    encrypt(plaintext, key, ciphertext);

    // Write the encrypted text to the output file
    fwrite(ciphertext, 1, fileLength, out);
    fclose(out);

    // Free dynamically allocated memory
    free(plaintext);
    free(ciphertext);
    free(key);

    return 0;
}