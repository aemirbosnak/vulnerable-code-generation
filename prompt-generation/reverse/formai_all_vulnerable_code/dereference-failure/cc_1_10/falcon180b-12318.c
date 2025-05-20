//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

// Function to split a string into words
void split_string(char* str, char** words) {
    char* word = strtok(str, ",.!?;:");
    int count = 0;
    while (word!= NULL) {
        if (count >= MAX_WORDS) {
            break;
        }
        words[count] = word;
        count++;
        word = strtok(NULL, ",.!?;:");
    }
}

// Function to stem a word
char* stem_word(char* word) {
    char* stem = malloc(MAX_WORD_LENGTH * sizeof(char));
    int len = strlen(word);
    int i = 0;
    while (i < len) {
        if (isalpha(word[i])) {
            stem[i] = tolower(word[i]);
        }
        i++;
    }
    stem[i] = '\0';
    return stem;
}

// Function to calculate the sentiment score of a sentence
int calculate_sentiment_score(char* sentence) {
    int score = 0;
    char** words = malloc(MAX_WORDS * sizeof(char*));
    int num_words = 0;
    split_string(sentence, words);
    for (int i = 0; i < num_words; i++) {
        char* stemmed_word = stem_word(words[i]);
        if (strcmp(stemmed_word, "happy") == 0) {
            score += 1;
        } else if (strcmp(stemmed_word, "sad") == 0) {
            score -= 1;
        }
    }
    free(words);
    return score;
}

// Function to print the sentiment score
void print_sentiment_score(int score) {
    if (score > 0) {
        printf("The sentence is positive.\n");
    } else if (score < 0) {
        printf("The sentence is negative.\n");
    } else {
        printf("The sentence is neutral.\n");
    }
}

// Main function
int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <sentence>\n", argv[0]);
        return 1;
    }
    char* sentence = argv[1];
    int score = calculate_sentiment_score(sentence);
    print_sentiment_score(score);
    return 0;
}