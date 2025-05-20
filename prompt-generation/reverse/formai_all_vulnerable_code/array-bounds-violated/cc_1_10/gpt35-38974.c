//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: peaceful
#include <stdio.h>
#include <string.h>

void analyzeSentiment(char *sentence);

int main()
{
    char input[100];

    printf("Enter a sentence to analyze its sentiment: ");
    fgets(input, 100, stdin);

    // Remove the newline character at the end of the input string
    input[strlen(input) - 1] = '\0';

    analyzeSentiment(input);

    return 0;
}

void analyzeSentiment(char *sentence)
{
    // A list of positive words
    char *positiveWords[] = {"peaceful", "calm", "tranquil", "serene", "harmonious", "relaxing", "soothing", "pleasant", "joyful"};
    int numPositiveWords = 9;

    // A list of negative words
    char *negativeWords[] = {"angry", "frustrated", "stressed", "anxious", "sad", "depressed", "negative", "tense", "irritable", "unhappy"};
    int numNegativeWords = 10;

    int positiveScore = 0;
    int negativeScore = 0;

    // Tokenize the sentence
    char *token = strtok(sentence, " ");
    while (token != NULL)
    {
        // Check if the token matches a positive word
        for (int i = 0; i < numPositiveWords; i++)
        {
            if (strcmp(token, positiveWords[i]) == 0)
            {
                positiveScore++;
                break;
            }
        }

        // Check if the token matches a negative word
        for (int i = 0; i < numNegativeWords; i++)
        {
            if (strcmp(token, negativeWords[i]) == 0)
            {
                negativeScore++;
                break;
            }
        }

        token = strtok(NULL, " ");
    }

    printf("\nSentiment Analysis Results:\n");
    printf("==========================\n");
    printf("Positive Score: %d\n", positiveScore);
    printf("Negative Score: %d\n", negativeScore);

    // Determine the sentiment of the sentence based on the scores
    if (positiveScore > negativeScore)
    {
        if (negativeScore == 0)
        {
            printf("\nOverall Sentiment: Very Positive!\n");
        }
        else
        {
            printf("\nOverall Sentiment: Positive!\n");
        }
    }
    else if (negativeScore > positiveScore)
    {
        if (positiveScore == 0)
        {
            printf("\nOverall Sentiment: Very Negative!\n");
        }
        else
        {
            printf("\nOverall Sentiment: Negative!\n");
        }
    }
    else
    {
        printf("\nOverall Sentiment: Neutral!\n");
    }
}