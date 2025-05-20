//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_VIRUSES 10
#define VIRUS_NAME_LENGTH 50
#define FILE_NAME_LENGTH 100
#define VIRUS_SIGNATURE_LENGTH 100

typedef struct {
    char virusName[VIRUS_NAME_LENGTH];
    char fileName[FILE_NAME_LENGTH];
    char virusSignature[VIRUS_SIGNATURE_LENGTH];
} Virus;

Virus viruses[MAX_VIRUSES];
int numViruses;

void loadViruses() {
    FILE *file;
    char line[100];
    int i = 0;

    file = fopen("viruses.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open viruses.txt\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)) {
        if (i >= MAX_VIRUSES) {
            printf("Error: Too many viruses defined in viruses.txt\n");
            exit(1);
        }
        sscanf(line, "%s %s %s", viruses[i].virusName, viruses[i].fileName, viruses[i].virusSignature);
        i++;
    }

    numViruses = i;
    fclose(file);
}

void scanFile(char *fileName) {
    FILE *file;
    char line[100];
    int i;

    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error: Unable to open %s\n", fileName);
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        for (i = 0; i < numViruses; i++) {
            if (strstr(line, viruses[i].virusSignature)) {
                printf("Virus found: %s\n", viruses[i].virusName);
                break;
            }
        }
    }

    fclose(file);
}

int main() {
    loadViruses();

    char fileName[FILE_NAME_LENGTH];
    printf("Enter file name to scan: ");
    scanf("%s", fileName);

    scanFile(fileName);

    return 0;
}