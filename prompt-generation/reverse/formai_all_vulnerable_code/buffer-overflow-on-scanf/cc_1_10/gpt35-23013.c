//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 256
#define MAX_METADATA_LEN 1024

/* function to extract metadata from file */
char* extract_metadata(char* filename) {

    FILE* fp;
    char* metadata = (char*) malloc(MAX_METADATA_LEN * sizeof(char)); // allocate memory for metadata
    char buffer[MAX_METADATA_LEN];
    int i = 0;

    // open file in read mode
    fp = fopen(filename, "r");

    // check if file could be opened
    if (fp == NULL) {
        printf("\nError opening file: %s\n", filename);
        exit(1);
    }

    // read first line of file
    fgets(buffer, MAX_METADATA_LEN, fp);

    // check if line contains metadata
    if (strstr(buffer, "Metadata:") != NULL) {
        i = strlen("Metadata:"); // skip "Metadata:" string
        while (buffer[i] != '\0' && i < MAX_METADATA_LEN) {
            metadata[i - strlen("Metadata:")] = buffer[i]; // copy metadata to output
            i++;
        }
    } 

    // close file
    fclose(fp);

    return metadata;
}

/* main function to test metadata extractor */
int main(int argc, char *argv[]) {

    char filename[MAX_FILENAME_LEN];
    printf("Enter name of file to extract metadata from: ");
    scanf("%s", filename);
    
    char* metadata = extract_metadata(filename);
    if (metadata != NULL) {
        printf("\nMetadata for file %s:\n%s\n", filename, metadata);
    } else {
        printf("\nNo metadata found in file: %s\n", filename);
    }

    free(metadata);

    return 0;
}