//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: excited
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
    int positive_words = count_positive_words(str);
    int negative_words = count_negative_words(str);

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

int count_positive_words(char *str)
{
    char *word = strtok(str, " ");
    int count = 0;

    while (word)
    {
        if (strcmp(word, "happy") == 0 || strcmp(word, "joy") == 0 || strcmp(word, "good") == 0)
        {
            count++;
        }

        word = strtok(NULL, " ");
    }

    return count;
}

int count_negative_words(char *str)
{
    char *word = strtok(str, " ");
    int count = 0;

    while (word)
    {
        if (strcmp(word, "sad") == 0 || strcmp(word, "anger") == 0 || strcmp(word, "hate") == 0)
        {
            count++;
        }

        word = strtok(NULL, " ");
    }

    return count;
}