//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

struct word_list {
    struct word words[MAX_WORDS];
    int num_words;
};

void initialize_word_list(struct word_list *list) {
    list->num_words = 0;
}

void add_word(struct word_list *list, char *word) {
    int i;
    for (i = 0; i < list->num_words; i++) {
        if (strcmp(list->words[i].word, word) == 0) {
            list->words[i].count++;
            return;
        }
    }
    if (list->num_words >= MAX_WORDS) {
        printf("Error: maximum number of words reached\n");
        return;
    }
    strncpy(list->words[list->num_words].word, word, MAX_WORD_LENGTH);
    list->words[list->num_words].count = 1;
    list->num_words++;
}

void print_word_counts(struct word_list *list) {
    int i;
    for (i = 0; i < list->num_words; i++) {
        printf("%s: %d\n", list->words[i].word, list->words[i].count);
    }
}

int main(int argc, char **argv) {
    struct word_list word_list;
    initialize_word_list(&word_list);
    char *word = NULL;
    int word_length = 0;
    while (fgets(word, MAX_WORD_LENGTH, stdin)!= NULL) {
        word_length = strlen(word);
        if (word_length > 0 && word[word_length - 1] == '\n') {
            word[--word_length] = '\0';
        }
        add_word(&word_list, word);
    }
    print_word_counts(&word_list);
    return 0;
}