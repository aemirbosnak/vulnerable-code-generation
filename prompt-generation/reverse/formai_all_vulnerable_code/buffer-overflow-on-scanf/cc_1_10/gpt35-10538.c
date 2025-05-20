//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHARACTERS 1000

int main()
{
    FILE *filePointer;
    char fileLocation[MAX_CHARACTERS], character;
    int fileSize = 0, lineCount = 0, wordCount = 0, charCount = 0;

    printf("Enter the location of the file: ");
    scanf("%s", fileLocation);

    filePointer = fopen(fileLocation, "r");

    if (filePointer == NULL)
    {
        printf("Error opening file!");
        exit(1);
    }

    while((character = fgetc(filePointer)) != EOF)
    {
        if (character != ' ' && character != '\n')
        {
            charCount++;
        }
        else if (character == ' ')
        {
            wordCount++;
            charCount++;
        }
        else if (character == '\n')
        {
            lineCount++;
            charCount++;
        }
        fileSize++;
    }

    printf("File size: %d\n", fileSize);
    printf("Total number of characters: %d\n", charCount);
    printf("Total number of words: %d\n", wordCount+1);
    printf("Total number of lines: %d", lineCount+1);

    fclose(filePointer);

    return 0;
}