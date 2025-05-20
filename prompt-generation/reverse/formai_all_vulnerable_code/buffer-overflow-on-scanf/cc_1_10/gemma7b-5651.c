//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415926535

int main()
{
    char str[1000];
    printf("Enter a message: ");
    scanf("%s", str);

    int l = strlen(str);
    if (l < 10)
    {
        printf("Message too short.\n");
        return 0;
    }

    int nWords = countWords(str);
    if (nWords > 20)
    {
        printf("Message has too many words.\n");
        return 0;
    }

    int spamScore = calculateSpamScore(str);
    if (spamScore > 50)
    {
        printf("Message is suspected to be spam.\n");
        return 0;
    }

    printf("Message is not suspected to be spam.\n");
    return 0;
}

int countWords(char *str)
{
    char *word = strtok(str, " ");
    int nWords = 0;

    while (word)
    {
        nWords++;
        word = strtok(NULL, " ");
    }

    return nWords;
}

int calculateSpamScore(char *str)
{
    int score = 0;

    if (containsPunctuation(str))
    {
        score += 10;
    }

    if (containsCaps(str))
    {
        score += 5;
    }

    if (containsNumbers(str))
    {
        score += 3;
    }

    if (containsEmail(str))
    {
        score += 2;
    }

    return score;
}

int containsPunctuation(char *str)
{
    return strchr(str, '.') || strchr(str, ',') || strchr(str, '?') || strchr(str, '"') || strchr(str, '$');
}

int containsCaps(char *str)
{
    return strchr(str, 'A') || strchr(str, 'B') || strchr(str, 'C') || strchr(str, 'D') || strchr(str, 'E');
}

int containsNumbers(char *str)
{
    return strchr(str, '0') || strchr(str, '1') || strchr(str, '2') || strchr(str, '3') || strchr(str, '4') || strchr(str, '5') || strchr(str, '6') || strchr(str, '7') || strchr(str, '8') || strchr(str, '9');
}

int containsEmail(char *str)
{
    return strstr(str, "@") || strstr(str, ".") || strstr(str, ":");
}