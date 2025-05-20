//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: romantic
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];

    printf("Enter a message: ");
    scanf("%s", str);

    int sentiment = sentiment_analysis(str);

    switch (sentiment)
    {
        case 0:
            printf("Your message is neutral.\n");
            break;
        case 1:
            printf("Your message is positive.\n");
            break;
        case -1:
            printf("Your message is negative.\n");
            break;
    }

    return 0;
}

int sentiment_analysis(char *str)
{
    int i, sentiment = 0;
    char word[20];

    for (i = 0; str[i] != '\0'; i++)
    {
        word[0] = str[i];

        if (isupper(word[0]))
        {
            word[0] = tolower(word[0]);
        }

        if (strcmp(word, "happy") == 0 || strcmp(word, "joy") == 0)
        {
            sentiment++;
        }
        else if (strcmp(word, "sad") == 0 || strcmp(word, "sorry") == 0)
        {
            sentiment--;
        }
    }

    return sentiment;
}