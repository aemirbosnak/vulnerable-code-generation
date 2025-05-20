//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define SHIFT 3
#define MAX_LENGTH 1024

// Function prototypes
void encryptFile(const char *inputFile, const char *outputFile);
void decryptFile(const char *inputFile, const char *outputFile);
void shiftCharacter(char *c, int shift);
void printBrainWarning();

int main() {
    printf("🎩 Welcome to the Great C File Encryptor! 🎩\n\n");
    printf("This program will encrypt your files faster than a squirrel on espresso!\n\n");
    
    char inputFile[MAX_LENGTH];
    char outputFile[MAX_LENGTH];
    
    printf("Enter the name of the file you want to encrypt: ");
    scanf("%s", inputFile);
    
    snprintf(outputFile, sizeof(outputFile), "%s.encrypted", inputFile);
    
    encryptFile(inputFile, outputFile);
    
    printf("🥳 Your file %s has been encrypted and saved as %s! 🥳\n", inputFile, outputFile);
    
    // Adding a decrypt option to keep it spooky
    char decryptOption;
    printf("Do you want to decrypt it? (y/n): ");
    scanf(" %c", &decryptOption);
    
    if (decryptOption == 'y' || decryptOption == 'Y') {
        char decryptedFile[MAX_LENGTH];
        snprintf(decryptedFile, sizeof(decryptedFile), "%s.decrypted", inputFile);
        
        decryptFile(outputFile, decryptedFile);
        
        printf("🎉 Your file has been decrypted and saved as %s! 🎉\n", decryptedFile);
    } else {
        printf("No problem! Your secrets are safe with us! 🤫\n");
    }

    printBrainWarning(); // Just for fun!
    return 0;
}

void encryptFile(const char *inputFile, const char *outputFile) {
    FILE *inFile = fopen(inputFile, "r");
    if (inFile == NULL) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }

    FILE *outFile = fopen(outputFile, "w");
    if (outFile == NULL) {
        perror("Failed to open output file");
        fclose(inFile);
        exit(EXIT_FAILURE);
    }

    char ch;
    while ((ch = fgetc(inFile)) != EOF) {
        shiftCharacter(&ch, SHIFT);
        fputc(ch, outFile);
    }

    fclose(inFile);
    fclose(outFile);
}

void decryptFile(const char *inputFile, const char *outputFile) {
    FILE *inFile = fopen(inputFile, "r");
    if (inFile == NULL) {
        perror("Failed to open input file for decryption");
        exit(EXIT_FAILURE);
    }

    FILE *outFile = fopen(outputFile, "w");
    if (outFile == NULL) {
        perror("Failed to open output file for decryption");
        fclose(inFile);
        exit(EXIT_FAILURE);
    }

    char ch;
    while ((ch = fgetc(inFile)) != EOF) {
        shiftCharacter(&ch, -SHIFT);
        fputc(ch, outFile);
    }

    fclose(inFile);
    fclose(outFile);
}

void shiftCharacter(char *c, int shift) {
    if (*c >= 'a' && *c <= 'z') {
        *c = ((*c - 'a' + shift) % 26 + 26) % 26 + 'a'; // Wrap around for lowercase
    } else if (*c >= 'A' && *c <= 'Z') {
        *c = ((*c - 'A' + shift) % 26 + 26) % 26 + 'A'; // Wrap around for uppercase
    } 
    // Punctuation and numbers are unchanged, to keep your files dignified!
}

void printBrainWarning() {
    printf("🧠 WARNING: This program consumes a LOT of brainpower. 🤯\n");
    printf("Using it may result in spontaneous knowledge accumulation!\n");
    printf("Enjoy responsibly and do not operate heavy machinery while coding!\n");
}