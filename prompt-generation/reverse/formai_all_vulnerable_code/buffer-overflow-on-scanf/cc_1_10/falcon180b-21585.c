//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Define the encryption key
#define KEY "MySecretKey"

// Function to encrypt the file content
void encryptFile(FILE *inputFile, FILE *outputFile) {
    char ch;
    int i = 0;

    // Read the input file character by character
    while ((ch = fgetc(inputFile))!= EOF) {
        // Convert the character to uppercase
        ch = toupper(ch);

        // Encrypt the character using the key
        ch = ch + (KEY[i] - 'A');

        // Increment the key index
        i++;

        // If the key index reaches the end of the key, reset it to 0
        if (i == strlen(KEY)) {
            i = 0;
        }

        // Write the encrypted character to the output file
        fputc(ch, outputFile);
    }
}

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[100], outputFileName[100];

    // Get the input and output file names from the user
    printf("Enter the input file name: ");
    scanf("%s", inputFileName);

    strcat(inputFileName, ".enc");

    printf("Enter the output file name: ");
    scanf("%s", outputFileName);

    // Open the input file for reading
    inputFile = fopen(inputFileName, "r");

    // Check if the input file is opened successfully
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Open the output file for writing
    outputFile = fopen(outputFileName, "w");

    // Check if the output file is opened successfully
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Encrypt the content of the input file and write it to the output file
    encryptFile(inputFile, outputFile);

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);

    printf("File encrypted successfully.\n");

    return 0;
}