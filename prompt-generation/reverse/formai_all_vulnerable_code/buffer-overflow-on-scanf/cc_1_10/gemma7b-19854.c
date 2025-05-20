//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SENTENCE_LENGTH 256

int sentiment_analysis(char *sentence)
{
    int positive_words_count = 0;
    int negative_words_count = 0;
    char *positive_words[] = {"happy", "joy", "good", "excellent", "wonderful", "great", "fine", "pleasant", "beautiful", "fortunate"};
    char *negative_words[] = {"sad", "sadness", "bad", "terrible", "awful", "hate", "despicable", "gloomy", "dark", "depressing"};

    for (int i = 0; i < MAX_SENTENCE_LENGTH; i++)
    {
        if (sentence[i] == '\0')
            break;

        for (int j = 0; j < 10; j++)
        {
            if (strcmp(sentence + i, positive_words[j]) == 0)
                positive_words_count++;
            else if (strcmp(sentence + i, negative_words[j]) == 0)
                negative_words_count++;
        }
    }

    return (positive_words_count - negative_words_count) / 2;
}

int main()
{
    char sentence[MAX_SENTENCE_LENGTH];

    printf("Enter a sentence: ");
    scanf("%s", sentence);

    int sentiment = sentiment_analysis(sentence);

    if (sentiment > 0)
    {
        printf("The sentiment of the sentence is positive.\n");
    }
    else if (sentiment < 0)
    {
        printf("The sentiment of the sentence is negative.\n");
    }
    else
    {
        printf("The sentiment of the sentence is neutral.\n");
    }

    return 0;
}