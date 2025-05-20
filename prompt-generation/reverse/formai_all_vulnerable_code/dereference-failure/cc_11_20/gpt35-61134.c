//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tweet{
    char message[280];
    int sentimentScore;
};

int main(){
    int numTweets;
    printf("How many tweets do you want to analyze? ");
    scanf("%d", &numTweets);

    // create an array of tweet structs
    struct tweet* tweets = (struct tweet*)malloc(numTweets * sizeof(struct tweet));

    // loop through each tweet and get message
    for(int i = 0; i < numTweets; i++){
        printf("Enter tweet message %d: ", i+1);
        scanf(" %[^\n]", tweets[i].message);
        tweets[i].sentimentScore = 0; // initialize sentiment score to 0
    }

    // perform sentiment analysis on each tweet
    for(int i = 0; i < numTweets; i++){
        char delimiter[]=" ";
        char *word = strtok(tweets[i].message, delimiter);

        while(word != NULL){
            if(strcmp(word, "happy") == 0 || strcmp(word, "joyful") == 0 || strcmp(word, "excited") == 0){
                tweets[i].sentimentScore += 2;
            }
            else if(strcmp(word, "sad") == 0 || strcmp(word, "disappointed") == 0 || strcmp(word, "depressed") == 0){
                tweets[i].sentimentScore -= 2;
            }
            word = strtok(NULL, delimiter);
        }
    }

    // print out the sentiment score for each tweet
    for(int i = 0; i < numTweets; i++){
        printf("Tweet %d has a sentiment score of %d\n", i+1, tweets[i].sentimentScore);
    }

    // free memory used for tweet array
    free(tweets);

    return 0;
}