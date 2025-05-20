//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} Word;

void load_dictionary(Word dictionary[MAX_WORDS]) {
    FILE* file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    int num_words = 0;
    while (fscanf(file, "%s", dictionary[num_words].word)!= EOF) {
        dictionary[num_words].is_correct = true;
        num_words++;
    }

    fclose(file);
}

int compare_words(const void* a, const void* b) {
    const Word* word1 = (const Word*) a;
    const Word* word2 = (const Word*) b;

    return strcmp(word1->word, word2->word);
}

void spell_check(char* text, Word dictionary[MAX_WORDS]) {
    char* word = strtok(text, ",.!?;:");
    while (word!= NULL) {
        bool is_correct = false;
        for (int i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word, dictionary[i].word) == 0) {
                is_correct = true;
                break;
            }
        }

        if (!is_correct) {
            printf("Possible spelling mistake: %s\n", word);
        }

        word = strtok(NULL, ",.!?;:");
    }
}

int main() {
    Word dictionary[MAX_WORDS];
    load_dictionary(dictionary);

    char* text = "The quick brown fox jumps over the lazy dog. ";
    spell_check(text, dictionary);

    return 0;
}