//MISTRAL-7B DATASET v1.0 Category: Antivirus scanner ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_DEFINITIONS 100
#define MAX_DEF_LEN 100
#define MAX_FILE_NAME 100
#define BUFFER_SIZE 1024

typedef struct VirusDefinition {
    char name[MAX_DEF_LEN];
    char signature[MAX_DEF_LEN];
} VirusDefinition;

typedef struct FileInfo {
    char fileName[MAX_FILE_NAME];
    char *fileData;
    size_t fileSize;
} FileInfo;

void readVirusDefinitions(VirusDefinition defs[], int *numDefs) {
    FILE *fp;
    char line[MAX_DEF_LEN];

    fp = fopen("virusDefinitions.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open virus definitions file.\n");
        exit(1);
    }

    *numDefs = 0;

    while (fgets(line, MAX_DEF_LEN, fp)) {
        sscanf(line, "%s %s", defs[*numDefs].name, defs[*numDefs].signature);
        (*numDefs)++;
    }

    fclose(fp);
}

void freeFileInfo(FileInfo *file) {
    free(file->fileData);
}

int compareSignatures(const char *signature, const char *data, size_t len) {
    size_t i;

    for (i = 0; i < len && i < strlen(signature) && i < strlen(data); i++) {
        if (tolower(signature[i]) != tolower(data[i])) {
            return 0;
        }
    }

    return strlen(signature) == i;
}

int scanFile(const VirusDefinition *defs, int numDefs, const char *fileName) {
    FILE *fp;
    FileInfo file;
    char buffer[BUFFER_SIZE];
    size_t i, j, fileSize;

    fp = fopen(fileName, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file %s for scanning.\n", fileName);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    file.fileSize = fileSize;
    file.fileData = (char *)malloc(fileSize);

    while (fread(buffer, sizeof(char), BUFFER_SIZE, fp)) {
        for (i = 0; i < numDefs; i++) {
            if (fileSize - file.fileSize < strlen(defs[i].signature)) {
                continue;
            }

            if (compareSignatures(defs[i].signature, file.fileData + file.fileSize - strlen(defs[i].signature), strlen(defs[i].signature))) {
                printf("Virus %s detected in file %s!\n", defs[i].name, fileName);
                fclose(fp);
                freeFileInfo(&file);
                return 1;
            }

            file.fileSize -= strlen(defs[i].signature) + 1;
            file.fileData += strlen(defs[i].signature) + 1;
        }
    }

    freeFileInfo(&file);
    fclose(fp);

    return 0;
}

int main(int argc, char *argv[]) {
    VirusDefinition defs[MAX_DEFINITIONS];
    int numDefs;
    int i;

    if (argc != 2) {
        printf("Usage: %s <file_to_scan>\n", argv[0]);
        return 1;
    }

    readVirusDefinitions(defs, &numDefs);

    if (scanFile(defs, numDefs, argv[1])) {
        return 1;
    }

    printf("File %s is clean.\n", argv[1]);

    return 0;
}