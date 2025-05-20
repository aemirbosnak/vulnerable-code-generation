//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VIRUSES 10
#define MAX_VIRUS_NAME_LENGTH 50
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char name[MAX_VIRUS_NAME_LENGTH];
    char signature[MAX_FILE_NAME_LENGTH];
} Virus;

Virus viruses[MAX_VIRUSES] = {{"WannaCry", "fc663c373e218b0f77d8f219943d4291"},
                             {"Locky", "7f2c2d51c5a6b7e9c5d2f1f2b8dbf6f1"},
                             {"Petya", "71c0b6c4d0d9c9d8c9f0c9c1c0c6c0c"},
                             {"NotPetya", "71c0b6c4d0d9c9d8c9f0c9c1c0c6c0c"},
                             {"BadRabbit", "fc663c373e218b0f77d8f219943d4291"}};

int numViruses() {
    return MAX_VIRUSES;
}

char* getVirusName(int index) {
    return viruses[index].name;
}

char* getVirusSignature(int index) {
    return viruses[index].signature;
}

int isInfected(char* fileName) {
    FILE* file = fopen(fileName, "rb");
    if (file == NULL) {
        return 0;
    }

    char buffer[MAX_FILE_NAME_LENGTH];
    fread(buffer, 1, MAX_FILE_NAME_LENGTH, file);
    fclose(file);

    int i;
    for (i = 0; i < numViruses(); i++) {
        if (strstr(buffer, getVirusSignature(i))!= NULL) {
            return 1;
        }
    }

    return 0;
}

void printVirusInfo(int index) {
    printf("Virus name: %s\n", getVirusName(index));
    printf("Signature: %s\n", getVirusSignature(index));
}

int main() {
    int numInfected = 0;

    printf("Starting virus scan...\n");

    char fileName[MAX_FILE_NAME_LENGTH];
    while (scanf("%s", fileName)!= EOF) {
        if (isInfected(fileName)) {
            numInfected++;
            printf("File %s is infected with the ", fileName);
            printVirusInfo(0); // Only one virus for now
            printf("virus.\n");
        } else {
            printf("File %s is clean.\n", fileName);
        }
    }

    printf("Scan complete. %d files were scanned and %d were found to be infected.\n", MAX_FILE_NAME_LENGTH, numInfected);

    return 0;
}