//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: surrealist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char str[1000];
    printf("Enter a sentence: ");
    scanf("%s", str);

    int len = strlen(str);
    int i = 0;
    int sentiment = 0;

    for (i = 0; i < len; i++)
    {
        char letter = str[i];

        switch (letter)
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                sentiment++;
                break;
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                sentiment++;
                break;
            case 'y':
            case 'Y':
                sentiment++;
                break;
            case 'n':
            case 'N':
                sentiment--;
                break;
            case 'r':
            case 'R':
                sentiment--;
                break;
            case 't':
            case 'T':
                sentiment--;
                break;
            default:
                break;
        }
    }

    if (sentiment > 0)
    {
        printf("The sentiment of the sentence is positive.\n");
    }
    else if (sentiment < 0)
    {
        printf("The sentiment of the sentence is negative.\n");
    }
    else
    {
        printf("The sentiment of the sentence is neutral.\n");
    }

    return 0;
}