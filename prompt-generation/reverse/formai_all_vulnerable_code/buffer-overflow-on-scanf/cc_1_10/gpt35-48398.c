//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: accurate
#include <stdio.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_VIRUS_SIGNATURES 50
#define MAX_SIGNATURE_LENGTH 50

struct VirusSignature {
    char signature[MAX_SIGNATURE_LENGTH];
} virusSignatures[MAX_VIRUS_SIGNATURES];

int signaturesCount = 0;

void loadVirusSignatures(char filename[]) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Could not open file: %s\n", filename);
        return;
    }
    char signature[MAX_SIGNATURE_LENGTH];

    while (fgets(signature, MAX_SIGNATURE_LENGTH, fp) != NULL) {
        strcpy(virusSignatures[signaturesCount].signature, signature);
        signaturesCount++;
    }

    fclose(fp);
}

int isFileInfected(char filename[]) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Could not open file: %s\n", filename);
        return 0;
    }
    char fileContents[MAX_SIGNATURE_LENGTH];
    fgets(fileContents, MAX_SIGNATURE_LENGTH, fp);
    fclose(fp);

    for (int i = 0; i < signaturesCount; i++) {
        if (strstr(fileContents, virusSignatures[i].signature) != NULL) {
            return 1;
        }
    }

    return 0;
}

int main() {
    char virusSignaturesFile[MAX_FILENAME_LENGTH];
    char fileToScan[MAX_FILENAME_LENGTH];

    printf("Enter the file name containing virus signatures: ");
    scanf("%s", virusSignaturesFile);
    loadVirusSignatures(virusSignaturesFile);

    printf("Enter the file name to scan: ");
    scanf("%s", fileToScan);

    if (isFileInfected(fileToScan)) {
        printf("%s is infected with virus.\n", fileToScan);
    } else {
        printf("%s is not infected with any known virus.\n", fileToScan);
    }

    return 0;
}