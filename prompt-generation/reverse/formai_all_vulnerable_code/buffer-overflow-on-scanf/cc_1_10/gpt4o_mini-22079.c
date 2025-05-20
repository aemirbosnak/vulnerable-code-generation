//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TWEETS 100
#define MAX_LEN 280
#define MAX_POS_WORDS 50
#define MAX_NEG_WORDS 50

// Structure to store tweet
typedef struct {
    char content[MAX_LEN];
} Tweet;

// Lists of positive and negative words
const char *positiveWords[MAX_POS_WORDS] = {"happy", "good", "great", "fantastic", "love", "excellent"};
const char *negativeWords[MAX_NEG_WORDS] = {"sad", "bad", "terrible", "hate", "awful", "poor"};

// Function declarations
void getTweets(Tweet tweets[], int numTweets);
int analyzeSentiment(const char *tweet);
void printSentiment(int score);

int main() {
    Tweet tweets[MAX_TWEETS];
    int numTweets, i, sentimentScore;

    printf("Enter the number of tweets you want to analyze (max %d): ", MAX_TWEETS);
    scanf("%d", &numTweets);
    getchar(); // Clear the newline character

    if (numTweets > MAX_TWEETS) {
        printf("Exceeded maximum number of tweets. Setting to %d.\n", MAX_TWEETS);
        numTweets = MAX_TWEETS;
    }

    getTweets(tweets, numTweets);

    for (i = 0; i < numTweets; i++) {
        printf("\nTweet %d: %s\n", i+1, tweets[i].content);
        sentimentScore = analyzeSentiment(tweets[i].content);
        printSentiment(sentimentScore);
    }

    return 0;
}

// Function to read tweets from user
void getTweets(Tweet tweets[], int numTweets) {
    for (int i = 0; i < numTweets; i++) {
        printf("Enter tweet %d: ", i + 1);
        fgets(tweets[i].content, MAX_LEN, stdin);
        tweets[i].content[strcspn(tweets[i].content, "\n")] = 0; // Remove newline
    }
}

// Function to analyze sentiment of the tweet
int analyzeSentiment(const char *tweet) {
    int positiveCount = 0, negativeCount = 0;
    char *token;
    char *tempTweet = strdup(tweet); // Duplicate tweet to avoid modifying original string
    
    // Convert to lowercase for comparison
    for (int i = 0; tempTweet[i]; i++) {
        tempTweet[i] = tolower(tempTweet[i]);
    }

    // Tokenize the tweet and count positive and negative words
    token = strtok(tempTweet, " ");
    while (token != NULL) {
        for (int j = 0; j < MAX_POS_WORDS; j++) {
            if (strcmp(token, positiveWords[j]) == 0) {
                positiveCount++;
            }
        }
        for (int k = 0; k < MAX_NEG_WORDS; k++) {
            if (strcmp(token, negativeWords[k]) == 0) {
                negativeCount++;
            }
        }
        token = strtok(NULL, " ");
    }

    free(tempTweet); // Free the duplicated memory
    return positiveCount - negativeCount; // Return net sentiment score
}

// Function to print sentiment analysis result
void printSentiment(int score) {
    if (score > 0) {
        printf("Sentiment: Positive (Score: %d)\n", score);
    } else if (score < 0) {
        printf("Sentiment: Negative (Score: %d)\n", score);
    } else {
        printf("Sentiment: Neutral (Score: %d)\n", score);
    }
}