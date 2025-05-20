//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE (1024*1024*10) // 10MB
#define MAX_VIRUS_LENGTH 1024
#define NUM_VIRUSES 3

typedef struct {
    char name[MAX_VIRUS_LENGTH];
    char signature[MAX_VIRUS_LENGTH];
} Virus;

Virus viruses[NUM_VIRUSES] = {
    {"MyDoom", "mydoom"},
    {"I Love You", "love"},
    {"Melissa", "melissa"}
};

int scanFile(FILE *file, Virus *viruses, int numViruses) {
    char buffer[MAX_FILE_SIZE];
    int bufferSize = fread(buffer, 1, MAX_FILE_SIZE, file);

    if (bufferSize <= 0) {
        printf("Error reading file\n");
        return -1;
    }

    for (int i = 0; i < numViruses; i++) {
        int virusSize = strlen(viruses[i].signature);
        int j;

        for (j = 0; j < bufferSize - virusSize; j++) {
            if (strncmp(buffer + j, viruses[i].signature, virusSize) == 0) {
                printf("Virus found: %s\n", viruses[i].name);
                return i + 1; // return virus index + 1
            }
        }
    }

    return 0; // no virus found
}

int main() {
    char filename[100];
    printf("Enter a filename to scan: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("File not found\n");
        return 1;
    }

    int virusIndex = scanFile(file, viruses, NUM_VIRUSES);

    if (virusIndex > 0) {
        printf("File contains %s virus\n", viruses[virusIndex - 1].name);
    } else {
        printf("File is clean\n");
    }

    fclose(file);
    return 0;
}