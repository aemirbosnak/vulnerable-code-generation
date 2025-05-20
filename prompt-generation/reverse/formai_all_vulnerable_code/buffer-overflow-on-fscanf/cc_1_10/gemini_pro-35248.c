//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_VIRUS_SIGNATURES 100
#define MAX_FILE_SIZE 100000

typedef struct {
    char *signature;
    int length;
} VirusSignature;

VirusSignature virusSignatures[MAX_VIRUS_SIGNATURES];

int numVirusSignatures = 0;

void loadVirusSignatures(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening virus signature file");
        exit(1);
    }

    while (fscanf(fp, "%s %d", virusSignatures[numVirusSignatures].signature, &virusSignatures[numVirusSignatures].length) != EOF) {
        numVirusSignatures++;
    }

    fclose(fp);
}

int scanFile(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    if (fileSize > MAX_FILE_SIZE) {
        printf("File is too large to scan\n");
        fclose(fp);
        return -1;
    }

    char *fileBuffer = malloc(fileSize);
    if (fileBuffer == NULL) {
        perror("Error allocating memory for file buffer");
        fclose(fp);
        return -1;
    }

    fread(fileBuffer, fileSize, 1, fp);
    fclose(fp);

    for (int i = 0; i < numVirusSignatures; i++) {
        if (strstr(fileBuffer, virusSignatures[i].signature) != NULL) {
            printf("File is infected with virus %s\n", virusSignatures[i].signature);
            free(fileBuffer);
            return 1;
        }
    }

    printf("File is clean\n");
    free(fileBuffer);
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <virus signature file> <file to scan>\n", argv[0]);
        exit(1);
    }

    loadVirusSignatures(argv[1]);
    scanFile(argv[2]);

    return 0;
}