//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function to check if a string is a virus
int isVirus(char* str) {
    char* virusNames[] = {"WannaCry", "Petya", "Locky", "NotPetya", "BadRabbit", "Emotet", "TrickBot", "Ryuk", "GandCrab", "Dridex"};
    int numViruses = sizeof(virusNames)/sizeof(char*);

    for (int i = 0; i < numViruses; i++) {
        if (strcmp(str, virusNames[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

// Function to scan a file for viruses
void scanFile(char* fileName) {
    FILE* file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Error: File not found.\n");
        return;
    }

    char line[1024];
    int lineNum = 1;

    while (fgets(line, sizeof(line), file)!= NULL) {
        int len = strlen(line);

        // Remove newline character
        line[len-1] = '\0';

        // Check if line contains a virus
        if (isVirus(line)) {
            printf("Virus found on line %d:\n%s\n", lineNum, line);
        }

        lineNum++;
    }

    fclose(file);
}

int main() {
    char fileName[1024];
    printf("Enter the name of the file to scan: ");
    scanf("%s", fileName);

    scanFile(fileName);

    return 0;
}