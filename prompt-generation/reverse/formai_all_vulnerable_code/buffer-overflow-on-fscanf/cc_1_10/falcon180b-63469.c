//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: funny
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

int main()
{
    FILE *fp;
    char filename[50];
    char word[MAX_WORD_LENGTH];
    int word_count = 0;
    int char_count = 0;
    int i = 0;

    // Ask the user for the filename
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file for reading
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    // Loop through each character in the file
    while ((fscanf(fp, "%c", &word[i]))!= EOF)
    {
        // Check if the character is a letter
        if (isalpha(word[i]))
        {
            // If the word is empty, start a new word
            if (i == 0)
            {
                strcpy(word, "");
            }

            // Append the character to the word
            strcat(word, &word[i]);

            // Increment the character count
            char_count++;
        }
        else
        {
            // If the word is not empty, count it
            if (strlen(word) > 0)
            {
                word_count++;
            }

            // Reset the word for the next word
            strcpy(word, "");
        }

        // Increment the character index
        i++;
    }

    // Close the file
    fclose(fp);

    // Print the results
    printf("Total words: %d\n", word_count);
    printf("Total characters: %d\n", char_count);

    return 0;
}