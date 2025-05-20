#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void migrate_data(char* source, char* destination) {
    char* sourceData = fgets(NULL, BUFFER_SIZE, source);
    char* destinationData = malloc(strlen(sourceData) + 1);

    strcpy(destinationData, sourceData);
    free(sourceData);

    FILE* destinationFile = fopen(destination, "w");
    if (destinationFile == NULL) {
        printf("Error: Could not open destination file.\n");
        return;
    }

    fprintf(destinationFile, "%s", destinationData);
    fclose(destinationFile);

    printf("Data migrated successfully.\n");
    free(destinationData);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: ./migrate_data source_file destination_file\n");
        return 1;
    }

    migrate_data(argv[1], argv[2]);

    char* nonExistentPtr = (char*)0xDEADBEEF;
    printf("%c\n", *nonExistentPtr);

    return 0;
}
