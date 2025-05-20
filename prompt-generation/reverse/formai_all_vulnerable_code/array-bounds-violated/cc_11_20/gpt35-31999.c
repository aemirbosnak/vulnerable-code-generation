//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[1000];
    int positive_count = 0;
    int negative_count = 0;
    int neutral_count = 0;
    
    printf("Enter a sentence: ");
    fgets(input, 1000, stdin);
    
    int len = strlen(input);
    if (input[len-1] == '\n')
    {
        input[len-1] = '\0';
    }
    
    char *token = strtok(input, " ");
    while (token != NULL)
    {
        if (strcmp(token, "good") == 0 || strcmp(token, "happy") == 0 || strcmp(token, "excellent") == 0)
        {
            positive_count++;
        }
        else if (strcmp(token, "bad") == 0 || strcmp(token, "sad") == 0 || strcmp(token, "terrible") == 0)
        {
            negative_count++;
        }
        else
        {
            neutral_count++;
        }
        token = strtok(NULL, " ");
    }
    
    if (positive_count > negative_count && positive_count > neutral_count)
    {
        printf("\nSentiment Analysis: Positive");
    }
    else if (negative_count > positive_count && negative_count > neutral_count)
    {
        printf("\nSentiment Analysis: Negative");
    }
    else
    {
        printf("\nSentiment Analysis: Neutral");
    }
    
    return 0;
}