//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str[1000];
    printf("Enter a sentence: ");
    scanf("%s", str);

    int length = strlen(str);
    char sentiment[length];

    for (int i = 0; i < length; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            sentiment[i] = str[i] - 'a' + 1;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            sentiment[i] = str[i] - 'A' + 1;
        }
        else
        {
            sentiment[i] = 0;
        }
    }

    int positive = 0, negative = 0, neutral = 0;

    for (int i = 0; i < length; i++)
    {
        if (sentiment[i] >= 4)
        {
            positive++;
        }
        else if (sentiment[i] <= 2)
        {
            negative++;
        }
        else
        {
            neutral++;
        }
    }

    printf("Positive words: %d\n", positive);
    printf("Negative words: %d\n", negative);
    printf("Neutral words: %d\n", neutral);

    return 0;
}