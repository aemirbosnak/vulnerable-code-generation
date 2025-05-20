//FormAI DATASET v1.0 Category: Data recovery tool ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFFER_SIZE 512

int main()
{
    FILE *fp;
    size_t fileLen;
    char *buffer, fileName[20], newFileName[30];
    int i, j, extensionIndex;

    // Get the name of the file to be recovered from user
    printf("Enter filename: ");
    scanf("%s", fileName);

    // Open the file in read mode
    fp = fopen(fileName, "r");
    if(fp == NULL)
    {
        printf("Error: Failed to open file %s\n", fileName);
        exit(1);
    }

    // Calculate the size of the file
    fseek(fp, 0, SEEK_END);
    fileLen = ftell(fp);
    rewind(fp);

    // Allocate memory for the buffer to store the file content
    buffer = (char *) malloc(fileLen * sizeof(char));
    if(buffer == NULL)
    {
        printf("Error: Failed to allocate memory for buffer\n");
        fclose(fp);
        exit(1);
    }

    // Read the contents of the file into the buffer
    fread(buffer, fileLen, 1, fp);

    // Close the file
    fclose(fp);

    // Search for the file extension
    extensionIndex = -1;
    for(i = strlen(fileName) - 1; i >= 0; i--)
    {
        if(fileName[i] == '.')
        {
            extensionIndex = i;
            break;
        }
    }

    if(extensionIndex == -1)
    {
        printf("Error: File extension not found\n");
        free(buffer);
        exit(1);
    }

    // Generate the new filename by appending "_recovered" to the original filename
    strncpy(newFileName, fileName, extensionIndex);
    strcat(newFileName, "_recovered");
    strcat(newFileName, fileName + extensionIndex);

    // Open the newly generated file in write mode
    fp = fopen(newFileName, "wb");
    if(fp == NULL)
    {
        printf("Error: Failed to create recovered file %s\n", newFileName);
        free(buffer);
        exit(1);
    }

    // Write the contents of the buffer back to the file
    fwrite(buffer, fileLen, 1, fp);

    // Close the file
    fclose(fp);

    // Free up the memory allocated for the buffer
    free(buffer);

    printf("Recovery process completed successfully. Recovered file saved as %s\n", newFileName);

    return 0;
}