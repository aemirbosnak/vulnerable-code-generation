//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000

typedef struct {
    char *word;
    int count;
} WordFrequency;

void read_sentence(char *sentence) {
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
    sentence[strcspn(sentence, "\n")] = '\0';
}

void tokenize_sentence(char *sentence, char *words[], int max_words) {
    int num_words = 0;
    char *token = strtok(sentence, ",.?!;:");
    while (token!= NULL && num_words < max_words) {
        words[num_words] = token;
        num_words++;
        token = strtok(NULL, ",.?!;:");
    }
}

void count_word_frequencies(char *words[], int num_words, WordFrequency freq_table[], int max_freq_table_size) {
    int i, j;
    for (i = 0; i < num_words; i++) {
        for (j = 0; j < max_freq_table_size; j++) {
            if (freq_table[j].word == NULL || strcasecmp(freq_table[j].word, words[i])!= 0) {
                continue;
            }
            freq_table[j].count++;
            break;
        }
    }
}

void print_word_frequencies(WordFrequency freq_table[], int num_freq_table_entries) {
    int i;
    for (i = 0; i < num_freq_table_entries; i++) {
        if (freq_table[i].word!= NULL) {
            printf("%s: %d\n", freq_table[i].word, freq_table[i].count);
        }
    }
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    char words[MAX_WORD_LENGTH][MAX_WORD_LENGTH];
    WordFrequency freq_table[MAX_WORD_LENGTH];
    int max_freq_table_size = sizeof(freq_table) / sizeof(freq_table[0]);

    read_sentence(sentence);
    tokenize_sentence(sentence, words, MAX_WORD_LENGTH);
    count_word_frequencies(words, MAX_WORD_LENGTH, freq_table, max_freq_table_size);
    print_word_frequencies(freq_table, max_freq_table_size);

    return 0;
}