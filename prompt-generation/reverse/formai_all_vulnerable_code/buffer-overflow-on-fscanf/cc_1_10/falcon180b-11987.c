//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_VIRUS_NAME_LENGTH 50
#define MAX_VIRUS_SIGNATURE_LENGTH 100

typedef struct {
    char fileName[MAX_FILE_NAME_LENGTH];
    char virusName[MAX_VIRUS_NAME_LENGTH];
    char virusSignature[MAX_VIRUS_SIGNATURE_LENGTH];
} Virus;

int loadViruses(Virus *viruses, int maxViruses) {
    FILE *file = fopen("viruses.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open viruses.txt file.\n");
        return -1;
    }

    int numViruses = 0;
    while (fscanf(file, "%s\t%s\t%s\n", viruses[numViruses].fileName, viruses[numViruses].virusName, viruses[numViruses].virusSignature) == 3 && numViruses < maxViruses) {
        numViruses++;
    }

    fclose(file);
    return numViruses;
}

int scanFile(char *fileName, Virus *viruses, int numViruses) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error: Could not open %s.\n", fileName);
        return -1;
    }

    char buffer[1024];
    int numBytesRead;
    while ((numBytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; i < numViruses; i++) {
            int index = 0;
            while ((index = memmem(buffer + index, numBytesRead - index, viruses[i].virusSignature, strlen(viruses[i].virusSignature)))!= NULL) {
                printf("Virus found in %s: %s\n", fileName, viruses[i].virusName);
                return 1;
            }
        }
    }

    fclose(file);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return -1;
    }

    Virus viruses[100];
    int numViruses = loadViruses(viruses, sizeof(viruses) / sizeof(viruses[0]));
    if (numViruses <= 0) {
        return -1;
    }

    int result = scanFile(argv[1], viruses, numViruses);
    if (result == 0) {
        printf("No virus found in %s.\n", argv[1]);
    }

    return 0;
}