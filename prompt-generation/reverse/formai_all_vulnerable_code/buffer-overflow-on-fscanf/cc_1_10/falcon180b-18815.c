//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

struct word {
    char word[MAX_WORD_LEN];
    bool is_correct;
};

void load_words(FILE *file, struct word *words) {
    int count = 0;
    while (fscanf(file, "%s", words[count].word) == 1 && count < MAX_WORDS) {
        count++;
    }
    for (int i = 0; i < count; i++) {
        words[i].is_correct = true;
    }
}

void check_word(char *word, struct word *words) {
    int len = strlen(word);
    if (len > MAX_WORD_LEN) {
        return;
    }
    bool all_lower = true;
    for (int i = 0; i < len; i++) {
        if (!isalpha(word[i])) {
            return;
        }
        if (isupper(word[i])) {
            all_lower = false;
        }
    }
    if (all_lower) {
        for (int i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].is_correct = false;
            }
        }
    }
}

void print_errors(FILE *file, struct word *words) {
    fprintf(file, "Spelling errors:\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        if (!words[i].is_correct) {
            fprintf(file, "%s\n", words[i].word);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }
    struct word words[MAX_WORDS];
    load_words(file, words);
    fclose(file);

    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }
    char line[1000];
    while (fgets(line, sizeof(line), input_file)!= NULL) {
        char *word_start = line;
        char *word_end = line;
        while (*word_end!= '\0' &&!isspace(*word_end)) {
            word_end++;
        }
        char *word = malloc(word_end - word_start + 1);
        strncpy(word, word_start, word_end - word_start);
        word[word_end - word_start] = '\0';
        check_word(word, words);
        free(word);
        word_start = word_end;
    }
    fclose(input_file);

    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }
    print_errors(output_file, words);
    fclose(output_file);

    return 0;
}