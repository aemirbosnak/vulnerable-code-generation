//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

#define SENTIMENT_ANALYSIS_THRESHOLD 5

int main()
{
    char sentiment_analysis_text[200];
    int sentiment_analysis_score = 0;

    printf("Enter text for sentiment analysis:");
    scanf("%s", sentiment_analysis_text);

    // Analyze text for positive and negative words
    for (int i = 0; sentiment_analysis_text[i] != '\0'; i++)
    {
        if (sentiment_analysis_text[i] >= 'a' && sentiment_analysis_text[i] <= 'z')
        {
            // Count positive words
            if (sentiment_analysis_text[i] == 'a' || sentiment_analysis_text[i] == 'e' || sentiment_analysis_text[i] == 'i' || sentiment_analysis_text[i] == 'o' || sentiment_analysis_text[i] == 'u')
            {
                sentiment_analysis_score++;
            }

            // Count negative words
            if (sentiment_analysis_text[i] == 'n' || sentiment_analysis_text[i] == 'r' || sentiment_analysis_text[i] == 's' || sentiment_analysis_text[i] == 't' || sentiment_analysis_text[i] == 'h')
            {
                sentiment_analysis_score--;
            }
        }
    }

    // Calculate sentiment analysis score
    sentiment_analysis_score = sentiment_analysis_score / SENTIMENT_ANALYSIS_THRESHOLD;

    // Display sentiment analysis score
    if (sentiment_analysis_score > 0)
    {
        printf("Sentiment analysis score: Positive\n");
    }
    else if (sentiment_analysis_score < 0)
    {
        printf("Sentiment analysis score: Negative\n");
    }
    else
    {
        printf("Sentiment analysis score: Neutral\n");
    }

    return 0;
}