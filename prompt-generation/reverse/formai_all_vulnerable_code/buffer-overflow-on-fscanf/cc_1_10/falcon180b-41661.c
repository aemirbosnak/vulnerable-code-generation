//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Sherlock Holmes
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

int loadViruses(Virus viruses[MAX_VIRUSES]) {
    FILE *file = fopen("viruses.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open viruses.txt\n");
        return 1;
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", viruses[count].name, viruses[count].signature)!= EOF) {
        count++;
        if (count >= MAX_VIRUSES) {
            printf("Warning: Reached maximum number of viruses\n");
            break;
        }
    }

    fclose(file);
    return 0;
}

int scanFile(char *fileName, Virus viruses[MAX_VIRUSES]) {
    FILE *file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Error: Could not open %s\n", fileName);
        return 1;
    }

    char buffer[1024];
    while (fread(buffer, 1, sizeof(buffer), file) > 0) {
        for (int i = 0; i < MAX_VIRUSES; i++) {
            if (strstr(buffer, viruses[i].signature)!= NULL) {
                printf("Infection found: %s\n", viruses[i].name);
                return 1;
            }
        }
    }

    fclose(file);
    return 0;
}

int main(int argc, char *argv[]) {
    Virus viruses[MAX_VIRUSES];

    if (loadViruses(viruses)!= 0) {
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (scanFile(argv[i], viruses)!= 0) {
            return 1;
        }
    }

    printf("No infections found.\n");
    return 0;
}