//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str[1000];
    printf("Enter a romantic message: ");
    gets(str);

    int sentiment = sentiment_analysis(str);

    if (sentiment == 1)
    {
        printf("Your message is filled with love and passion.");
    }
    else if (sentiment == 2)
    {
        printf("Your message is sweet and caring.");
    }
    else if (sentiment == 3)
    {
        printf("Your message is passionate and intense.");
    }
    else
    {
        printf("Your message is not very romantic.");
    }

    return 0;
}

int sentiment_analysis(char *str)
{
    int i = 0;
    int sentiment = 0;
    char *words[] = {"love", "passion", "sweet", "caring", "passionate", "intense"};

    for (i = 0; str[i] != '\0'; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (strcmp(str + i, words[j]) == 0)
            {
                sentiment++;
            }
        }
    }

    return sentiment;
}