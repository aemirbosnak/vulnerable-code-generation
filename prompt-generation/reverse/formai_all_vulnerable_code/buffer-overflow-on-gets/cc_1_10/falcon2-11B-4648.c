//Falcon2-11B DATASET v1.0 Category: Sentiment analysis tool ; Style: complete
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to calculate sentiment score of a sentence
int sentimentScore(char sentence[])
{
    // Define positive and negative words
    char positive[] = "great, best, wonderful, amazing, fantastic, awesome, excellent, incredible, superb";
    char negative[] = "bad, worst, terrible, awful, horrible, poor, terrible, awful, horrible";

    // Length of positive and negative words
    int positiveLength = strlen(positive);
    int negativeLength = strlen(negative);

    // Length of the sentence
    int sentenceLength = strlen(sentence);

    // Initialize sentiment score to 0
    int sentiment = 0;

    // Check for positive words
    for (int i = 0; i < positiveLength; i++)
    {
        if (strstr(sentence, positive[i]))
        {
            sentiment++;
        }
    }

    // Check for negative words
    for (int i = 0; i < negativeLength; i++)
    {
        if (strstr(sentence, negative[i]))
        {
            sentiment--;
        }
    }

    // Return sentiment score
    return sentiment;
}

int main()
{
    char sentence[100];
    printf("Enter a sentence: ");
    gets(sentence);

    // Calculate sentiment score
    int sentiment = sentimentScore(sentence);

    // Print sentiment score
    printf("Sentiment score: %d\n", sentiment);

    return 0;
}