//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50
#define MAX_SENTENCE_LENGTH 500

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void init_word_frequency(WordFrequency *word_frequency) {
    memset(word_frequency, 0, sizeof(WordFrequency));
}

void update_word_frequency(WordFrequency *word_frequency, const char *word) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(word_frequency[i].word, word) == 0) {
            word_frequency[i].count++;
            return;
        }
    }
    if (word_frequency->count >= MAX_WORDS) {
        printf("Error: Maximum number of words exceeded.\n");
        exit(1);
    }
    strcpy(word_frequency[word_frequency->count].word, word);
    word_frequency[word_frequency->count].count = 1;
    word_frequency->count++;
}

void print_word_frequency(const WordFrequency *word_frequency) {
    int i;
    for (i = 0; i < word_frequency->count; i++) {
        printf("%s: %d\n", word_frequency[i].word, word_frequency[i].count);
    }
}

int main() {
    FILE *input_file;
    char sentence[MAX_SENTENCE_LENGTH];
    char word[MAX_WORD_LENGTH];
    WordFrequency word_frequency;

    init_word_frequency(&word_frequency);

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Unable to open input file.\n");
        exit(1);
    }

    while (fgets(sentence, MAX_SENTENCE_LENGTH, input_file)!= NULL) {
        int i = 0;
        while (i < strlen(sentence)) {
            if (isalpha(sentence[i])) {
                strcpy(word, &sentence[i]);
                while (isalpha(sentence[i])) {
                    strcat(word, &sentence[i]);
                    i++;
                }
                update_word_frequency(&word_frequency, word);
            } else {
                i++;
            }
        }
    }

    fclose(input_file);

    print_word_frequency(&word_frequency);

    return 0;
}