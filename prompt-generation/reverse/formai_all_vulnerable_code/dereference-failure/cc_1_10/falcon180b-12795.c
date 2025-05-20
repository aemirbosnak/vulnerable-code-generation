//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    int id;
    char name[50];
    char description[100];
    int size;
} FileMetadata;

int main() {
    FILE *file;
    char buffer[BUFFER_SIZE];
    int metadata_count = 0;
    FileMetadata *metadata_list = NULL;

    file = fopen("metadata.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(buffer, BUFFER_SIZE, file)!= NULL) {
        if (metadata_count >= BUFFER_SIZE) {
            printf("Error: metadata list is full.\n");
            return 1;
        }

        FileMetadata *metadata = malloc(sizeof(FileMetadata));
        if (metadata == NULL) {
            printf("Error: could not allocate memory.\n");
            return 1;
        }

        metadata->id = atoi(strtok(buffer, ","));
        strcpy(metadata->name, strtok(NULL, ","));
        strcpy(metadata->description, strtok(NULL, ","));
        metadata->size = atoi(strtok(NULL, ","));

        metadata_list = realloc(metadata_list, sizeof(FileMetadata) * ++metadata_count);
        metadata_list[metadata_count - 1] = *metadata;
        free(metadata);
    }

    fclose(file);

    printf("Metadata count: %d\n", metadata_count);

    for (int i = 0; i < metadata_count; i++) {
        printf("ID: %d\n", metadata_list[i].id);
        printf("Name: %s\n", metadata_list[i].name);
        printf("Description: %s\n", metadata_list[i].description);
        printf("Size: %d\n\n", metadata_list[i].size);
    }

    free(metadata_list);

    return 0;
}