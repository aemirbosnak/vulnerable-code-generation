//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 100

int main(int argc, char *argv[])
{
    FILE *input_file = NULL;
    char word[MAX_WORD_SIZE];
    int word_count = 0;
    int total_char_count = 0;
    int max_word_length = 0;
    char *longest_word = malloc(MAX_WORD_SIZE * sizeof(char));

    if (argc!= 2)
    {
        printf("Error: Please provide a file name as an argument.\n");
        return 1;
    }

    input_file = fopen(argv[1], "r");

    if (input_file == NULL)
    {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fscanf(input_file, "%s", word)!= EOF)
    {
        word_count++;
        total_char_count += strlen(word);

        if (strlen(word) > max_word_length)
        {
            max_word_length = strlen(word);
            strcpy(longest_word, word);
        }
    }

    printf("Total word count: %d\n", word_count);
    printf("Total character count: %d\n", total_char_count);
    printf("Longest word: %s (length: %d)\n", longest_word, max_word_length);

    fclose(input_file);
    free(longest_word);

    return 0;
}