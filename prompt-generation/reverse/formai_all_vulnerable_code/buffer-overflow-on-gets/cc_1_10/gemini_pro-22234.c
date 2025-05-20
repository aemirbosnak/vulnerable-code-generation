//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the possible sentiment values.
typedef enum {
    POSITIVE,
    NEGATIVE,
    NEUTRAL
} Sentiment;

// Define the maximum size of a word.
#define MAX_WORD_SIZE 256

// Define the maximum number of words in a sentence.
#define MAX_SENTENCE_SIZE 1024

// Define the maximum number of sentences in a text.
#define MAX_TEXT_SIZE 10240

// Function to get the sentiment of a word.
Sentiment get_word_sentiment(const char *word) {
    // Check if the word is positive.
    if (strcmp(word, "good") == 0 || strcmp(word, "great") == 0 || strcmp(word, "awesome") == 0) {
        return POSITIVE;
    }
    // Check if the word is negative.
    else if (strcmp(word, "bad") == 0 || strcmp(word, "terrible") == 0 || strcmp(word, "horrible") == 0) {
        return NEGATIVE;
    }
    // Otherwise, the word is neutral.
    else {
        return NEUTRAL;
    }
}

// Function to get the sentiment of a sentence.
Sentiment get_sentence_sentiment(const char *sentence) {
    // Split the sentence into words.
    char words[MAX_SENTENCE_SIZE][MAX_WORD_SIZE];
    int num_words = 0;
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        strcpy(words[num_words], word);
        num_words++;
        word = strtok(NULL, " ");
    }

    // Get the sentiment of each word.
    Sentiment sentiments[num_words];
    for (int i = 0; i < num_words; i++) {
        sentiments[i] = get_word_sentiment(words[i]);
    }

    // Get the overall sentiment of the sentence.
    Sentiment overall_sentiment = NEUTRAL;
    for (int i = 0; i < num_words; i++) {
        if (sentiments[i] == POSITIVE) {
            overall_sentiment = POSITIVE;
        } else if (sentiments[i] == NEGATIVE) {
            overall_sentiment = NEGATIVE;
        }
    }

    return overall_sentiment;
}

// Function to get the sentiment of a text.
Sentiment get_text_sentiment(const char *text) {
    // Split the text into sentences.
    char sentences[MAX_TEXT_SIZE][MAX_SENTENCE_SIZE];
    int num_sentences = 0;
    char *sentence = strtok(text, ".");
    while (sentence != NULL) {
        strcpy(sentences[num_sentences], sentence);
        num_sentences++;
        sentence = strtok(NULL, ".");
    }

    // Get the sentiment of each sentence.
    Sentiment sentiments[num_sentences];
    for (int i = 0; i < num_sentences; i++) {
        sentiments[i] = get_sentence_sentiment(sentences[i]);
    }

    // Get the overall sentiment of the text.
    Sentiment overall_sentiment = NEUTRAL;
    for (int i = 0; i < num_sentences; i++) {
        if (sentiments[i] == POSITIVE) {
            overall_sentiment = POSITIVE;
        } else if (sentiments[i] == NEGATIVE) {
            overall_sentiment = NEGATIVE;
        }
    }

    return overall_sentiment;
}

// Main function.
int main() {
    // Get the text from the user.
    char text[MAX_TEXT_SIZE];
    printf("Enter the text: ");
    gets(text);

    // Get the sentiment of the text.
    Sentiment sentiment = get_text_sentiment(text);

    // Print the sentiment of the text.
    switch (sentiment) {
        case POSITIVE:
            printf("The text is positive.\n");
            break;
        case NEGATIVE:
            printf("The text is negative.\n");
            break;
        case NEUTRAL:
            printf("The text is neutral.\n");
            break;
    }

    return 0;
}