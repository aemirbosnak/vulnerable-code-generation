//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_WORD_SIZE 100

int main(int argc, char *argv[])
{
    FILE *file;
    char line[MAX_LINE_SIZE];
    char word[MAX_WORD_SIZE];
    int word_count = 0;
    int char_count = 0;
    int line_count = 0;

    // Open the input file
    file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Error: could not open file %s.\n", argv[1]);
        exit(1);
    }

    // Read the file line by line
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL)
    {
        line_count++;
        char_count += strlen(line);

        // Remove any trailing newline character
        if (line[strlen(line) - 1] == '\n')
        {
            line[strlen(line) - 1] = '\0';
        }

        // Split the line into words
        char *token = strtok(line, ",.!?;:");
        while (token!= NULL)
        {
            strcpy(word, token);
            word_count++;

            // Remove any trailing punctuation from the word
            int length = strlen(word);
            if (length > 0 && word[length - 1] == '.' || word[length - 1] == '!' || word[length - 1] == '?')
            {
                word[length - 1] = '\0';
            }

            token = strtok(NULL, ",.!?;:");
        }
    }

    // Close the input file
    fclose(file);

    // Print the results
    printf("Total lines: %d\n", line_count);
    printf("Total characters: %d\n", char_count);
    printf("Total words: %d\n", word_count);

    return 0;
}