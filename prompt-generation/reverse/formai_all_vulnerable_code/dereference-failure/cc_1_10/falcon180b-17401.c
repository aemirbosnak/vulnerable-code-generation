//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_VIRUS_DEFINITIONS 100
#define MAX_VIRUS_NAME_LENGTH 64
#define MAX_VIRUS_SIGNATURE_LENGTH 256

typedef struct {
    char fileName[MAX_FILE_NAME_LENGTH];
    char virusName[MAX_VIRUS_NAME_LENGTH];
    char virusSignature[MAX_VIRUS_SIGNATURE_LENGTH];
} VirusDefinition;

int main() {
    FILE *virusDefinitionsFile;
    char line[1024];
    int numVirusDefinitions = 0;
    VirusDefinition *virusDefinitions = malloc(MAX_VIRUS_DEFINITIONS * sizeof(VirusDefinition));

    virusDefinitionsFile = fopen("virus_definitions.txt", "r");

    if (virusDefinitionsFile == NULL) {
        printf("Error opening virus definitions file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), virusDefinitionsFile)!= NULL) {
        if (numVirusDefinitions >= MAX_VIRUS_DEFINITIONS) {
            printf("Maximum number of virus definitions reached.\n");
            break;
        }

        char *token = strtok(line, ",");
        strcpy(virusDefinitions[numVirusDefinitions].fileName, token);

        token = strtok(NULL, ",");
        strcpy(virusDefinitions[numVirusDefinitions].virusName, token);

        token = strtok(NULL, ",");
        strcpy(virusDefinitions[numVirusDefinitions].virusSignature, token);

        numVirusDefinitions++;
    }

    fclose(virusDefinitionsFile);

    char fileName[MAX_FILE_NAME_LENGTH];
    printf("Enter file name to scan: ");
    scanf("%s", fileName);

    FILE *file = fopen(fileName, "rb");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int fileSize = 0;
    char buffer[1024];

    while (fread(buffer, 1, sizeof(buffer), file) > 0) {
        fileSize += sizeof(buffer);
    }

    rewind(file);

    int i;
    for (i = 0; i < numVirusDefinitions; i++) {
        int j;
        for (j = 0; j < fileSize - strlen(virusDefinitions[i].virusSignature); j++) {
            if (memcmp(buffer + j, virusDefinitions[i].virusSignature, strlen(virusDefinitions[i].virusSignature)) == 0) {
                printf("Virus found: %s\n", virusDefinitions[i].virusName);
                exit(1);
            }
        }
    }

    printf("No viruses found.\n");
    exit(0);
}