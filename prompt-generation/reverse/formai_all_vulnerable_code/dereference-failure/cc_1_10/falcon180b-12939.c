//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void initialize_word_counts(WordCount *word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        word_counts[i].count = 0;
    }
}

void update_word_count(WordCount *word_counts, const char *word) {
    int word_length = strlen(word);
    if (word_length > MAX_WORD_LENGTH) {
        return;
    }
    char *lowercase_word = malloc(MAX_WORD_LENGTH);
    strcpy(lowercase_word, word);
    for (int i = 0; i < word_length; i++) {
        lowercase_word[i] = tolower(lowercase_word[i]);
    }
    int index = hash(lowercase_word);
    WordCount *word_count = &word_counts[index];
    word_count->count++;
}

int hash(const char *word) {
    int hash_value = 0;
    for (int i = 0; i < strlen(word); i++) {
        hash_value += tolower(word[i]);
    }
    return hash_value % MAX_NUM_WORDS;
}

void print_word_counts(const WordCount *word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        if (word_counts[i].count > 0) {
            printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
        }
    }
}

int main() {
    int num_words;
    scanf("%d", &num_words);
    char **words = malloc(num_words * sizeof(char *));
    for (int i = 0; i < num_words; i++) {
        words[i] = malloc(MAX_WORD_LENGTH);
        scanf("%s", words[i]);
    }
    WordCount word_counts[MAX_NUM_WORDS];
    initialize_word_counts(word_counts, num_words);
    for (int i = 0; i < num_words; i++) {
        update_word_count(word_counts, words[i]);
    }
    print_word_counts(word_counts, num_words);
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }
    free(words);
    return 0;
}