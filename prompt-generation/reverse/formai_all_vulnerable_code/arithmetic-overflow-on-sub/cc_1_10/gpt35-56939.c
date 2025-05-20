//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    char *name; // name of metadata tag
    uint32_t size; // size of metadata value
    char *value; // value of metadata
} MetaData;

// function prototypes
void extractMetaData(const char *filename, MetaData **data, size_t *totalCount);
void freeMetaData(MetaData **data, size_t count);

int main(int argc, char **argv) {
    // check for valid number of arguments
    if(argc != 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        return 1;
    }
    
    // initialize variables
    MetaData *data = NULL;
    size_t totalCount = 0;
    
    // extract metadata
    extractMetaData(argv[1], &data, &totalCount);
    
    // print metadata
    for(size_t i = 0; i < totalCount; i++) {
        printf("Metadata #%lu: name=%s size=%u value=%s\n", i + 1, data[i].name, data[i].size, data[i].value);
    }
    
    // free memory
    freeMetaData(&data, totalCount);
    
    return 0;
}

// extract metadata from file
void extractMetaData(const char *filename, MetaData **data, size_t *totalCount) {
    // open file
    FILE *fp = fopen(filename, "rb");
    if(fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    
    // initialize variables
    char *buffer = NULL;
    size_t bufferSize = 0;
    ssize_t bytesRead;
    int inMetaData = 0;
    char metadataName[256];
    size_t metadataSize = 0;
    size_t metadataCount = 0;
    
    // read file
    while((bytesRead = getline(&buffer, &bufferSize, fp)) != -1) {
        // remove trailing newline
        if(buffer[bytesRead - 1] == '\n') {
            buffer[bytesRead - 1] = '\0';
            bytesRead--;
        }
        
        // check for start of metadata
        if(strcmp(buffer, "BEGIN_METADATA") == 0) {
            inMetaData = 1;
            metadataCount++;
            
            // allocate memory for new metadata entry
            *data = realloc(*data, metadataCount * sizeof(MetaData));
            if(*data == NULL) {
                perror("realloc");
                exit(EXIT_FAILURE);
            }
        }
        // check for end of metadata
        else if(strcmp(buffer, "END_METADATA") == 0) {
            inMetaData = 0;
        }
        // parse metadata line
        else if(inMetaData) {
            // check for metadata name
            if(strncmp(buffer, "name=", 5) == 0) {
                strncpy(metadataName, buffer + 5, sizeof(metadataName));
                metadataName[sizeof(metadataName) - 1] = '\0';
            }
            // check for metadata size
            else if(strncmp(buffer, "size=", 5) == 0) {
                metadataSize = atol(buffer + 5);
            }
            // add metadata value to current entry
            else {
                MetaData *currentEntry = &((*data)[metadataCount - 1]);
                currentEntry->name = strdup(metadataName);
                currentEntry->size = metadataSize;
                currentEntry->value = malloc(metadataSize + 1);
                strncpy(currentEntry->value, buffer, metadataSize);
                currentEntry->value[metadataSize] = '\0';
            }
        }
    }
    
    // set total count
    *totalCount = metadataCount;
    
    // free memory
    free(buffer);
    fclose(fp);
}

// free metadata array
void freeMetaData(MetaData **data, size_t count) {
    for(size_t i = 0; i < count; i++) {
        free((*data)[i].name);
        free((*data)[i].value);
    }
    free(*data);
    *data = NULL;
}