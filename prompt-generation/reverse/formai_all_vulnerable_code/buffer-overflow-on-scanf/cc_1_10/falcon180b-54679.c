//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100
#define MAX_VIRUS_NAME 50
#define MAX_VIRUS_SIZE 100

typedef struct {
    char virusName[MAX_VIRUS_NAME];
    char virusSignature[MAX_VIRUS_SIZE];
} Virus;

Virus viruses[] = {
    {"MyDoom", "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"},
    {"I Love You", "ILoveYou"},
    {"Code Red", "Hacked By Chinese!"},
    {"Slammer", "Slammer"},
    {"Melissa", "Melissa"},
    {"Sasser", "Sasser"},
    {"Blaster", "Blaster"},
    {"Nimda", "Nimda"},
    {"Conficker", "Conficker"},
    {"Stuxnet", "Stuxnet"}
};

int numViruses = sizeof(viruses)/sizeof(Virus);

void scanFile(char *fileName) {
    FILE *fp;
    char buffer[MAX_FILE_NAME];
    int numBytesRead;
    Virus *virus;

    if ((fp = fopen(fileName, "rb")) == NULL) {
        printf("Error: Could not open file '%s'.\n", fileName);
        return;
    }

    numBytesRead = fread(buffer, 1, MAX_FILE_NAME, fp);
    if (numBytesRead <= 0) {
        printf("Error: Could not read file '%s'.\n", fileName);
        fclose(fp);
        return;
    }

    buffer[numBytesRead] = '\0';

    for (virus = viruses; virus < viruses + numViruses; virus++) {
        if (strstr(buffer, virus->virusSignature)!= NULL) {
            printf("Virus detected: %s\n", virus->virusName);
            fclose(fp);
            return;
        }
    }

    printf("File '%s' is clean.\n", fileName);
    fclose(fp);
}

int main() {
    char fileName[MAX_FILE_NAME];

    printf("Enter the name of the file to scan: ");
    scanf("%s", fileName);

    scanFile(fileName);

    return 0;
}