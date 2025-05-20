//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Ada Lovelace
/* This program is a sentiment analysis tool that determines the sentiment of a given text. It reads in a text file and analyzes the words to determine whether it is positive, negative, or neutral. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char filename[50];
    char word[50], ch;
    int count_pos = 0, count_neg = 0, count_neu = 0;
    char positive_words[10][50] = {"happy", "joyful", "awesome", "exciting", "amazing", "love", "advantage", "friendly", "helpful", "pleasure"};
    char negative_words[10][50] = {"sad", "disappointing", "frustrating", "annoying", "awful", "hate", "disadvantage", "mean", "threatening", "powerless"};

    printf("Please enter the name of the text file (ex: review.txt): ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error! File not found.");
        exit(1);
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == ' ' || ch == '\n')
        {
            int i = 0, flag = 0;

            for (i = 0; i < 10; i++)
            {
                if (strcmp(word, positive_words[i]) == 0)
                {
                    count_pos++;
                    flag = 1;
                    break;
                }
                else if (strcmp(word, negative_words[i]) == 0)
                {
                    count_neg++;
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
            {
                count_neu++;
            }

            memset(word, 0, sizeof(word));
            continue;
        }

        strncat(word, &ch, 1);
    }

    fclose(fp);

    printf("\nPositive words count: %d", count_pos);
    printf("\nNegative words count: %d", count_neg);
    printf("\nNeutral words count: %d", count_neu);

    if (count_pos > count_neg)
    {
        printf("\nThe text is positive!");
    }
    else if (count_pos < count_neg)
    {
        printf("\nThe text is negative!");
    }
    else
    {
        printf("\nThe text is neutral!");
    }

    return 0;
}