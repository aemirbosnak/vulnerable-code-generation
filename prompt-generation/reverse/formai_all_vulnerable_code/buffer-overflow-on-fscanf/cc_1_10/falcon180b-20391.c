//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

bool is_word_separator(char c) {
    return isspace(c) || c == '.' || c == ',' || c == ';' || c == ':' || c == '!' || c == '?' || c == '-' || c == '_' || c == '"' || c == '\'';
}

void remove_punctuation(char* word) {
    int i = 0;
    while (word[i]) {
        if (!is_word_separator(word[i])) {
            word[i] = tolower(word[i]);
        }
        i++;
    }
}

int main() {
    FILE* file = fopen("input.txt", "r");
    if (!file) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    struct word_count* word_counts = malloc(MAX_WORDS * sizeof(struct word_count));
    int num_words = 0;

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        remove_punctuation(word);
        for (int i = 0; i < num_words; i++) {
            if (strcmp(word, word_counts[i].word) == 0) {
                word_counts[i].count++;
                break;
            }
        }
        if (num_words >= MAX_WORDS) {
            printf("Error: Too many words.\n");
            fclose(file);
            free(word_counts);
            return 1;
        }
        strcpy(word_counts[num_words].word, word);
        word_counts[num_words].count = 1;
        num_words++;
    }

    fclose(file);

    printf("Word\tCount\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", word_counts[i].word, word_counts[i].count);
    }

    free(word_counts);
    return 0;
}