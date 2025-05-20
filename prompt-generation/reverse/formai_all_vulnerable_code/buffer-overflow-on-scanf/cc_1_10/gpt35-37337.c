//FormAI DATASET v1.0 Category: File Encyptor ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

int main() {
    char password[10];
    printf("Enter the encryption key: ");
    scanf("%s", password);

    if (strcmp(password, "cyberpunk2077") != 0) {
        printf("Sorry, invalid encryption key!\n");
        return 1;
    }

    FILE *inputFilePtr;
    FILE *outputFilePtr;

    char inputFileName[100];
    printf("Enter the name of the file to be encrypted: ");
    scanf("%s", inputFileName);

    char outputFileName[100];
    printf("Enter the name of the output file: ");
    scanf("%s", outputFileName);

    inputFilePtr = fopen(inputFileName, "rb");
    if (inputFilePtr == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    outputFilePtr = fopen(outputFileName, "wb");
    if (outputFilePtr == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    char buffer[100];
    int bytesRead;

    while ((bytesRead = fread(buffer, sizeof(char), 100, inputFilePtr)) > 0) {
        for (int i = 0; i < bytesRead; i++) {
            buffer[i] ^= 0b10101010; // XOR every byte with 0b10101010
        }
        fwrite(buffer, sizeof(char), bytesRead, outputFilePtr);
    }

    printf("File encryption successful.\n");

    fclose(inputFilePtr);
    fclose(outputFilePtr);

    return 0;
}