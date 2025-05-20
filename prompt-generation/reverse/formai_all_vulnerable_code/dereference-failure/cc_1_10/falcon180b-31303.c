//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_WORDS_PER_SENTENCE 50

// Function to split a sentence into words
void split_sentence(char* sentence, char** words) {
    char* word = strtok(sentence, " ");
    int word_count = 0;

    while (word!= NULL) {
        if (word_count >= MAX_WORDS_PER_SENTENCE) {
            break;
        }

        words[word_count] = strdup(word);
        word_count++;

        word = strtok(NULL, " ");
    }
}

// Function to calculate the sentiment of a word
int calculate_sentiment(char* word) {
    if (strcmp(word, "happy") == 0 || strcmp(word, "joy") == 0 || strcmp(word, "love") == 0) {
        return 1;
    } else if (strcmp(word, "sad") == 0 || strcmp(word, "angry") == 0 || strcmp(word, "hate") == 0) {
        return -1;
    } else {
        return 0;
    }
}

// Function to calculate the overall sentiment of a sentence
int calculate_sentiment_score(char** words, int word_count) {
    int score = 0;

    for (int i = 0; i < word_count; i++) {
        score += calculate_sentiment(words[i]);
    }

    return score;
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    char* words[MAX_WORDS_PER_SENTENCE];

    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    split_sentence(sentence, words);

    int word_count = 0;
    while (words[word_count]!= NULL) {
        word_count++;
    }

    int sentiment_score = calculate_sentiment_score(words, word_count);

    if (sentiment_score > 0) {
        printf("The sentence has a positive sentiment.\n");
    } else if (sentiment_score < 0) {
        printf("The sentence has a negative sentiment.\n");
    } else {
        printf("The sentence has a neutral sentiment.\n");
    }

    return 0;
}