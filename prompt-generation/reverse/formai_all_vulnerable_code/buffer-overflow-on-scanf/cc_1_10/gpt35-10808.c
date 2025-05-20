//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>

/* This program demonstrates the use of C metadata extractor*/
/* Define necessary constants */
#define MAX_METADATA_SIZE 1024
#define MAX_LINE_SIZE 1024

/* Define necessary error messages */
#define FILE_NOT_FOUND_ERROR "File not found, please enter a valid file path"
#define METADATA_TOO_LARGE_ERROR "Metadata too large, please increase MAX_METADATA_SIZE"
#define LINE_TOO_LONG_ERROR "Line size too long, please increase MAX_LINE_SIZE"

/* Function to extract metadata from a given file path */
char* extract_metadata(char* file_path){
    /* Create necessary variables */
    FILE* file;
    char* metadata = malloc(MAX_METADATA_SIZE); /* Allocate memory for metadata */
    char line[MAX_LINE_SIZE];
    int metadata_size = 0;
    int line_length;

    /* Open file for reading */
    file = fopen(file_path, "r");

    /* If file not found, display error message and return NULL */
    if (file == NULL){
        printf(FILE_NOT_FOUND_ERROR);
        return NULL;
    }

    /* Read each line of the file and extract metadata */
    while(fgets(line, MAX_LINE_SIZE, file) != NULL){
        line_length = strlen(line);

        /* If line too long, display error message and return NULL */
        if (line[line_length-1] != '\n' && !feof(file)){
            printf(LINE_TOO_LONG_ERROR);
            return NULL;
        }
        
        /* Check if the line contains metadata */
        if (strstr(line, "metadata: ") != NULL){
            /* Get metadata and add to metadata string */
            metadata_size += snprintf(metadata+metadata_size, MAX_METADATA_SIZE-metadata_size, "%s", line);
            
            /* If metadata too large, display error message and return NULL */
            if (metadata_size >= MAX_METADATA_SIZE){
                printf(METADATA_TOO_LARGE_ERROR);
                return NULL;
            }
        }
    }

    /* Close file */
    fclose(file);

    /* If metadata is empty, return NULL */
    if (metadata_size == 0){
        free(metadata);
        return NULL;
    }

    /* Return extracted metadata */
    return metadata;
}


/* Main function to demonstrate the C metadata extractor */
int main(){
    printf("Welcome to the C Metadata Extractor!\n");
    printf("Please enter the file path: ");

    /* Get file path from user */
    char file_path[MAX_LINE_SIZE];
    scanf("%s",file_path);

    /* Extract metadata */
    char* metadata = extract_metadata(file_path);

    /* If metadata was extracted, display it */
    if (metadata != NULL){
        printf("\nMetadata extracted:\n%s", metadata);
    } else {
        /* If metadata was not extracted, display error message */
        printf("\nMetadata could not be extracted");
    }

    /* Deallocate memory */
    free(metadata);

    /* Exit program */
    return 0;
}