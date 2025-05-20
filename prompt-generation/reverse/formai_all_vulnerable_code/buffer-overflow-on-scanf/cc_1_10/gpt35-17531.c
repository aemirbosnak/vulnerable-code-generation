//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

//Function to extract metadata from a file
void extractMetadata(char* fileName)
{
    FILE *fp;
    char *metadata;
    long fileSize;

    //Opening the file in read mode
    fp = fopen(fileName, "r");

    //Checking if file exists and is accessible
    if(fp == NULL)
    {
        printf("Error: File not found or cannot be opened!\n");
        exit(EXIT_FAILURE);
    }

    //Determine the file size
    fseek(fp, 0, SEEK_END);
    fileSize = ftell(fp);
    rewind(fp);

    //Allocate memory for metadata
    metadata = (char *)malloc(fileSize);

    //Read file into metadata buffer
    fread(metadata, fileSize, 1, fp);

    //Print metadata
    printf("Metadata:\n%s\n", metadata);

    //Closing the file
    fclose(fp);

    //Free memory
    free(metadata);
}

//Main function to test metadata extraction
int main()
{
    char fileName[100];

    printf("Enter file name with path: ");
    scanf("%s", fileName);

    //Call function to extract metadata
    extractMetadata(fileName);

    return 0;
}