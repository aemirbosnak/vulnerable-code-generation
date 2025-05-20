//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to determine sentiment score
int analyze_sentiment(char* text) {
    int score = 0;
    char word[50];

    // open sentiment lexicon file
    FILE *lexicon = fopen("sentiment_lexicon.txt", "r");
    if (lexicon == NULL) {
        printf("Error opening sentiment lexicon file.\n");
        exit(1);
    }

    while (fscanf(lexicon, "%s %d", word, &score) != EOF) {
        // check if word appears in text
        if (strstr(text, word) != NULL) {
            // adjust sentiment score based on word's polarity
            if (score == 1) {
                score += 1;
            } else if (score == -1) {
                score -= 1;
            }
        }
    }

    // close sentiment lexicon file
    fclose(lexicon);

    return score;
}

int main() {
    char input[100];
    int sentiment_score;

    // get user input
    printf("Enter text to analyze sentiment: ");
    scanf("%[^\n]", input);

    // analyze sentiment
    sentiment_score = analyze_sentiment(input);

    // print sentiment analysis result
    if (sentiment_score > 0) {
        printf("Positive sentiment detected with a score of %d.\n", sentiment_score);
    } else if (sentiment_score < 0) {
        printf("Negative sentiment detected with a score of %d.\n", sentiment_score);
    } else {
        printf("Neutral sentiment detected.\n");
    }

    return 0;
}