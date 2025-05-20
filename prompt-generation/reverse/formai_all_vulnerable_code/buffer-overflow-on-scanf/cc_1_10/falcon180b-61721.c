//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1000000
#define MAX_LINE_SIZE 1000
#define MAX_WORD_SIZE 50

int main()
{
    FILE *fp;
    char filename[MAX_FILE_SIZE];
    char line[MAX_LINE_SIZE];
    char word[MAX_WORD_SIZE];
    int count = 0;
    int i, j;

    // Prompt the user for the file name
    printf("Enter the file name: ");
    scanf("%s", filename);

    // Open the file for reading
    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    // Read the file line by line
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL)
    {
        count++;

        // Remove any leading or trailing white spaces from the line
        i = 0;
        while (isspace(line[i]))
        {
            i++;
        }
        j = strlen(line) - 1;
        while (isspace(line[j]))
        {
            line[j] = '\0';
            j--;
        }

        // Convert the line to lowercase
        for (i = 0; line[i]!= '\0'; i++)
        {
            line[i] = tolower(line[i]);
        }

        // Extract the words from the line
        word[0] = '\0';
        i = 0;
        while (line[i]!= '\0')
        {
            if (isspace(line[i]))
            {
                strcat(word, " ");
            }
            else
            {
                strcat(word, &line[i]);
            }
            i++;
        }

        // Print the line and word count
        printf("Line %d: %s\n", count, word);

        // Reset the word buffer
        word[0] = '\0';
    }

    // Close the file
    fclose(fp);

    return 0;
}