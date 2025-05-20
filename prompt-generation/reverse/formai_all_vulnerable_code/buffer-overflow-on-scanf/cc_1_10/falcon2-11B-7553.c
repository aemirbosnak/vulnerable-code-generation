//Falcon2-11B DATASET v1.0 Category: Spell checking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_HISTORY_SIZE 100

struct word_history {
    char word[MAX_WORD_LENGTH + 1];
    int frequency;
};

struct word_history history[MAX_HISTORY_SIZE];
int history_size = 0;

void add_word(const char* word) {
    if (history_size == MAX_HISTORY_SIZE) {
        printf("History size exceeded.\n");
        return;
    }

    struct word_history new_word;
    strncpy(new_word.word, word, MAX_WORD_LENGTH);
    new_word.frequency = 1;

    history[history_size] = new_word;
    history_size++;

    printf("Word added to history: %s\n", word);
}

void remove_word(const char* word) {
    int index = -1;

    for (int i = 0; i < history_size; i++) {
        if (strcmp(history[i].word, word) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Word not found in history.\n");
        return;
    }

    memmove(history + index, history + (index + 1), (history_size - (index + 1)) * sizeof(struct word_history));
    history_size--;

    printf("Word removed from history: %s\n", word);
}

int main() {
    char word[MAX_WORD_LENGTH + 1];

    while (1) {
        printf("Enter a word (type 'quit' to exit): ");
        scanf("%s", word);

        if (strcmp(word, "quit") == 0) {
            break;
        }

        add_word(word);

        printf("History: ");
        for (int i = 0; i < history_size; i++) {
            printf("%s ", history[i].word);
        }
        printf("\n");
    }

    return 0;
}