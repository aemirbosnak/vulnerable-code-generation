//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_SENTENCES 100

// A struct to represent a word and its sentiment score.
typedef struct {
    char *word;
    int score;
} Word;

// A struct to represent a sentence and its sentiment score.
typedef struct {
    char *sentence;
    int score;
} Sentence;

// A global array of words and their sentiment scores.
Word words[MAX_WORDS];

// A global array of sentences and their sentiment scores.
Sentence sentences[MAX_SENTENCES];

// A function to load the words and their sentiment scores from a file.
void load_words(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    int num_words;
    fscanf(file, "%d\n", &num_words);

    for (int i = 0; i < num_words; i++) {
        char word[100];
        int score;
        fscanf(file, "%s %d\n", word, &score);

        words[i].word = strdup(word);
        words[i].score = score;
    }

    fclose(file);
}

// A function to load the sentences from a file.
void load_sentences(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    int num_sentences;
    fscanf(file, "%d\n", &num_sentences);

    for (int i = 0; i < num_sentences; i++) {
        char sentence[1000];
        fscanf(file, "%[^\n]\n", sentence);

        sentences[i].sentence = strdup(sentence);
        sentences[i].score = 0;
    }

    fclose(file);
}

// A function to calculate the sentiment score of a sentence.
int calculate_sentiment(const char *sentence) {
    int score = 0;

    // Tokenize the sentence into words.
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        // Find the word in the global array of words.
        for (int i = 0; i < MAX_WORDS; i++) {
            if (strcmp(token, words[i].word) == 0) {
                // Add the word's sentiment score to the sentence's score.
                score += words[i].score;
            }
        }

        // Get the next token.
        token = strtok(NULL, " ");
    }

    return score;
}

// A function to print the sentiment scores of the sentences.
void print_sentiment_scores() {
    for (int i = 0; i < MAX_SENTENCES; i++) {
        printf("%s: %d\n", sentences[i].sentence, sentences[i].score);
    }
}

// The main function.
int main() {
    // Load the words and their sentiment scores from a file.
    load_words("words.txt");

    // Load the sentences from a file.
    load_sentences("sentences.txt");

    // Calculate the sentiment score of each sentence.
    for (int i = 0; i < MAX_SENTENCES; i++) {
        sentences[i].score = calculate_sentiment(sentences[i].sentence);
    }

    // Print the sentiment scores of the sentences.
    print_sentiment_scores();

    return 0;
}