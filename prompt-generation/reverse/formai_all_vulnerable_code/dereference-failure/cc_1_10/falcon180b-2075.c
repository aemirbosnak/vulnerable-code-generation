//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MIN_WORD_LEN 3

typedef struct {
    char *word;
    int count;
} Word;

typedef struct {
    Word *words;
    int num_words;
} WordList;

WordList *create_word_list();
void add_word(WordList *list, char *word);
void print_word_list(WordList *list);
void free_word_list(WordList *list);

int main() {
    FILE *fp;
    char line[1024];
    char *token;
    WordList *spam_words = create_word_list();

    fp = fopen("spam_words.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open spam_words.txt\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, " \t\n");
        while (token!= NULL) {
            add_word(spam_words, token);
            token = strtok(NULL, " \t\n");
        }
    }

    fclose(fp);

    char text[1024];
    while (fgets(text, sizeof(text), stdin)!= NULL) {
        int is_spam = 0;
        token = strtok(text, " \t\n");
        while (token!= NULL) {
            Word *word = NULL;
            for (int i = 0; i < spam_words->num_words; i++) {
                if (strcmp(token, spam_words->words[i].word) == 0) {
                    word = &spam_words->words[i];
                    break;
                }
            }

            if (word!= NULL) {
                word->count++;
                is_spam = 1;
            }

            token = strtok(NULL, " \t\n");
        }

        if (is_spam) {
            printf("Spam detected!\n");
        } else {
            printf("No spam detected.\n");
        }
    }

    free_word_list(spam_words);

    return 0;
}

WordList *create_word_list() {
    WordList *list = (WordList*) malloc(sizeof(WordList));
    list->words = (Word*) malloc(MAX_WORDS * sizeof(Word));
    list->num_words = 0;

    return list;
}

void add_word(WordList *list, char *word) {
    if (list->num_words >= MAX_WORDS) {
        printf("Error: maximum number of words reached.\n");
        return;
    }

    Word *new_word = (Word*) malloc(sizeof(Word));
    new_word->word = strdup(word);
    new_word->count = 0;

    list->words[list->num_words++] = *new_word;
}

void print_word_list(WordList *list) {
    for (int i = 0; i < list->num_words; i++) {
        printf("%s: %d\n", list->words[i].word, list->words[i].count);
    }
}

void free_word_list(WordList *list) {
    for (int i = 0; i < list->num_words; i++) {
        free(list->words[i].word);
    }

    free(list->words);
    free(list);
}