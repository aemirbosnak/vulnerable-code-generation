//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_LENGTH 100
#define MAX_CONSPIRACY_WORDS 20
#define WORD_LIST_FILE "word_list.txt"

typedef struct {
    char **words;
    int num_words;
} WordList;

void load_word_list(WordList *word_list) {
    FILE *file = fopen(WORD_LIST_FILE, "r");
    if (file == NULL) {
        printf("Error: could not open word list file.\n");
        exit(1);
    }

    char word[MAX_CONSPIRACY_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        word_list->words[word_list->num_words++] = strdup(word);
    }

    fclose(file);
}

void generate_conspiracy_theory(WordList *word_list) {
    srand(time(NULL));

    char conspiracy[MAX_CONSPIRACY_LENGTH];
    conspiracy[0] = '\0';

    int num_words = rand() % MAX_CONSPIRACY_WORDS + 1;
    for (int i = 0; i < num_words; i++) {
        int word_index = rand() % word_list->num_words;
        strcat(conspiracy, word_list->words[word_index]);
        strcat(conspiracy, " ");
    }

    printf("The truth behind %s is that %s.\n", conspiracy, conspiracy);
}

int main() {
    WordList word_list;
    load_word_list(&word_list);
    generate_conspiracy_theory(&word_list);

    return 0;
}