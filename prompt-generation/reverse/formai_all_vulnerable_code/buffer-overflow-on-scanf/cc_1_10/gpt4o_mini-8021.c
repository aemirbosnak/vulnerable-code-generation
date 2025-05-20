//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

struct WordFreq {
    char word[MAX_WORD_LEN];
    int count;
};

int find_word(struct WordFreq words[], int total_words, const char *word) {
    for (int i = 0; i < total_words; i++) {
        if (strcmp(words[i].word, word) == 0) {
            return i;
        }
    }
    return -1; // Not found
}

void sort_words(struct WordFreq words[], int total_words) {
    for (int i = 0; i < total_words - 1; i++) {
        for (int j = i + 1; j < total_words; j++) {
            if (strcmp(words[i].word, words[j].word) > 0) {
                struct WordFreq temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void print_word_frequencies(struct WordFreq words[], int total_words) {
    printf("Word Frequencies:\n");
    for (int i = 0; i < total_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    struct WordFreq words[MAX_WORDS];
    int total_words = 0;
    char word[MAX_WORD_LEN];
    
    printf("Enter text (end with EOF, Ctrl+D):\n");

    while (scanf("%s", word) != EOF) {
        // Remove punctuation and convert to lowercase
        int len = strlen(word);
        for (int i = 0; i < len; i++) {
            if (isalpha(word[i])) {
                word[i] = tolower(word[i]);
            } else {
                word[i] = '\0'; // replace with null terminator
            }
        }

        if (strlen(word) == 0) continue; // Skip empty word

        int index = find_word(words, total_words, word);
        if (index == -1) { // New word
            strncpy(words[total_words].word, word, MAX_WORD_LEN);
            words[total_words].count = 1;
            total_words++;
        } else { // Existing word
            words[index].count++;
        }
    }

    sort_words(words, total_words);
    print_word_frequencies(words, total_words);

    return 0;
}