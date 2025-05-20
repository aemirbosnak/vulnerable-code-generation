//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 100
#define MAX_CHARS 80

int main(int argc, char *argv[])
{
    FILE *fp;
    char filename[MAX_LINE];
    char line[MAX_LINE];
    int i, j, k, l, count;
    char ascii_art[MAX_LINE];

    // Ask user for input file name
    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    // Open input file
    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error: Could not open file %s.\n", filename);
        exit(1);
    }

    // Read input file line by line
    while (fgets(line, MAX_LINE, fp)!= NULL)
    {
        count = 0;

        // Convert line to uppercase
        for (i = 0; line[i]!= '\0'; i++)
        {
            if (isalpha(line[i]))
            {
                line[i] = toupper(line[i]);
            }
        }

        // Remove spaces and punctuation from line
        for (i = 0, j = 0; line[i]!= '\0'; i++)
        {
            if (isalpha(line[i]))
            {
                ascii_art[j++] = line[i];
            }
        }
        ascii_art[j] = '\0';

        // Check if line is too long
        if (j > MAX_CHARS)
        {
            printf("Error: Line is too long.\n");
            exit(1);
        }

        // Print ASCII art
        for (k = 0; k < strlen(ascii_art); k++)
        {
            for (l = 0; l < strlen(ascii_art); l++)
            {
                printf("%c", ascii_art[l]);
            }
            printf("\n");
        }
        count++;
    }

    // Close input file
    fclose(fp);

    printf("Done! %d lines of ASCII art generated.\n", count);

    return 0;
}