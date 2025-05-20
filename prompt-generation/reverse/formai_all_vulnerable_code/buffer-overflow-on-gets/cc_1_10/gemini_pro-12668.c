//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCES 100
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

// Function to read the input text from the user
char *read_text() {
    char *text = malloc(sizeof(char) * 1000);
    printf("Enter the text to be summarized: ");
    gets(text);
    return text;
}

// Function to tokenize the input text into sentences
char **tokenize_sentences(char *text) {
    char **sentences = malloc(sizeof(char *) * MAX_SENTENCES);
    int num_sentences = 0;
    char *sentence = strtok(text, ".");
    while (sentence != NULL) {
        sentences[num_sentences++] = sentence;
        sentence = strtok(NULL, ".");
    }
    return sentences;
}

// Function to tokenize each sentence into words
char ***tokenize_words(char **sentences, int num_sentences) {
    char ***words = malloc(sizeof(char **) * num_sentences);
    for (int i = 0; i < num_sentences; i++) {
        words[i] = malloc(sizeof(char *) * MAX_WORDS);
        int num_words = 0;
        char *word = strtok(sentences[i], " ");
        while (word != NULL) {
            words[i][num_words++] = word;
            word = strtok(NULL, " ");
        }
    }
    return words;
}

// Function to calculate the frequency of each word in the text
int *calculate_word_frequency(char ***words, int num_sentences, int num_words) {
    int *word_frequency = malloc(sizeof(int) * num_words);
    for (int i = 0; i < num_words; i++) {
        word_frequency[i] = 0;
    }
    for (int i = 0; i < num_sentences; i++) {
        for (int j = 0; j < num_words; j++) {
            word_frequency[j]++;
        }
    }
    return word_frequency;
}

// Function to identify the top N frequent words in the text
char **identify_top_words(int *word_frequency, char **words, int num_words, int num_top_words) {
    char **top_words = malloc(sizeof(char *) * num_top_words);
    for (int i = 0; i < num_top_words; i++) {
        int max_frequency = -1;
        int max_index = -1;
        for (int j = 0; j < num_words; j++) {
            if (word_frequency[j] > max_frequency) {
                max_frequency = word_frequency[j];
                max_index = j;
            }
        }
        top_words[i] = words[max_index];
        word_frequency[max_index] = -1;
    }
    return top_words;
}

// Function to generate the summary of the text
char *generate_summary(char **top_words, int num_top_words) {
    char *summary = malloc(sizeof(char) * 1000);
    strcpy(summary, "Summary: ");
    for (int i = 0; i < num_top_words; i++) {
        strcat(summary, top_words[i]);
        strcat(summary, " ");
    }
    return summary;
}

// Function to print the summary of the text
void print_summary(char *summary) {
    printf("%s", summary);
}

// Main function
int main() {
    char *text = read_text();
    char **sentences = tokenize_sentences(text);
    char ***words = tokenize_words(sentences, strlen(sentences));
    int *word_frequency = calculate_word_frequency(words, strlen(sentences), strlen(words));
    char **top_words = identify_top_words(word_frequency, words, strlen(words), 5);
    char *summary = generate_summary(top_words, 5);
    print_summary(summary);
    return 0;
}