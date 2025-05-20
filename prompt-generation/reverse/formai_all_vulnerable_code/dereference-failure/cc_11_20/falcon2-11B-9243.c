//Falcon2-11B DATASET v1.0 Category: Sentiment analysis tool ; Style: scientific
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <text file>\n", argv[0]);
        return 1;
    }

    char text[100];
    FILE *fp;
    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    int i, n, sum = 0, pos = 0, neg = 0;
    char *sentence = (char*)malloc(100 * sizeof(char));
    while (fscanf(fp, "%s", sentence) == 1)
    {
        n = strlen(sentence);
        for (i = 0; i < n; i++)
        {
            if (isupper(sentence[i]))
            {
                sum += 1;
            }
            else if (isdigit(sentence[i]))
            {
                pos += 1;
            }
            else if (isalpha(sentence[i]) && sentence[i]!= '_')
            {
                neg += 1;
            }
        }
    }

    if (pos > neg && pos > sum / 2)
    {
        printf("Positive sentiment.\n");
    }
    else if (neg > pos && neg > sum / 2)
    {
        printf("Negative sentiment.\n");
    }
    else
    {
        printf("Neutral sentiment.\n");
    }

    fclose(fp);
    return 0;
}