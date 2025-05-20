//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: energetic
#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";
    int i = 0;
    int word_count = 0;
    char word[20];

    printf("Original Text:\n\n");
    printf("%s", str);

    printf("\nWord Frequency:\n");

    // Loop through the text to count the number of words
    while (str[i] != '\0')
    {
        char current_word[20];
        int j = 0;

        // Identify the current word
        while (str[i] != ' ' && str[i] != '\0')
        {
            current_word[j] = str[i];
            i++;
            j++;
        }

        // Add the current word to the word list
        word[word_count] = current_word;
        word_count++;

        // Increment the index
        i++;
    }

    // Print the word frequency
    for (int k = 0; k < word_count; k++)
    {
        int frequency = 0;
        for (int l = 0; l < word_count; l++)
        {
            if (strcmp(word[k], word[l]) == 0)
            {
                frequency++;
            }
        }

        printf("%s: %d\n", word[k], frequency);
    }

    return 0;
}