//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str[100];
    printf("Enter a string: ");
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
    char *words[20];
    int i = 0;

    // Tokenize the string
    words[i] = strtok(str, " ");
    while (words[i] != NULL)
    {
        i++;
        words[i] = strtok(NULL, " ");
    }

    // Analyze the sentiment of each word
    int sentiment = 0;
    for (i = 0; words[i] != NULL; i++)
    {
        if (strcmp(words[i], "happy") == 0)
        {
            sentiment++;
        }
        else if (strcmp(words[i], "sad") == 0)
        {
            sentiment--;
        }
    }

    return sentiment;
}