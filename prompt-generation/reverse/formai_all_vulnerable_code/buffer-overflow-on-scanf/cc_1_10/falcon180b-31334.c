//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 100000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    bool is_correct;
} Word;

void load_dictionary(Word words[]) {
    FILE* fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error loading dictionary.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s", words[count].word)!= EOF) {
        words[count].is_correct = true;
        count++;
    }

    fclose(fp);
}

bool is_word_correct(Word words[], char* word) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, word) == 0 && words[i].is_correct) {
            return true;
        }
    }

    return false;
}

void check_word(char* word) {
    Word words[MAX_WORDS];
    load_dictionary(words);

    if (is_word_correct(words, word)) {
        printf("%s is correct.\n", word);
    } else {
        printf("%s is incorrect.\n", word);
    }
}

int main() {
    char input[MAX_WORD_LEN];

    while (true) {
        printf("Enter a word to check (type 'exit' to quit): ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        check_word(input);
    }

    return 0;
}