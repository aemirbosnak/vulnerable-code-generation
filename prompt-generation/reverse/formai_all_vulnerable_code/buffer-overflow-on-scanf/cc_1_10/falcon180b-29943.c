//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the file
void encryptFile(FILE *inputFile, FILE *outputFile, int key) {
    char ch;
    ch = fgetc(inputFile);
    while (ch!= EOF) {
        if (ch >= 'a' && ch <= 'z') {
            ch = ch + key;
            if (ch > 'z') {
                ch = ch - 26;
            }
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + key;
            if (ch > 'Z') {
                ch = ch - 26;
            }
        }
        fputc(ch, outputFile);
        ch = fgetc(inputFile);
    }
}

// Function to decrypt the file
void decryptFile(FILE *inputFile, FILE *outputFile, int key) {
    char ch;
    ch = fgetc(inputFile);
    while (ch!= EOF) {
        if (ch >= 'a' && ch <= 'z') {
            ch = ch - key;
            if (ch < 'a') {
                ch = ch + 26;
            }
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ch - key;
            if (ch < 'A') {
                ch = ch + 26;
            }
        }
        fputc(ch, outputFile);
        ch = fgetc(inputFile);
    }
}

int main() {
    char fileName[100], outputFileName[100];
    int key;
    
    // Get the file name from user
    printf("Enter the file name: ");
    scanf("%s", fileName);
    
    // Get the key from user
    printf("Enter the key: ");
    scanf("%d", &key);
    
    // Open the input file
    FILE *inputFile = fopen(fileName, "r");
    if (inputFile == NULL) {
        printf("Error: Input file not found.\n");
        exit(1);
    }
    
    // Open the output file
    char *outputFileMode = "wb";
    FILE *outputFile = fopen(fileName, outputFileMode);
    if (outputFile == NULL) {
        printf("Error: Output file not created.\n");
        exit(1);
    }
    
    // Encrypt the file
    encryptFile(inputFile, outputFile, key);
    printf("File encrypted successfully.\n");
    
    // Close the files
    fclose(inputFile);
    fclose(outputFile);
    
    return 0;
}