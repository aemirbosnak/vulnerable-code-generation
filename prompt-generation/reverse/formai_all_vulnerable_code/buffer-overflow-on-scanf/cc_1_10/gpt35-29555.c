//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_SIZE 255

int isVirus(FILE *file);

int main()
{
    char fileName[MAX_FILE_NAME_SIZE];
    printf("Enter the file name to scan for viruses: ");
    scanf("%s", fileName);

    FILE *file = fopen(fileName, "rb");
    if (file == NULL)
    {
        printf("Could not open file!");
        return 1;
    }

    if (isVirus(file))
    {
        printf("The file is infected with a virus!");
        return 1;
    }

    printf("The file is safe. No viruses found!");

    fclose(file);
    return 0;
}

int isVirus(FILE *file)
{
    char sequence[] = "\n\r\t "; // characters to ignore
    char virus[] = "EvilVirus"; // the virus signature to search for

    int virusLen = strlen(virus); // length of the virus signature

    fseek(file, 0, SEEK_END); // move the file pointer to the end of the file
    int fileSize = ftell(file); // get the size of the file

    char *buffer = (char *)malloc(fileSize + 1); // allocate memory for the file buffer
    memset(buffer, 0, fileSize + 1); // clear the buffer

    fseek(file, 0, SEEK_SET); // move the file pointer back to the start of the file
    fread(buffer, fileSize, 1, file); // read the contents of the file into the buffer

    // check for the virus signature
    int i, j;
    for (i = 0; i < fileSize - virusLen; i++)
    {
        for (j = 0; j < virusLen && buffer[i+j] != '\0' && strchr(sequence, buffer[i+j]); j++)
        {
            // do nothing, just skip
        }

        if (j == virusLen && !strchr(sequence, buffer[i+j]))
        {
            // found the virus signature
            return 1;
        }
    }

    free(buffer); // free the buffer
    return 0; // no viruses found
}