//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    // Sentiment analysis tool
    
    int posCount=0, negCount=0, neutralCount=0, totalWords=0;
    float posPerc, negPerc, neutralPerc, totalPerc;
    char review[1000];
    
    printf("Enter your review:\n");
    gets(review);
    
    // Converting whole string to lowercase
    for(int i=0; i<strlen(review); i++)
    {
        review[i] = tolower(review[i]);
    }
    
    // Tokenizing the string by space
    char *token = strtok(review, " ");
    
    while(token != NULL)
    {
        totalWords++;   // Counting the total number of words
        
        if(strcmp(token, "good")==0 || strcmp(token, "excellent")==0 || strcmp(token, "awesome")==0)
            posCount++; // Counting the number of positive words
        
        else if(strcmp(token, "bad")==0 || strcmp(token, "worst")==0 || strcmp(token, "awful")==0)
            negCount++; // Counting the number of negative words
        
        else
            neutralCount++; // Counting the number of neutral words
            
        token = strtok(NULL, " ");
    }
    
    // Calculating the percentages of positive, negative and neutral words
    posPerc = ((float)posCount/totalWords)*100;
    negPerc = ((float)negCount/totalWords)*100;
    neutralPerc = ((float)neutralCount/totalWords)*100;
    
    // Calculating the overall sentiment percentage
    totalPerc = ((float)(posCount-negCount)/totalWords)*100;
    
    printf("The analysis of your review is as follows:\n");
    printf("Total words: %d\n", totalWords);
    printf("Positive words: %d (%.2f%%)\n", posCount, posPerc);
    printf("Negative words: %d (%.2f%%)\n", negCount, negPerc);
    printf("Neutral words: %d (%.2f%%)\n", neutralCount, neutralPerc);
    
    if(totalPerc>0)
        printf("Overall sentiment is positive with a percentage of %.2f%%.\n", totalPerc);
    else if(totalPerc<0)
        printf("Overall sentiment is negative with a percentage of %.2f%%.\n", -totalPerc);
    else
        printf("Overall sentiment is neutral.\n");
    
    return 0;
}