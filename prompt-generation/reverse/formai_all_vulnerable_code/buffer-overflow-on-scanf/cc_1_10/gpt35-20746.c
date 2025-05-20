//FormAI DATASET v1.0 Category: File Encyptor ; Style: satisfied
#include <stdio.h>
#include <string.h>

#define MAX_FILENAME 256
#define KEY 3

void encryptFile(char *filename) {
    char buffer[1024];
    char newFilename[MAX_FILENAME];
    int bytesRead, i;
    FILE *fp, *nf;

    // Create new filename with ".enc" extension
    strcpy(newFilename, filename);
    strcat(newFilename, ".enc");

    // Open file to encrypt
    fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("Error opening input file.");
        return;
    }

    // Open new file for writing encrypted data
    nf = fopen(newFilename, "wb");

    if (nf == NULL) {
        printf("Error creating output file.");
        fclose(fp);
        return;
    }

    // Read and encrypt data from input file and write to new file
    while ((bytesRead = fread(buffer, sizeof(char), sizeof(buffer), fp)) > 0) {
        for (i = 0; i < bytesRead; i++) {
            buffer[i] = buffer[i] + KEY; // Encrypt data by adding key
        }
        fwrite(buffer, sizeof(char), bytesRead, nf);
    }

    // Close files
    fclose(fp);
    fclose(nf);

    printf("Encryption successful. Encrypted file: %s\n", newFilename);
}

int main() {
    char filename[MAX_FILENAME];

    printf("Enter filename to encrypt: ");
    scanf("%s", filename);

    encryptFile(filename);

    return 0;
}