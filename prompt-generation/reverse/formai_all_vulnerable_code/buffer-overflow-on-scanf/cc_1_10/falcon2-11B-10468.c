//Falcon2-11B DATASET v1.0 Category: Text processing ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 100

int countWords(char *filename);
void writeResult(int numWords, char *filename);

int main()
{
    char filename[MAX_FILE_NAME_LENGTH];
    char resultFilename[MAX_FILE_NAME_LENGTH];
    int numWords;

    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    numWords = countWords(filename);

    printf("Enter the name of the output file: ");
    scanf("%s", resultFilename);

    writeResult(numWords, resultFilename);

    return 0;
}

int countWords(char *filename)
{
    FILE *inputFile = fopen(filename, "r");
    if (inputFile == NULL)
    {
        printf("Error opening input file\n");
        return -1;
    }

    int numWords = 0;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), inputFile)!= NULL)
    {
        numWords++;

        for (int i = 0; i < strlen(line); i++)
        {
            line[i] = tolower(line[i]);
        }

        line[strcspn(line, "\r\n")] = '\0';

        if (strstr(line, " ")!= NULL)
        {
            numWords--;
        }
    }

    fclose(inputFile);
    return numWords;
}

void writeResult(int numWords, char *filename)
{
    FILE *outputFile = fopen(filename, "w");
    if (outputFile == NULL)
    {
        printf("Error opening output file\n");
        return;
    }

    fprintf(outputFile, "Number of words: %d\n", numWords);

    fclose(outputFile);
}