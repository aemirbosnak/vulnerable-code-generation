//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

// Function to split a sentence into words
void split_sentence(char* sentence, char** words) {
    int num_words = 0;
    char* word = strtok(sentence, " ");
    while (word!= NULL) {
        if (num_words >= MAX_WORDS) {
            printf("Error: Too many words in sentence.\n");
            exit(1);
        }
        words[num_words] = strdup(word);
        num_words++;
        word = strtok(NULL, " ");
    }
}

// Function to calculate the sentiment score of a word
double calculate_sentiment_score(char* word) {
    double score = 0;
    int length = strlen(word);
    for (int i = 0; i < length; i++) {
        if (isalpha(word[i])) {
            if (isupper(word[i])) {
                score += pow(2, length - i - 1);
            } else {
                score -= pow(2, length - i - 1);
            }
        }
    }
    return score;
}

// Function to calculate the overall sentiment score of a sentence
double calculate_sentiment(char** words, int num_words) {
    double score = 0;
    for (int i = 0; i < num_words; i++) {
        score += calculate_sentiment_score(words[i]);
    }
    return score;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Error: No sentence provided.\n");
        return 1;
    }

    char* sentence = argv[1];
    char** words = malloc(MAX_WORDS * sizeof(char*));

    split_sentence(sentence, words);

    double sentiment_score = calculate_sentiment(words, strlen(sentence));

    if (sentiment_score > 0) {
        printf("The sentiment of the sentence is positive.\n");
    } else if (sentiment_score < 0) {
        printf("The sentiment of the sentence is negative.\n");
    } else {
        printf("The sentiment of the sentence is neutral.\n");
    }

    free(words);
    return 0;
}