//Falcon2-11B DATASET v1.0 Category: Word Frequency Counter ; Style: portable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100
#define MAX_WORD 100

int main()
{
    char sentence[MAX_LENGTH];
    char words[MAX_WORD][MAX_LENGTH];
    int num_words = 0;
    int word_freq[MAX_WORD];

    printf("Enter a sentence: ");
    fgets(sentence, MAX_LENGTH, stdin);

    // Remove trailing newline character
    if (sentence[strlen(sentence) - 1] == '\n')
        sentence[strlen(sentence) - 1] = '\0';

    // Tokenize the sentence into words
    char *token = strtok(sentence, " \n\t");
    while (token!= NULL)
    {
        strcpy(words[num_words], token);
        word_freq[num_words] = 0;
        num_words++;
        token = strtok(NULL, " \n\t");
    }

    // Count the frequency of each word
    for (int i = 0; i < num_words; i++)
    {
        int j = 0;
        while (words[i][j]!= '\0')
        {
            if (isalpha(words[i][j]))
            {
                word_freq[i]++;
            }
            j++;
        }
    }

    // Print the word frequency
    for (int i = 0; i < num_words; i++)
    {
        printf("%-10s: %d\n", words[i], word_freq[i]);
    }

    return 0;
}