//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SENTIMENT_WORDS 50

typedef struct SentimentWord
{
    char word[20];
    int sentiment_score;
} SentimentWord;

SentimentWord sentiment_words[MAX_SENTIMENT_WORDS];

void load_sentiment_words()
{
    FILE* fp = fopen("sentiment_words.txt", "r");
    if (fp == NULL)
    {
        return;
    }

    int i = 0;
    char word[20];
    while (fscanf(fp, "%s %d", word, &sentiment_words[i].sentiment_score) != EOF)
    {
        strcpy(sentiment_words[i].word, word);
        i++;
    }

    fclose(fp);
}

int analyze_sentiment(char* text)
{
    load_sentiment_words();

    int sentiment_score = 0;
    for (int i = 0; sentiment_words[i].word != NULL; i++)
    {
        if (strstr(text, sentiment_words[i].word) != NULL)
        {
            sentiment_score += sentiment_words[i].sentiment_score;
        }
    }

    return sentiment_score;
}

int main()
{
    char text[] = "I am very happy today.";
    int sentiment_score = analyze_sentiment(text);

    printf("Sentiment score: %d", sentiment_score);

    return 0;
}