//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} Word;

typedef struct {
    Word *words;
    int num_words;
    int max_words;
} WordList;

void init_word_list(WordList *word_list) {
    word_list->words = (Word *)malloc(MAX_WORDS * sizeof(Word));
    word_list->num_words = 0;
    word_list->max_words = MAX_WORDS;
}

void add_word(WordList *word_list, char *word) {
    Word *new_word = (Word *)malloc(sizeof(Word));
    strcpy(new_word->word, word);
    new_word->count = 1;
    word_list->words[word_list->num_words] = *new_word;
    word_list->num_words++;
}

void print_word_list(WordList *word_list) {
    for (int i = 0; i < word_list->num_words; i++) {
        printf("%s: %d\n", word_list->words[i].word, word_list->words[i].count);
    }
}

int is_word(char *word) {
    int len = strlen(word);
    if (len > MAX_WORD_LEN) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input_file[100];
    printf("Enter the name of the input file: ");
    scanf("%s", input_file);
    FILE *fp = fopen(input_file, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }
    WordList word_list;
    init_word_list(&word_list);
    char word[MAX_WORD_LEN];
    while (fscanf(fp, "%s", word)!= EOF) {
        if (is_word(word)) {
            add_word(&word_list, word);
        }
    }
    fclose(fp);
    printf("Words in the file:\n");
    print_word_list(&word_list);
    return 0;
}