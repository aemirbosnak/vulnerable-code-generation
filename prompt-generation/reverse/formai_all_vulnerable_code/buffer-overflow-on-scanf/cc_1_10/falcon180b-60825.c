//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: authentic
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

void scanFile(char* fileName, Virus viruses[], int numViruses) {
    FILE* file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", fileName);
        return;
    }

    char buffer[1024];
    int fileSize = 0;
    while (fread(buffer, 1, sizeof(buffer), file) > 0) {
        fileSize += sizeof(buffer);

        for (int i = 0; i < numViruses; i++) {
            int index = 0;
            while (index < strlen(viruses[i].signature)) {
                if (buffer[fileSize - index - 1]!= viruses[i].signature[index]) {
                    break;
                }
                index++;
            }

            if (index == strlen(viruses[i].signature)) {
                printf("Virus found: %s\n", viruses[i].name);
                break;
            }
        }
    }

    fclose(file);
}

int main() {
    Virus viruses[MAX_VIRUSES] = {{"WannaCry", "FC"}};
    int numViruses = 1;

    char fileName[MAX_FILE_NAME_LENGTH];
    printf("Enter file name to scan: ");
    scanf("%s", fileName);

    scanFile(fileName, viruses, numViruses);

    return 0;
}