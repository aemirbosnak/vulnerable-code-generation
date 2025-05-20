//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *input, char *output, int key) {
    FILE *inFile = fopen(input, "r");
    if (inFile == NULL) {
        fprintf(stderr, "Could not open input file %s for reading.\n", input);
        exit(1);
    }
    
    FILE *outFile = fopen(output, "w");
    if (outFile == NULL) {
        fprintf(stderr, "Could not open output file %s for writing.\n", output);
        fclose(inFile);
        exit(1);
    }

    char ch;
    while ((ch = fgetc(inFile)) != EOF) {
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + key) % 26 + 'A'; // Encrypt uppercase letters
        } else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + key) % 26 + 'a'; // Encrypt lowercase letters
        }
        fputc(ch, outFile);
    }

    fclose(inFile);
    fclose(outFile);
    printf("Encryption complete! Encrypted file created: %s\n", output);
}

int main() {
    char inputFile[100], outputFile[100];
    int shift;

    printf("Welcome to the Curious File Encryptor!\n");
    printf("Please enter the input file name: ");
    scanf("%s", inputFile);

    printf("What do you want to name the encrypted output file? ");
    scanf("%s", outputFile);

    printf("Enter an integer for the shift value (key): ");
    scanf("%d", &shift);

    // Handle negative shifts
    if (shift < 0) {
        printf("Negative shifts are flipped to positive. Adjusting the key...\n");
        shift = (26 + (shift % 26)) % 26;
    } else {
        shift = shift % 26; // Ensure the shift is within 0-25
    }

    printf("Encrypting your file with a shift of %d...\n", shift);
    encrypt(inputFile, outputFile, shift);

    return 0;
}