//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to extract metadata
int extract_metadata(char *filename, char *metadata)
{
    FILE *fp;
    char line[MAX_SIZE];

    // Open the file
    if((fp = fopen(filename, "rb")) == NULL)
        return -1; //Unable to open file

    // Read line by line
    while(fgets(line, MAX_SIZE, fp))
    {
        if(strncmp(line, "Metadata:", 9) == 0)
        {
            strcpy(metadata, line + 10);
            fclose(fp);
            return 0; // Metadata successfully extracted
        }
    }

    fclose(fp);
    return -1; // No metadata found
}

int main()
{
    char filename[MAX_SIZE], metadata[MAX_SIZE];

    // Get filename from user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Extract metadata
    if(extract_metadata(filename, metadata) == 0)
    {
        printf("Metadata for file %s is: %s", filename, metadata);
    }
    else
    {
        printf("Metadata not found.");
    }

    return 0;
}