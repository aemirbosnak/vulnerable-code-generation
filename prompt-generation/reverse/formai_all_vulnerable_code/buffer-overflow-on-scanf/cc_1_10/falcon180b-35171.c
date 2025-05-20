//Falcon-180B DATASET v1.0 Category: Text processing ; Style: beginner-friendly
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

int main()
{
    FILE *input_file;
    char filename[MAX_WORD_LENGTH];
    char line[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    int num_words = 0;
    int i = 0;

    // Ask user for input file name
    printf("Enter input file name: ");
    scanf("%s", filename);

    // Open input file
    input_file = fopen(filename, "r");

    // Check if input file was opened successfully
    if (input_file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    // Read input file line by line
    while (fgets(line, MAX_WORD_LENGTH, input_file)!= NULL)
    {
        // Convert line to lowercase
        for (i = 0; i < strlen(line); i++)
        {
            line[i] = tolower(line[i]);
        }

        // Split line into words
        char *token = strtok(line, ",.?!;:");
        while (token!= NULL)
        {
            // Check if word is already in array
            int found = 0;
            for (i = 0; i < num_words; i++)
            {
                if (strcmp(word[i], token) == 0)
                {
                    found = 1;
                    break;
                }
            }

            // Add new word to array
            if (found == 0)
            {
                strcpy(word[num_words], token);
                num_words++;
            }

            if (num_words >= MAX_WORDS)
            {
                printf("Maximum number of words reached.\n");
                break;
            }

            token = strtok(NULL, ",.?!;:");
        }
    }

    // Close input file
    fclose(input_file);

    // Print number of words in file
    printf("Number of words in file: %d\n", num_words);

    // Print words in alphabetical order
    printf("Words in alphabetical order:\n");
    for (i = 0; i < num_words; i++)
    {
        printf("%s\n", word[i]);
    }

    return 0;
}