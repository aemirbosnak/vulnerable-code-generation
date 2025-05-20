//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sentiment scores for each word
typedef struct Sentiment {
    char *word;
    int score;
} Sentiment;

// List of sentiment words
Sentiment sentiment_list[] = {
    {"great", 1}, {"super", 1}, {"awesome", 1},
    {"bad", -1}, {"terrible", -1}, {"awful", -1}
};

// Get the sentiment score of a string
int get_sentiment(char *str) {
    int score = 0;
    char *word;

    // Tokenize the string
    word = strtok(str, " ");
    while (word != NULL) {
        // Find the word in the sentiment list
        for (int i = 0; i < sizeof(sentiment_list) / sizeof(Sentiment); i++) {
            if (strcmp(word, sentiment_list[i].word) == 0) {
                // Add the sentiment score to the total
                score += sentiment_list[i].score;
            }
        }

        // Get the next word
        word = strtok(NULL, " ");
    }

    return score;
}

// Print the sentiment analysis of a string
void print_sentiment(char *str) {
    int score = get_sentiment(str);

    if (score > 0) {
        printf("The sentiment of \"%s\" is positive.\n", str);
    } else if (score < 0) {
        printf("The sentiment of \"%s\" is negative.\n", str);
    } else {
        printf("The sentiment of \"%s\" is neutral.\n", str);
    }
}

int main() {
    // Get the input string
    char str[100];
    printf("Enter a string: ");
    gets(str);

    // Print the sentiment analysis
    print_sentiment(str);

    return 0;
}