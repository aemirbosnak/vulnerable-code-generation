//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME 100
#define MAX_FILE_SIZE 1000000

// Function to encrypt the file
void encryptFile(FILE *inputFile, FILE *outputFile) {
    char ch;
    int key = 5; // Encryption key
    while ((ch = fgetc(inputFile))!= EOF) {
        if (isalpha(ch)) {
            ch = toupper(ch);
            if (ch >= 'A' && ch <= 'Z') {
                ch = (ch - 'A' + key) % 26 + 'A';
            } else {
                ch = (ch - 'a' + key) % 26 + 'a';
            }
        } else {
            ch = ch + key;
        }
        fputc(ch, outputFile);
    }
    fclose(inputFile);
    fclose(outputFile);
}

int main() {
    char inputFileName[MAX_FILE_NAME], outputFileName[MAX_FILE_NAME];
    FILE *inputFile, *outputFile;

    // Get input and output file names
    printf("Enter input file name: ");
    scanf("%s", inputFileName);
    printf("Enter output file name: ");
    scanf("%s", outputFileName);

    // Open input file
    inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Open output file
    outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    // Encrypt the file
    encryptFile(inputFile, outputFile);

    printf("File encrypted successfully.\n");

    return 0;
}