//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} word_t;

word_t words[MAX_WORDS];
int num_words = 0;

void add_word(char *word) {
    if (num_words >= MAX_WORDS) {
        printf("Error: too many words\n");
        exit(1);
    }
    strcpy(words[num_words].word, word);
    words[num_words].is_correct = true;
    num_words++;
}

bool is_correct_word(char *word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(word, words[i].word) == 0) {
            return words[i].is_correct;
        }
    }
    return false;
}

void suggest_corrections(char *word) {
    char *corrected_word;
    int i, j, k;
    bool found_corrections = false;

    for (i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) {
            continue;
        }
        for (j = i + 1; j < strlen(word); j++) {
            if (!isalpha(word[j])) {
                break;
            }
            corrected_word = (char *)malloc(strlen(word) + 1);
            strcpy(corrected_word, word);
            corrected_word[i] = toupper(word[i]);
            corrected_word[j] = toupper(word[j]);
            corrected_word[j + 1] = '\0';
            if (is_correct_word(corrected_word)) {
                printf("Did you mean: %s\n", corrected_word);
                found_corrections = true;
                break;
            }
            free(corrected_word);
        }
        if (found_corrections) {
            break;
        }
    }
}

int main(int argc, char **argv) {
    char *word;
    int i;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        return 1;
    }

    while (fscanf(file, "%s", word) == 1) {
        if (isalpha(word[0])) {
            add_word(word);
        }
    }

    fclose(file);

    if (num_words == 0) {
        printf("No words found in dictionary\n");
        return 1;
    }

    while (scanf("%s", word) == 1) {
        if (isalpha(word[0])) {
            if (is_correct_word(word)) {
                printf("Correct\n");
            } else {
                suggest_corrections(word);
            }
        }
    }

    return 0;
}