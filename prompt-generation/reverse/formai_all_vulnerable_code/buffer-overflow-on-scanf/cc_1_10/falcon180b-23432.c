//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_FILE_SIZE 1000000
#define MAX_VIRUS_NAME_LENGTH 100
#define MAX_VIRUS_SIGNATURES 100
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char virusName[MAX_VIRUS_NAME_LENGTH];
    char virusSignature[MAX_VIRUS_SIGNATURES];
} Virus;

Virus viruses[MAX_VIRUS_SIGNATURES];
int numViruses = 0;

void addVirus(char* virusName, char* virusSignature) {
    strcpy(viruses[numViruses].virusName, virusName);
    strcpy(viruses[numViruses].virusSignature, virusSignature);
    numViruses++;
}

void scanFile(char* fileName) {
    FILE* file;
    char buffer[MAX_FILE_SIZE];
    int bufferSize = 0;
    int i;

    file = fopen(fileName, "rb");

    if (file == NULL) {
        printf("Error: file not found.\n");
        return;
    }

    while (fread(buffer + bufferSize, 1, 1, file) == 1) {
        bufferSize++;

        if (bufferSize == MAX_FILE_SIZE) {
            printf("Error: file too large.\n");
            fclose(file);
            return;
        }
    }

    fclose(file);

    for (i = 0; i < numViruses; i++) {
        if (strstr(buffer, viruses[i].virusSignature)) {
            printf("Virus found: %s\n", viruses[i].virusName);
            return;
        }
    }

    printf("No viruses found.\n");
}

int main() {
    char fileName[MAX_FILE_NAME_LENGTH];

    printf("Enter file name: ");
    scanf("%s", fileName);

    scanFile(fileName);

    return 0;
}