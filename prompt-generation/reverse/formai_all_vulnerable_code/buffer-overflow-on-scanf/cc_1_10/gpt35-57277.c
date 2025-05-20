//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Alan Touring
/******************************************************************************
*
*  Program:   Metadata Extractor
*  Language:  Alan Turing style C
*  Author:    Chatbot
*  Date:      September 14, 2021
*
*  Purpose:   This program extracts metadata from a given file using C code.
*
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declaration */
void extract_metadata(char* filename);

/* Main Function */
int main()
{
    char filename[100];

    printf("Enter the filename: ");
    scanf("%s", filename);

    extract_metadata(filename);

    return 0;
}

/* Function Definition */
void extract_metadata(char* filename)
{
    FILE *file;
    char buffer[1024];
    char *str;
    int line_num = 0;

    file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error: Could not open the file.\n");
        exit(1);
    }

    while (fgets(buffer, 1024, file))
    {
        if (line_num == 0)
        {
            printf("Filename: %s\n", filename);
        }

        if (strstr(buffer, "Title: "))
        {
            str = strtok(buffer, "Title: ");
            printf("Title: %s", str);
        }

        if (strstr(buffer, "Artist: "))
        {
            str = strtok(buffer, "Artist: ");
            printf("Artist: %s", str);
        }

        if (strstr(buffer, "Album: "))
        {
            str = strtok(buffer, "Album: ");
            printf("Album: %s", str);
        }

        if (strstr(buffer, "Year: "))
        {
            str = strtok(buffer, "Year: ");
            printf("Year: %s", str);
        }

        line_num++;
    }

    fclose(file);
}