//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LENGTH 1024
#define CHAR_COUNT 256

void tokenize(char *text);
void remove_punctuation(char *text);
void remove_stopwords(char *text);
void stem_words(char *text);
void print_word_frequency(char *text);

int main() {
    char text[MAX_LENGTH];
    gets(text); // Read input text from user

    tokenize(text); // Tokenize text into individual words
    remove_punctuation(text); // Remove punctuation from text
    remove_stopwords(text); // Remove stopwords from text
    stem_words(text); // Stem words to their base form
    print_word_frequency(text); // Print word frequency distribution

    return 0;
}

void tokenize(char *text) {
    char *token = strtok(text, " "); // Tokenize text using space as delimiter
    while (token != NULL) {
        printf("%s ", token); // Print each token
        token = strtok(NULL, " "); // Get next token
    }
    printf("\n"); // Print a newline to separate tokens
}

void remove_punctuation(char *text) {
    char *p = strtok(text, "!");// Remove punctuation using a array of punctuation characters
    while (p != NULL) {
        *p = '\0'; // Replace punctuation with null character
        p = strtok(NULL, "!"); // Get next punctuation character
    }
}

void remove_stopwords(char *text) {
    char *word = strtok(text, " "); // Tokenize text using space as delimiter
    while (word != NULL) {
        if (strchr("their there they're", word[0]) != NULL) { // Check if word is a stopword
            *word = '\0'; // Replace stopword with null character
        }
        word = strtok(NULL, " "); // Get next word
    }
}

void stem_words(char *text) {
    char *word = strtok(text, " "); // Tokenize text using space as delimiter
    while (word != NULL) {
        if (strchr("tth", word[0]) != NULL) { // Check if word is a stem word
            word[0] = 'e'; // Stem word to its base form
        }
        word = strtok(NULL, " "); // Get next word
    }
}

void print_word_frequency(char *text) {
    char *word = strtok(text, " "); // Tokenize text using space as delimiter
    int frequency = 0;
    while (word != NULL) {
        frequency++; // Increment word frequency
        word = strtok(NULL, " "); // Get next word
    }
    printf("%d\n", frequency); // Print word frequency distribution
}