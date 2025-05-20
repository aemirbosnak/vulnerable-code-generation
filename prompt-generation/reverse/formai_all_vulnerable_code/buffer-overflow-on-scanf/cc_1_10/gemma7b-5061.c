//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: protected
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    printf("Enter a sentence: ");
    scanf("%s", str);

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
    int i = 0;
    int sentiment = 0;

    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            sentiment++;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            sentiment++;
        }
        else if (str[i] == '!')
        {
            sentiment--;
        }
        else if (str[i] == '?')
        {
            sentiment--;
        }
        i++;
    }

    return sentiment;
}