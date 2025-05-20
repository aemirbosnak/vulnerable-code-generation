//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment dictionary
struct sentiment_dict {
    char *word;
    int sentiment;
};

// Initialize the sentiment dictionary
struct sentiment_dict sentiment_dictionary[] = {
    {"good", 1},
    {"bad", -1},
    {"excellent", 2},
    {"terrible", -2},
    {"amazing", 3},
    {"awful", -3},
    {"great", 2},
    {"terrible", -2},
    {"wonderful", 3},
    {"horrible", -3}
};

// Get the sentiment score of a word
int get_sentiment_score(char *word) {
    for (int i = 0; i < sizeof(sentiment_dictionary) / sizeof(sentiment_dictionary[0]); i++) {
        if (strcmp(word, sentiment_dictionary[i].word) == 0) {
            return sentiment_dictionary[i].sentiment;
        }
    }

    return 0;
}

// Get the sentiment score of a sentence
int get_sentence_sentiment(char *sentence) {
    int sentiment_score = 0;
    char *word = strtok(sentence, " ");

    while (word != NULL) {
        sentiment_score += get_sentiment_score(word);
        word = strtok(NULL, " ");
    }

    return sentiment_score;
}

// Print the sentiment of a sentence
void print_sentiment(char *sentence) {
    int sentiment_score = get_sentence_sentiment(sentence);

    if (sentiment_score > 0) {
        printf("The sentence '%s' has a positive sentiment.\n", sentence);
    } else if (sentiment_score < 0) {
        printf("The sentence '%s' has a negative sentiment.\n", sentence);
    } else {
        printf("The sentence '%s' has a neutral sentiment.\n", sentence);
    }
}

int main() {
    // Get the sentence from the user
    char sentence[100];
    printf("Enter a sentence: ");
    scanf("%s", sentence);

    // Print the sentiment of the sentence
    print_sentiment(sentence);

    return 0;
}