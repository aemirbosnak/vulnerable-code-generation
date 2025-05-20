//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 1000
#define MAX_WORDS 10000

// Function to remove punctuation from a string
void remove_punctuation(char* str) {
    int i, j;
    for (i = 0, j = 0; str[i]!= '\0'; i++) {
        if (!ispunct(str[i])) {
            str[j++] = tolower(str[i]);
        }
    }
    str[j] = '\0';
}

// Function to split a string into sentences
int split_sentences(char* text, char* sentences[]) {
    char* sentence = strtok(text, ".");
    int count = 0;
    while (sentence!= NULL) {
        sentences[count] = sentence;
        count++;
        sentence = strtok(NULL, ".");
    }
    return count;
}

// Function to split a sentence into words
int split_words(char* sentence, char* words[]) {
    char* word = strtok(sentence, " ");
    int count = 0;
    while (word!= NULL) {
        words[count] = word;
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

// Function to generate a summary
void generate_summary(char* text, int num_sentences) {
    char* sentences[MAX_SENTENCES];
    int num_sentences_found = split_sentences(text, sentences);
    if (num_sentences_found < num_sentences) {
        printf("Not enough sentences found in text.\n");
        return;
    }

    int i, j;
    for (i = 0; i < num_sentences; i++) {
        int num_words_found = split_words(sentences[i], sentences[i]);
        if (num_words_found == 0) {
            continue;
        }

        for (j = 0; j < num_words_found; j++) {
            printf("%s ", sentences[i]);
        }
        printf("\n");
    }
}

int main() {
    char text[MAX_SENTENCE_LENGTH];
    printf("Enter text to summarize: ");
    fgets(text, MAX_SENTENCE_LENGTH, stdin);

    int num_sentences;
    printf("Enter number of sentences to summarize: ");
    scanf("%d", &num_sentences);

    remove_punctuation(text);
    generate_summary(text, num_sentences);

    return 0;
}