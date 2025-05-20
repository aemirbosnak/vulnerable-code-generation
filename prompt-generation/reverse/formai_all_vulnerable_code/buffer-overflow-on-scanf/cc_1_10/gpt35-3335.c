//FormAI DATASET v1.0 Category: File Encyptor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *inputFileName, char *outputFileName) {
    FILE *inFile, *outFile;
    inFile = fopen(inputFileName, "r");
    outFile = fopen(outputFileName, "w");

    if (inFile == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }
    if (outFile == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    char ch;
    while ((ch = fgetc(inFile)) != EOF) {
        ch ^= 6;
        fprintf(outFile, "%c", ch);
    }

    printf("File encrypted successfully\n");

    fclose(inFile);
    fclose(outFile);
}

void decrypt(char *inputFileName, char *outputFileName) {
    FILE *inFile, *outFile;
    inFile = fopen(inputFileName, "r");
    outFile = fopen(outputFileName, "w");

    if (inFile == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }
    if (outFile == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    char ch;
    while ((ch = fgetc(inFile)) != EOF) {
        ch ^= 6;
        fprintf(outFile, "%c", ch);
    }

    printf("File decrypted successfully\n");

    fclose(inFile);
    fclose(outFile);
}

int main() {
    char inputFileName[50], outputFileName[50];
    int choice;

    printf("Choose an option:\n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);

    printf("Enter input file name: ");
    scanf("%s", inputFileName);

    printf("Enter output file name: ");
    scanf("%s", outputFileName);

    switch (choice) {
        case 1:
            encrypt(inputFileName, outputFileName);
            break;
        case 2:
            decrypt(inputFileName, outputFileName);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}