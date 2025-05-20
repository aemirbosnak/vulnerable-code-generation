//FormAI DATASET v1.0 Category: Data recovery tool ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to find the file size
long int fileSize(FILE *file)
{
    long int size;

    fseek(file, 0L, SEEK_END);
    size = ftell(file);
    fseek(file, 0L, SEEK_SET);

    return size;
}

// function to display the data in hexadecimal format
void displayDataInHex(FILE *file, long int size)
{
    int c;
    int i = 0;

    while ((c = fgetc(file)) != EOF && i <= size)
    {
        printf("%02X ", c);
        i++;
    }
}

// function to recover the data from the file
int recoverDataFromFile(FILE *file, long int size, char *outputFileName)
{
    int c;
    int i = 0;
    FILE *outputFile = fopen(outputFileName, "wb");

    if (outputFile == NULL)
    {
        printf("Error: Unable to create output file\n");
        return -1;
    }

    while ((c = fgetc(file)) != EOF && i <= size)
    {
        fputc(c, outputFile);
        i++;
    }

    fclose(outputFile);

    return 0;
}

int main()
{
    FILE *file;
    long int size;
    char inputFileName[100], outputFileName[100];

    // prompt user for file name
    printf("Enter the input file name: ");
    scanf("%s", inputFileName);

    // open file
    file = fopen(inputFileName, "rb");

    // check if file exists
    if (file == NULL)
    {
        printf("Error: Input file not found\n");
        exit(1);
    }

    // find file size
    size = fileSize(file);

    // display file data in hexadecimal format
    printf("File data in hexadecimal format:\n");
    displayDataInHex(file, size);

    // prompt user for output file name
    printf("\nEnter the output file name: ");
    scanf("%s", outputFileName);

    // recover data from the file
    if (recoverDataFromFile(file, size, outputFileName) == 0)
    {
        printf("\nData recovery successful!\n");
    }
    else
    {
        printf("\nError: Data recovery failed\n");
    }

    // close file
    fclose(file);

    return 0;
}