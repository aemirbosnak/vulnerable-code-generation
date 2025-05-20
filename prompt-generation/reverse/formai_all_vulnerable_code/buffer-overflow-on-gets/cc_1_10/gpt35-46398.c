//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: expert-level
#include <stdio.h>
#include <string.h>

//Function to determine sentiment value of a word
int wordSentimentValue(char *word) {
    int sentiment = 0;
    char *positive_words[] = {"good", "happy", "awesome", "love", "excited"};
    char *negative_words[] = {"bad", "sad", "terrible", "hate", "disappointed"};
    int positive_word_count = sizeof(positive_words)/sizeof(char*);
    int negative_word_count = sizeof(negative_words)/sizeof(char*);
    
    for(int i=0; i<positive_word_count; i++) {
        if(strcmp(word, positive_words[i]) == 0) {
            sentiment = 1;
            break;
        }
    }
    
    if(sentiment != 1) {
        for(int i=0; i<negative_word_count; i++) {
            if(strcmp(word, negative_words[i]) == 0) {
                sentiment = -1;
                break;
            }
        }
    }
    
    return sentiment;
}

//Function to determine the sentiment score of a sentence
int sentenceSentimentScore(char *sentence) {
    char *word_token = strtok(sentence, " ");
    int sentiment_score = 0;
    
    while(word_token != NULL) {
        sentiment_score += wordSentimentValue(word_token);
        word_token = strtok(NULL, " ");
    }
    
    return sentiment_score;
}

int main() {
    char text[200];
    printf("Enter a sentence: ");
    gets(text);
    
    int sentiment_score = sentenceSentimentScore(text);
    
    if(sentiment_score > 0) {
        printf("Positive Sentiment");
    } else if (sentiment_score < 0) {
        printf("Negative Sentiment");
    } else {
        printf("Neutral Sentiment");
    }
    
    return 0;
}