//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[1000];
    printf("Enter a sentence: ");
    gets(str);

    int sentiment = sentiment_analysis(str);

    if (sentiment == 0)
    {
        printf("Neutral\n");
    }
    else if (sentiment == 1)
    {
        printf("Positive\n");
    }
    else if (sentiment == -1)
    {
        printf("Negative\n");
    }

    return 0;
}

int sentiment_analysis(char *str)
{
    int length = strlen(str);
    int positive_words = 0;
    int negative_words = 0;
    char *words[] = {"happy", "joy", "love", "good", "excellent", "fine", "pleasant", "strong", "brave", "optimistic"};
    char *negatives[] = {"sad", "angry", "hate", "fear", "hate", "terrible", "bad", "awful", "terrible", "disgust"};

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (str[i] == words[j][0] || str[i] == words[j][1] || str[i] == words[j][2])
            {
                positive_words++;
            }
        }

        for (int k = 0; k < 10; k++)
        {
            if (str[i] == negatives[k][0] || str[i] == negatives[k][1] || str[i] == negatives[k][2])
            {
                negative_words++;
            }
        }
    }

    if (positive_words > negative_words)
    {
        return 1;
    }
    else if (negative_words > positive_words)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}