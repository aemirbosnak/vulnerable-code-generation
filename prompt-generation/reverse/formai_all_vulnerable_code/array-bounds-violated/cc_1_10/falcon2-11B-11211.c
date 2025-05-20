//Falcon2-11B DATASET v1.0 Category: Sentiment analysis tool ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main()
{
    char sentence[MAX_LENGTH];
    char words[MAX_LENGTH][MAX_LENGTH];
    int i, j, k;
    int count = 0;

    printf("Enter a sentence: ");
    fgets(sentence, MAX_LENGTH, stdin);

    sentence[strcspn(sentence, "\n")] = '\0';

    for (i = 0; sentence[i]!= '\0'; i++)
    {
        if (isalpha(sentence[i]))
        {
            words[count][j++] = sentence[i];
        }
    }
    words[count][j] = '\0';

    for (i = 0; i < count; i++)
    {
        printf("%s ", words[i]);
    }
    printf("\n");

    for (i = 0; i < count; i++)
    {
        for (j = 0; words[i][j]!= '\0'; j++)
        {
            if (islower(words[i][j]))
            {
                words[i][j] = toupper(words[i][j]);
            }
        }
    }

    for (i = 0; i < count; i++)
    {
        printf("%s ", words[i]);
    }
    printf("\n");

    return 0;
}