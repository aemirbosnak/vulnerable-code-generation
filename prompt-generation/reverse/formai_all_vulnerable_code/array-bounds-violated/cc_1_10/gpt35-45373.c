//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: satisfied
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*function to count the number of positive, negative and neutral words*/
void countSentiment(char *sentence, int *positive, int *negative, int *neutral)
{
    char positiveWords[10][20] = {"good", "nice", "great", "excellent", "happy", "love", "awesome", "fantastic", "superb", "terrific"};
    char negativeWords[10][20] = {"bad", "terrible", "poor", "awful", "sad", "hate", "disgusting", "unpleasant", "unsatisfactory", "pathetic"};

    char *word;
    int pos_count = 0, neg_count = 0, neu_count = 0;

    /*tokenize the input sentence*/
    word = strtok(sentence, " ");
    while (word != NULL)
    {
        for(int i = 0; i < 10; i++)
        {
            if(strcmp(word, positiveWords[i]) == 0)
            {
                pos_count++;
                break;
            }
            else if(strcmp(word, negativeWords[i]) == 0)
            {
                neg_count++;
                break;
            }
        }
        word = strtok(NULL, " ");
    }

    /*calculate the final sentiment*/
    if(pos_count > neg_count)
    {
        *positive = pos_count;
    }
    else if(neg_count > pos_count)
    {
        *negative = neg_count;
    }
    else
    {
        *neutral = strlen(sentence) - (*positive + *negative);
    }
}

int main()
{
    char sentence[100];
    int positive = 0, negative = 0, neutral = 0;

    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);
    sentence[strlen(sentence)-1] = '\0';

    countSentiment(sentence, &positive, &negative, &neutral);

    printf("\nSentiment Analysis Report\n");
    printf("Positive Words: %d\n", positive);
    printf("Negative Words: %d\n", negative);
    printf("Neutral Words: %d\n", neutral);

    if(positive > negative)
    {
        printf("\nOverall Sentiment: Positive\n");
    }
    else if(negative > positive)
    {
        printf("\nOverall Sentiment: Negative\n");
    }
    else
    {
        printf("\nOverall Sentiment: Neutral\n");
    }

    return 0;
}