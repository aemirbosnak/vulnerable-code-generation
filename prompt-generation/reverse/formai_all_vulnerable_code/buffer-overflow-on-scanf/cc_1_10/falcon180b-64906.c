//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_LENGTH 16

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[100], outputFileName[100];
    char key[KEY_LENGTH];
    char inputBuffer[1024];
    char outputBuffer[1024];
    int i, j, n;

    printf("Enter the name of the input file: ");
    scanf("%s", inputFileName);

    printf("Enter the name of the output file: ");
    scanf("%s", outputFileName);

    printf("Enter the encryption key: ");
    for (i = 0; i < KEY_LENGTH; i++) {
        scanf("%c", &key[i]);
    }

    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while ((n = fread(inputBuffer, sizeof(char), sizeof(inputBuffer), inputFile)) > 0) {
        for (i = 0; i < n; i++) {
            if (isalpha(inputBuffer[i])) {
                inputBuffer[i] = toupper(inputBuffer[i]);
                inputBuffer[i] = inputBuffer[i] + key[i % KEY_LENGTH];
            } else if (isdigit(inputBuffer[i])) {
                inputBuffer[i] = inputBuffer[i] + key[i % KEY_LENGTH];
            } else {
                inputBuffer[i] = inputBuffer[i];
            }
        }
        fwrite(inputBuffer, sizeof(char), n, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("File encryption complete.\n");

    return 0;
}