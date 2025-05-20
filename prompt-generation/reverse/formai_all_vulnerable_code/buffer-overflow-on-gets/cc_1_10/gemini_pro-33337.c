//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment dictionary
char *sentiment_dictionary[] = {
    "amazing", "awesome", "brilliant", "cool", "excellent", "fantastic", "great", "incredible",
    "lovely", "marvelous", "outstanding", "perfect", "splendid", "superb", "terrific", "wonderful",
    "bad", "boring", "dreadful", "dull", "awful", "terrible", "ugly", "worthless",
    "sad", "depressed", "unhappy", "miserable", "depressing",
    "interesting", "curious", "fascinating", "intriguing", "mysterious",
    "beautiful", "charming", "elegant", "graceful", "handsome", "pretty",
    "delicious", "scrumptious", "yummy", "tasty", "mouthwatering",
    "clean", "fresh", "healthy", "pure", "sparkling",
    "comfortable", "cozy", "luxurious", "pleasant", "relaxing", "warm",
};

// Get the sentiment score of a word
int get_sentiment_score(char *word) {
    for (int i = 0; i < sizeof(sentiment_dictionary) / sizeof(char *); i++) {
        if (strcmp(word, sentiment_dictionary[i]) == 0) {
            return i >= sizeof(sentiment_dictionary) / sizeof(char *) / 2 ? 1 : -1;
        }
    }

    return 0;
}

// Get the sentiment score of a sentence
int get_sentence_sentiment_score(char *sentence) {
    int score = 0;
    char *token;

    token = strtok(sentence, " ");
    while (token != NULL) {
        score += get_sentiment_score(token);
        token = strtok(NULL, " ");
    }

    return score;
}

// Print the sentiment of a sentence
void print_sentence_sentiment(char *sentence) {
    int score = get_sentence_sentiment_score(sentence);

    if (score > 0) {
        printf("The sentence \"%s\" has a positive sentiment.\n", sentence);
    } else if (score < 0) {
        printf("The sentence \"%s\" has a negative sentiment.\n", sentence);
    } else {
        printf("The sentence \"%s\" has a neutral sentiment.\n", sentence);
    }
}

int main() {
    // Get the sentence from the user
    char sentence[100];
    printf("Enter a sentence: ");
    gets(sentence);

    // Print the sentiment of the sentence
    print_sentence_sentiment(sentence);

    return 0;
}