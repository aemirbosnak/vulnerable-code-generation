//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: multiplayer
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char sentence[1000];
    int positive=0, negative=0, neutral=0;

    printf("Enter a sentence: ");
    fgets(sentence,1000,stdin);
    sentence[strlen(sentence)-1] = '\0'; //removing the new-line character from the input string

    char *tokens = strtok(sentence," ");
    while(tokens!=NULL)
    {
        int found_positive=0, found_negative=0;
        char *word = tokens;
        //Checking for positive words
        char positive_words[5][20] = {"good","great","fantastic","excellent","awesome"};
        for(int i=0;i<5;i++)
        {
            if(strcmp(word,positive_words[i]) == 0)
            {
                positive++;
                found_positive=1;
                break;
            }
        }
        //Checking for negative words
        char negative_words[5][20] = {"bad","terrible","horrible","awful","poor"};
        for(int i=0;i<5;i++)
        {
            if(strcmp(word,negative_words[i]) == 0)
            {
                negative++;
                found_negative=1;
                break;
            }
        }
        //Haven't found either positive or negative words
        if(!found_positive && !found_negative)
            neutral++;

        //Get the next token
        tokens = strtok(NULL," ");
    }

    //Displaying the results
    printf("Sentiment Analysis Result: ");
    if(positive>negative && positive>neutral)
        printf("Positive\n");
    else if(negative>positive && negative>neutral)
        printf("Negative\n");
    else
        printf("Neutral\n");
    return 0;
}