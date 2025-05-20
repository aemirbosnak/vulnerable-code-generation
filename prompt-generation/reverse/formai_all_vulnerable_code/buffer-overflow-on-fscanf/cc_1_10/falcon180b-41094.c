//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CONSPIRACY_LENGTH 1000
#define MAX_CONSPIRACY_WORDS 100
#define WORD_LIST_FILE "word_list.txt"

typedef struct {
    char *word;
    int length;
} Word;

void generate_conspiracy_theory(char theory[MAX_CONSPIRACY_LENGTH]) {
    FILE *word_list = fopen(WORD_LIST_FILE, "r");
    if (word_list == NULL) {
        printf("Error: could not open word_list.txt\n");
        exit(1);
    }

    Word words[MAX_CONSPIRACY_WORDS];
    int num_words = 0;

    while (fscanf(word_list, "%s", words[num_words].word)!= EOF) {
        words[num_words].length = strlen(words[num_words].word);
        num_words++;
    }

    fclose(word_list);

    srand(time(NULL));

    int i = 0;
    while (i < MAX_CONSPIRACY_LENGTH - 1) {
        int word_index = rand() % num_words;
        strncat(theory, words[word_index].word, words[word_index].length);
        i += words[word_index].length;
        if (i < MAX_CONSPIRACY_LENGTH - 2) {
            strncat(theory, " ", 1);
        }
    }

    strncat(theory, " is a lie!", 10);
}

int main() {
    char theory[MAX_CONSPIRACY_LENGTH];
    generate_conspiracy_theory(theory);
    printf("Theory: %s\n", theory);

    return 0;
}