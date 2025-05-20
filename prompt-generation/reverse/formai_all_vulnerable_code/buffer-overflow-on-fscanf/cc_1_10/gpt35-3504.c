//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

int main()
{
    char filename[20];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file.");
        return EXIT_FAILURE;
    }

    // Initialize array of word frequency counters
    int word_counts[26][26] = {0};

    // Read in file word by word
    char word[MAX_WORD_LENGTH] = {'\0'};
    while (fscanf(file, "%s", word) == 1)
    {
        // Convert all letters to lowercase
        for (int i = 0; word[i]; i++)
        {
            word[i] = tolower(word[i]);
        }

        // Increment frequency count for first and second letters of word
        if (isalpha(word[0]) && isalpha(word[1]))
        {
            int first_index = word[0] - 'a';
            int second_index = word[1] - 'a';
            word_counts[first_index][second_index]++;
        }
    }

    // Output frequency counts
    printf("  ");
    for (int i = 0; i < 26; i++)
    {
        printf("%c ", 'a' + i);
    }
    printf("\n");

    for (int i = 0; i < 26; i++)
    {
        printf("%c ", 'a' + i);
        for (int j = 0; j < 26; j++)
        {
            printf("%d ", word_counts[i][j]);
        }
        printf("\n");
    }

    fclose(file);
    return EXIT_SUCCESS;
}