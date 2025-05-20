//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_FILE_NAME 1024
#define MAX_VIRUS_NAME 1024

typedef struct {
    char name[MAX_FILE_NAME];
    char virusName[MAX_VIRUS_NAME];
} virus_t;

void loadViruses(virus_t viruses[]) {
    FILE *file = fopen("viruses.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open viruses.txt\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", viruses[count].name, viruses[count].virusName)!= EOF) {
        count++;
    }

    fclose(file);
}

int scanFile(char *filePath, virus_t viruses[], int numViruses) {
    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filePath);
        return -1;
    }

    char line[MAX_FILE_NAME];
    int lineNum = 1;
    while (fgets(line, MAX_FILE_NAME, file)!= NULL) {
        int i;
        for (i = 0; i < numViruses; i++) {
            if (strstr(line, viruses[i].virusName)) {
                printf("Virus found in file %s on line %d: %s\n", filePath, lineNum, viruses[i].name);
                return 1;
            }
        }
        lineNum++;
    }

    fclose(file);
    return 0;
}

int main() {
    virus_t viruses[10];
    loadViruses(viruses);

    char filePath[MAX_FILE_NAME];
    printf("Enter file path: ");
    scanf("%s", filePath);

    int result = scanFile(filePath, viruses, 10);
    if (result == 0) {
        printf("No viruses found in file %s\n", filePath);
    }

    return 0;
}