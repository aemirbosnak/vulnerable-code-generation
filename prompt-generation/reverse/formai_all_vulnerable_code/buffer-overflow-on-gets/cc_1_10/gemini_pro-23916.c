//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Define the maximum number of words in a sentence
#define MAX_WORDS_IN_SENTENCE 100

// Define the maximum number of sentences in a text
#define MAX_SENTENCES_IN_TEXT 100

// Define the number of sentiment scores
#define NUM_SENTIMENT_SCORES 3

// Define the sentiment scores
char *sentiment_scores[] = {"negative", "neutral", "positive"};

// Define the word list
char *word_list[] = {
    "bad", "terrible", "awful", "worst", "horrible", "negative",
    "good", "great", "excellent", "best", "positive",
    "okay", "alright", "fine", "neutral",
};

// Define the word weights
float word_weights[] = {
    -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
    1.0, 1.0, 1.0, 1.0, 1.0,
    0.0, 0.0, 0.0, 0.0,
};

// Get the sentiment score of a word
float get_word_sentiment_score(char *word) {
    for (int i = 0; i < sizeof(word_list) / sizeof(char *); i++) {
        if (strcmp(word, word_list[i]) == 0) {
            return word_weights[i];
        }
    }

    return 0.0;
}

// Get the sentiment score of a sentence
float get_sentence_sentiment_score(char *sentence) {
    char *words[MAX_WORDS_IN_SENTENCE];
    int num_words = 0;

    // Tokenize the sentence
    char *token = strtok(sentence, " ");
    while (token != NULL && num_words < MAX_WORDS_IN_SENTENCE) {
        words[num_words++] = token;
        token = strtok(NULL, " ");
    }

    // Calculate the sentiment score
    float sentiment_score = 0.0;
    for (int i = 0; i < num_words; i++) {
        sentiment_score += get_word_sentiment_score(words[i]);
    }

    return sentiment_score;
}

// Get the sentiment score of a text
float get_text_sentiment_score(char *text) {
    char *sentences[MAX_SENTENCES_IN_TEXT];
    int num_sentences = 0;

    // Tokenize the text
    char *token = strtok(text, ".");
    while (token != NULL && num_sentences < MAX_SENTENCES_IN_TEXT) {
        sentences[num_sentences++] = token;
        token = strtok(NULL, ".");
    }

    // Calculate the sentiment score
    float sentiment_score = 0.0;
    for (int i = 0; i < num_sentences; i++) {
        sentiment_score += get_sentence_sentiment_score(sentences[i]);
    }

    return sentiment_score;
}

int main() {
    // Get the text from the user
    char text[1000];
    printf("Enter the text: ");
    gets(text);

    // Get the sentiment score of the text
    float sentiment_score = get_text_sentiment_score(text);

    // Print the sentiment score
    printf("The sentiment score is: %.2f\n", sentiment_score);

    // Determine the sentiment
    char *sentiment;
    if (sentiment_score < 0.0) {
        sentiment = sentiment_scores[0];
    } else if (sentiment_score > 0.0) {
        sentiment = sentiment_scores[2];
    } else {
        sentiment = sentiment_scores[1];
    }

    // Print the sentiment
    printf("The sentiment is: %s\n", sentiment);

    return 0;
}