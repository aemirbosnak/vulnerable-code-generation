//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 200

char **words[MAX_WORDS];
char sentences[MAX_SENTENCE_LENGTH];

void analyze_sentence(char *sentence)
{
    char **words_ptr = words;
    int word_count = 0;
    int i = 0;

    // Tokenize the sentence
    char *word = strtok(sentence, " ");

    // Store each word in the words array
    while (word)
    {
        *words_ptr = word;
        words_ptr++;
        word_count++;
        word = strtok(NULL, " ");
    }

    // Calculate the word frequency
    for (i = 0; i < word_count; i++)
    {
        int frequency = 0;
        for (int j = 0; j < word_count; j++)
        {
            if (strcmp(words[i], words[j]) == 0)
            {
                frequency++;
            }
        }

        // If the word frequency is greater than 5, flag the sentence as suspicious
        if (frequency > 5)
        {
            printf("Suspicious sentence: %s\n", sentence);
        }
    }
}

int main()
{
    // Get the sentence from the user
    printf("Enter a sentence: ");
    gets(sentences);

    // Analyze the sentence
    analyze_sentence(sentences);

    return 0;
}