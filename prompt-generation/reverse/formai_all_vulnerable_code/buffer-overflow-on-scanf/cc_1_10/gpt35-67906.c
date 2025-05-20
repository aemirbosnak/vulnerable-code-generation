//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_METADATA_LENGTH 1024

typedef struct {
    char key[MAX_METADATA_LENGTH];
    char value[MAX_METADATA_LENGTH];
} Metadata;

void extractMetadata(char* filePath) {
    FILE *fp;
    char metadata[MAX_METADATA_LENGTH];
    char fileName[MAX_FILE_NAME_LENGTH];
    char *key, *value;
    int i=0, j=0;
    Metadata metadataArr[MAX_METADATA_LENGTH];
    
    memset(metadata, '\0', sizeof(metadata));
    memset(fileName, '\0', sizeof(fileName));
    
    // Get the file name from the path
    for(i=strlen(filePath)-1;i>=0;i--) {
        if(filePath[i] == '/') {
            j=i+1;
            break;
        }
    }
    strncpy(fileName, &(filePath[j]), strlen(&(filePath[j])));
    
    fp = fopen(filePath, "r");
    if(fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    
    // Read through the file line by line and extract metadata
    while(fgets(metadata, MAX_METADATA_LENGTH, fp) != NULL) {
        if(metadata[0] == '#') {
            key = strtok(metadata, ":");
            value = strtok(NULL, "\n");
            strcpy(metadataArr[i].key, key+1);
            strcpy(metadataArr[i].value, value);
            i++;
        }
        memset(metadata, '\0', sizeof(metadata));
    }
    
    fclose(fp);
    
    // Print the metadata
    printf("Metadata for file '%s':\n", fileName);
    for(j=0;j<i;j++) {
        printf("%s: %s\n", metadataArr[j].key, metadataArr[j].value);
    }
}

int main() {
    char filePath[MAX_FILE_NAME_LENGTH];
    printf("Enter the file path: ");
    scanf("%s", filePath);
    extractMetadata(filePath);
    return 0;
}