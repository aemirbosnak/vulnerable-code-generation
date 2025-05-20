//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: calm
#include <stdio.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 256

int sentiment_analysis(char *sentence)
{
    int length = strlen(sentence);
    char *words[length];
    int i = 0;
    int sentiment = 0;

    // Tokenize the sentence into words
    for (i = 0; i < length; i++)
    {
        if (sentence[i] == ' ' || sentence[i] == '\n' || sentence[i] == '\t')
        {
            words[i] = malloc(MAX_SENTENCE_LENGTH);
            strncpy(words[i], sentence + i, MAX_SENTENCE_LENGTH - 1);
            i++;
        }
    }

    // Analyze each word
    for (i = 0; words[i] != NULL; i++)
    {
        if (strcmp(words[i], "good") == 0)
        {
            sentiment++;
        }
        else if (strcmp(words[i], "bad") == 0)
        {
            sentiment--;
        }
    }

    // Return the sentiment score
    return sentiment;
}

int main()
{
    char sentence[MAX_SENTENCE_LENGTH];

    // Get the sentence from the user
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    // Analyze the sentiment of the sentence
    int sentiment = sentiment_analysis(sentence);

    // Print the sentiment score
    printf("The sentiment score for the sentence is: %d\n", sentiment);

    return 0;
}