//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// function to remove punctuation from given string and convert all characters to lower case
void preprocess(char* str)
{
    int len = strlen(str);

    // remove punctuation
    for(int i = 0; i < len; i++)
    {
        if(str[i] == ',' || str[i] == '.' || str[i] == '!' || str[i] == '?' || str[i] == ';')
        {
            for(int j = i; j < len - 1; j++)
            {
                str[j] = str[j+1];
            }
            str[len - 1] = '\0';
            len--;
        }
    }

    // convert to lower case
    for(int i = 0; i < len; i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] - 'A' + 'a';
        }
    }
}

// function to calculate sentiment score of a given sentence
double calculate_sentiment_score(char* sentence, char** pos_words, char** neg_words, int num_pos_words, int num_neg_words)
{
    double score = 0.0;

    // preprocess sentence
    preprocess(sentence);

    // split sentence into individual words
    char* token = strtok(sentence, " ");
    while(token != NULL)
    {
        // check if word is positive
        for(int i = 0; i < num_pos_words; i++)
        {
            if(strcmp(token, pos_words[i]) == 0)
            {
                score += 1.0;
                break;
            }
        }

        // check if word is negative
        for(int i = 0; i < num_neg_words; i++)
        {
            if(strcmp(token, neg_words[i]) == 0)
            {
                score -= 1.0;
                break;
            }
        }

        token = strtok(NULL, " ");
    }

    return score;
}

int main()
{
    char pos_words[][20] = {"good", "great", "excellent", "fantastic", "wonderful", "awesome", "nice", "amazing"};
    char neg_words[][20] = {"bad", "terrible", "poor", "awful", "horrible", "lousy", "disappointing"};

    int num_pos_words = sizeof(pos_words) / sizeof(pos_words[0]);
    int num_neg_words = sizeof(neg_words) / sizeof(neg_words[0]);

    char input[MAX_SIZE];

    printf("Enter a sentence to analyze sentiment: ");
    fgets(input, MAX_SIZE, stdin);
    input[strlen(input) - 1] = '\0';

    double score = calculate_sentiment_score(input, pos_words, neg_words, num_pos_words, num_neg_words);

    if(score > 0)
    {
        printf("Positive sentiment with score: %lf", score);
    }
    else if(score < 0)
    {
        printf("Negative sentiment with score: %lf", score);
    }
    else
    {
        printf("Neutral sentiment");
    }

    return 0;
}