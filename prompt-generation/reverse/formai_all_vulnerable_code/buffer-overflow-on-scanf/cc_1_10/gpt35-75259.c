//FormAI DATASET v1.0 Category: File Encyptor ; Style: high level of detail
#include <stdio.h>
#include <string.h>

int main() {
    char inFileName[100], outFileName[100], key[100];
    int choice, i;
    FILE *inFile, *outFile;

    printf("Enter the name of the input file: ");
    scanf("%s", inFileName);

    printf("Enter the name of the output file: ");
    scanf("%s", outFileName);

    printf("Enter the encryption/decryption key: ");
    scanf("%s", key);

    printf("Enter your choice:\n 1. Encrypt\n 2. Decrypt\n");
    scanf("%d", &choice);

    inFile = fopen(inFileName, "rb");
    outFile = fopen(outFileName, "wb");

    if (inFile == NULL || outFile == NULL) {
        printf("Error: Could not open file.");
        return 1;
    }

    fseek(inFile, 0, SEEK_END);
    int fileSize = ftell(inFile);
    fseek(inFile, 0, SEEK_SET);

    if (choice == 1) {
        // Encrypt the file
        char buffer[fileSize];
        fread(buffer, fileSize, 1, inFile);

        int keyLength = strlen(key);

        for (i = 0; i < fileSize; ++i) {
            buffer[i] = ((buffer[i] + key[i % keyLength]) % 256);
        }

        fwrite(buffer, fileSize, 1, outFile);
        printf("File has been encrypted successfully.");
    } else if (choice == 2) {
        // Decrypt the file
        char buffer[fileSize];
        fread(buffer, fileSize, 1, inFile);

        int keyLength = strlen(key);

        for (i = 0; i < fileSize; ++i) {
            buffer[i] = ((buffer[i] - key[i % keyLength] + 256) % 256);
        }

        fwrite(buffer, fileSize, 1, outFile);
        printf("File has been decrypted successfully.");
    } else {
        printf("Error: Invalid choice.");
        return 1;
    }

    fclose(inFile);
    fclose(outFile);

    return 0;
}