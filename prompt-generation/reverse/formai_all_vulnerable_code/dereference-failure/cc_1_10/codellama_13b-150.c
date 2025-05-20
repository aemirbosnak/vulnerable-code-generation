//Code Llama-13B DATASET v1.0 Category: Spam Detection System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void sort_words(WordFrequency* words, int num_words) {
    for (int i = 0; i < num_words - 1; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (words[i].frequency > words[j].frequency) {
                WordFrequency temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    int num_words;
    scanf("%s", sentence);
    num_words = 0;
    for (int i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] == ' ') {
            num_words++;
        }
    }
    num_words++;
    WordFrequency* words = malloc(num_words * sizeof(WordFrequency));
    int word_idx = 0;
    for (int i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] == ' ') {
            words[word_idx].frequency = 1;
            word_idx++;
        } else {
            words[word_idx].frequency++;
        }
    }
    sort_words(words, num_words);
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
    return 0;
}