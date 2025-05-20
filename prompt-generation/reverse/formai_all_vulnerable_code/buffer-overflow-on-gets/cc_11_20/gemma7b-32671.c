//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: grateful
#include <stdio.h>
#include <string.h>

int main()
{
    char str[200];
    printf("Enter a sentence: ");
    gets(str);

    int length = strlen(str);
    char sentiment[length];

    for (int i = 0; i < length; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            sentiment[i] = str[i] - 32;
        }
        else
        {
            sentiment[i] = str[i];
        }
    }

    int positive = 0;
    int negative = 0;

    for (int i = 0; i < length; i++)
    {
        if (sentiment[i] == 'A' || sentiment[i] == 'E' || sentiment[i] == 'I' || sentiment[i] == 'O' || sentiment[i] == 'U')
        {
            positive++;
        }
        else if (sentiment[i] == 'F' || sentiment[i] == 'H' || sentiment[i] == 'L' || sentiment[i] == 'N' || sentiment[i] == 'R')
        {
            negative++;
        }
    }

    printf("The sentiment of the sentence is: ");

    if (positive > negative)
    {
        printf("Positive");
    }
    else if (negative > positive)
    {
        printf("Negative");
    }
    else
    {
        printf("Neutral");
    }

    return 0;
}