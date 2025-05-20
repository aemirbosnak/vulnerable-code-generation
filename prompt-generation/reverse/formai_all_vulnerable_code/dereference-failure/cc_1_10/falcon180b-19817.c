//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_LINE_LENGTH 1024
#define MAX_NUM_KEYWORDS 10
#define MAX_KEYWORD_LENGTH 32

typedef struct {
    char fileName[MAX_FILE_NAME_LENGTH];
    int numKeywords;
    char keywords[MAX_NUM_KEYWORDS][MAX_KEYWORD_LENGTH];
} Metadata;

int readMetadata(Metadata *metadata) {
    char line[MAX_LINE_LENGTH];
    FILE *file = fopen(metadata->fileName, "r");

    if (file == NULL) {
        printf("Error: Unable to open file %s\n", metadata->fileName);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = (char *) malloc(fileSize + 1);
    fread(buffer, fileSize, 1, file);
    fclose(file);

    char *token = strtok(buffer, "\n");
    int numKeywords = 0;

    while (token!= NULL && numKeywords < MAX_NUM_KEYWORDS) {
        if (strlen(token) > 0 && token[0] == '#') {
            strcpy(metadata->keywords[numKeywords], &token[1]);
            numKeywords++;
        }
        token = strtok(NULL, "\n");
    }

    metadata->numKeywords = numKeywords;
    free(buffer);

    return 0;
}

int main() {
    Metadata metadata;
    metadata.numKeywords = 0;

    printf("Enter file name: ");
    scanf("%s", metadata.fileName);

    readMetadata(&metadata);

    printf("Number of keywords: %d\n", metadata.numKeywords);

    for (int i = 0; i < metadata.numKeywords; i++) {
        printf("Keyword %d: %s\n", i + 1, metadata.keywords[i]);
    }

    return 0;
}