//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void read_sentence(char sentence[]) {
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
    sentence[strcspn(sentence, "\n")] = '\0'; // remove newline character
}

void tokenize_sentence(char sentence[], char words[], int max_words) {
    int i = 0;
    char *token = strtok(sentence, ",.?!;:");
    while (token!= NULL && i < max_words) {
        strcpy(words[i], token);
        i++;
        token = strtok(NULL, ",.?!;:");
    }
}

void count_word_frequencies(char words[], int num_words, WordFrequency freq_table[]) {
    for (int i = 0; i < num_words; i++) {
        char *word = words[i];
        int word_length = strlen(word);
        if (word_length > MAX_WORD_LENGTH) {
            printf("Error: Word '%s' is too long.\n", word);
            exit(1);
        }
        strcpy(freq_table[i].word, word);
        freq_table[i].count = 1;
    }
}

void print_word_frequencies(WordFrequency freq_table[], int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", freq_table[i].word, freq_table[i].count);
    }
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    char words[MAX_WORD_LENGTH][MAX_WORD_LENGTH];
    WordFrequency freq_table[MAX_WORD_LENGTH];

    read_sentence(sentence);
    tokenize_sentence(sentence, words, MAX_WORD_LENGTH);
    count_word_frequencies(words, strlen(sentence), freq_table);
    print_word_frequencies(freq_table, strlen(sentence));

    return 0;
}