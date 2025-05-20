//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 50
#define MAX_CHARACTERS 1000
#define MAX_VOWELS 10

int main(void)
{
    // Declare variables
    int word_count = 0;
    int character_count = 0;
    int vowel_count = 0;
    int average_word_length = 0;
    char line[MAX_WORD_LENGTH + 1];

    // Open input file
    FILE *input_file = fopen("input.txt", "r");

    // Check if file is valid
    if (input_file == NULL)
    {
        printf("Error: Unable to open input file\n");
        return 1;
    }

    // Read in text from file
    while (fgets(line, MAX_WORD_LENGTH, input_file) != NULL)
    {
        // Tokenize line into words
        char *words[5];
        int i = 0;
        while (sscanf(line, "%s %n", words[i], &i) == 1)
        {
            // Count words, characters, and vowels
            word_count++;
            character_count += strlen(words[i]);
            vowel_count += (words[i][0] == 'a' || words[i][0] == 'e' || words[i][0] == 'i' || words[i][0] == 'o' || words[i][0] == 'u');

            // Calculate average word length
            average_word_length += strlen(words[i]);
        }
    }

    // Print out results
    printf("Word Count: %d\n", word_count);
    printf("Character Count: %d\n", character_count);
    printf("Vowel Count: %d\n", vowel_count);
    printf("Average Word Length: %d\n", average_word_length / word_count);

    // Close input file
    fclose(input_file);

    return 0;
}