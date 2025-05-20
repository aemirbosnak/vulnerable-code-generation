//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.1415926535

int main()
{

    int i = 0;
    char str[1000];
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
    }

    int words = 0;
    char word[100];
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            words++;
            strcpy(word, "");
        }
        else
        {
            strcat(word, str[i]);
        }
    }

    words++;

    double spam_score = 0.0;
    double avg_word_length = 0.0;
    double num_special_chars = 0.0;

    for (i = 0; word[i] != '\0'; i++)
    {
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            avg_word_length++;
        }
        else if (word[i] >= '0' && word[i] <= '9')
        {
            num_special_chars++;
        }
    }

    spam_score = (words - 1) * avg_word_length + num_special_chars / 2;

    if (spam_score > 50.0)
    {
        printf("Spam!");
    }
    else
    {
        printf("Not spam!");
    }

    return 0;
}