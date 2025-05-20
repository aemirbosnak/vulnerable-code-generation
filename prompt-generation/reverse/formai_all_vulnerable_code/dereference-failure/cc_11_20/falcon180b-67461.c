//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VIRUSES 10
#define MAX_VIRUS_NAME_LEN 100
#define MAX_FILE_NAME_LEN 1000

typedef struct {
    char name[MAX_VIRUS_NAME_LEN];
    char signature[MAX_FILE_NAME_LEN];
    int length;
} Virus;

int main() {
    int numViruses = 0;
    Virus viruses[MAX_VIRUSES];

    // Load virus definitions from file
    FILE *fp = fopen("virus_definitions.txt", "r");
    if (fp == NULL) {
        printf("Error loading virus definitions.\n");
        return 1;
    }

    char line[MAX_FILE_NAME_LEN];
    while (fgets(line, MAX_FILE_NAME_LEN, fp)!= NULL) {
        if (numViruses >= MAX_VIRUSES) {
            printf("Too many viruses defined.\n");
            break;
        }

        char *name = strtok(line, ",");
        char *signature = strtok(NULL, ",");
        int length = strlen(signature);

        strncpy(viruses[numViruses].name, name, MAX_VIRUS_NAME_LEN - 1);
        strncpy(viruses[numViruses].signature, signature, MAX_FILE_NAME_LEN - 1);
        viruses[numViruses].length = length;

        numViruses++;
    }

    fclose(fp);

    // Scan file for viruses
    char fileName[MAX_FILE_NAME_LEN];
    printf("Enter file name to scan: ");
    fgets(fileName, MAX_FILE_NAME_LEN, stdin);

    FILE *file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char buffer[4096];
    int fileSize = 0;
    while (fread(buffer, 1, sizeof(buffer), file) > 0) {
        fileSize += sizeof(buffer);
    }

    rewind(file);

    int matchCount = 0;
    for (int i = 0; i < numViruses; i++) {
        int offset = 0;
        while (offset < fileSize - viruses[i].length) {
            int j;
            for (j = 0; j < viruses[i].length; j++) {
                if (buffer[offset + j]!= viruses[i].signature[j]) {
                    break;
                }
            }

            if (j == viruses[i].length) {
                printf("Virus found: %s\n", viruses[i].name);
                matchCount++;
                break;
            }

            offset++;
        }
    }

    if (matchCount == 0) {
        printf("No viruses found.\n");
    }

    fclose(file);

    return 0;
}