//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VIRUS_LENGTH 1024
#define MAX_FILE_NAME_LENGTH 1024
#define MAX_LINE_LENGTH 1024

typedef struct {
    char *name;
    char *signature;
} Virus;

int loadViruses(Virus *viruses, int count) {
    FILE *fp = fopen("viruses.txt", "r");
    if (fp == NULL) {
        printf("Error loading viruses.\n");
        return 1;
    }

    int i = 0;
    while (fgets(viruses[i].name, MAX_VIRUS_LENGTH, fp)!= NULL && i < count) {
        viruses[i].signature = strdup(viruses[i].name);
        for (int j = 0; j < strlen(viruses[i].signature); j++) {
            viruses[i].signature[j] = tolower(viruses[i].signature[j]);
        }
        i++;
    }

    fclose(fp);
    return 0;
}

int scanFile(char *filename, Virus *viruses, int count) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s.\n", filename);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (strstr(line, viruses[i].signature)!= NULL) {
                printf("Virus found in file %s: %s\n", filename, viruses[i].name);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("File %s is clean.\n", filename);
        }
    }

    fclose(fp);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <file> <viruses.txt>\n", argv[0]);
        return 1;
    }

    Virus viruses[MAX_VIRUS_LENGTH];
    int count = 0;

    if (loadViruses(viruses, MAX_VIRUS_LENGTH)!= 0) {
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "viruses.txt") == 0) {
            continue;
        }

        scanFile(argv[i], viruses, count);
    }

    return 0;
}