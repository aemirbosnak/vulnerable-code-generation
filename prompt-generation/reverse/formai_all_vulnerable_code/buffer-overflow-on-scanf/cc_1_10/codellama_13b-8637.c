//Code Llama-13B DATASET v1.0 Category: File handling ; Style: Ada Lovelace
/*
 * File handling example program in Ada Lovelace style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Declare variables
    FILE *file;
    char filename[256];
    char buffer[256];
    int line_number = 0;
    int number_of_lines = 0;
    int number_of_words = 0;

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file for reading
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    // Read the file line by line
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        line_number++;
        number_of_lines++;
        number_of_words += count_words(buffer);
    }

    // Print the results
    printf("Number of lines: %d\n", number_of_lines);
    printf("Number of words: %d\n", number_of_words);

    // Close the file
    fclose(file);

    return 0;
}

int count_words(char *str)
{
    int count = 0;
    char *p = str;

    // Skip leading whitespace
    while (*p == ' ')
        p++;

    // Count the number of words
    while (*p != '\0')
    {
        if (*p == ' ')
        {
            count++;

            // Skip trailing whitespace
            while (*p == ' ')
                p++;
        }

        p++;
    }

    return count;
}