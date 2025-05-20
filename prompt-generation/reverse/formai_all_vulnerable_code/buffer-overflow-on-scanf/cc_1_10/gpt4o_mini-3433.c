//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 1024

void welcomeMessage() {
    printf("Welcome to the Enigmatic File Encryptor!\n");
    printf("Prepare to embark on a whimsical journey of file transformation.\n");
}

void generateKey(char *key, int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 256; // Generate random byte for the key
    }
}

void encryptDecrypt(FILE *input, FILE *output, char *key, long fileSize) {
    unsigned char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, input)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= key[i % fileSize]; // XOR operation for encryption/decryption
        }
        fwrite(buffer, 1, bytesRead, output);
    }
}

void doTheDance(FILE *input, FILE *output, int encryptMode) {
    long fileSize = ftell(input);
    fseek(input, 0, SEEK_SET); // Reset the pointer to the start of the file

    char *key = malloc(fileSize);
    if (key == NULL) {
        fprintf(stderr, "Oh dear! We seem to have run out of memory.\n");
        return;
    }

    generateKey(key, fileSize);
    encryptDecrypt(input, output, key, fileSize);
    free(key);
}

void promptForFile(char *filename, const char *action) {
    printf("Please enter the name of the file to %s: ", action);
    scanf("%s", filename);
}

int main() {
    welcomeMessage();

    char inputFile[256], outputFile[256];
    int encryptMode = 0;

    printf("Would you like to encrypt (1) or decrypt (0) a file? ");
    scanf("%d", &encryptMode);

    if (encryptMode != 0 && encryptMode != 1) {
        fprintf(stderr, "Oops! That's not a valid choice. Please enter either 0 or 1.\n");
        return 1;
    }

    const char *action = (encryptMode == 1) ? "encrypt" : "decrypt";
    promptForFile(inputFile, action);

    FILE *input = fopen(inputFile, "rb");
    if (input == NULL) {
        fprintf(stderr, "Alas! Could not open the input file.\n");
        return 1;
    }

    strcpy(outputFile, inputFile);
    strcat(outputFile, (encryptMode == 1) ? ".enc" : ".dec");
    
    FILE *output = fopen(outputFile, "wb");
    if (output == NULL) {
        fprintf(stderr, "Oh no! Could not create the output file.\n");
        fclose(input);
        return 1;
    }

    printf("The enigma unfolds, we’re now %sing your file...\n", action);
    doTheDance(input, output, encryptMode);

    printf("Success! Your file is now %sed to %s.\n", action, outputFile);
    
    fclose(input);
    fclose(output);

    return 0;
}