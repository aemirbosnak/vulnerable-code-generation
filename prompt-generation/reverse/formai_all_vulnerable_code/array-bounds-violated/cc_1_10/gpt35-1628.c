//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to calculate the sentiment score
int calculate_sentiment_score(char* tweet) {
    int score = 0;
    int len = strlen(tweet);

    // list of positive and negative words
    char* positive_words[] = {"good", "great", "awesome", "love", "happy"};
    char* negative_words[] = {"bad", "terrible", "awful", "hate", "sad"};

    // loop through each word in the tweet
    char* word = strtok(tweet, " ");
    while (word != NULL) {
        // check if the word is a positive or negative word
        for (int i = 0; i < 5; i++) {
            if (strcmp(word, positive_words[i]) == 0) {
                score++;
            }
            else if (strcmp(word, negative_words[i]) == 0) {
                score--;
            }
        }
        word = strtok(NULL, " ");
    }

    // return the sentiment score
    return score;
}

int main() {
    char tweet[100];
    printf("Enter a tweet: ");
    fgets(tweet, 100, stdin);

    // remove the newline character from the end of the tweet
    int len = strlen(tweet);
    if (tweet[len-1] == '\n') {
        tweet[len-1] = '\0';
    }

    // get the sentiment score of the tweet
    int sentiment_score = calculate_sentiment_score(tweet);

    // print the sentiment score of the tweet
    if (sentiment_score > 0) {
        printf("The sentiment score of the tweet is positive.\n");
    }
    else if (sentiment_score < 0) {
        printf("The sentiment score of the tweet is negative.\n");
    }
    else {
        printf("The sentiment score of the tweet is neutral.\n");
    }

    return 0;
}