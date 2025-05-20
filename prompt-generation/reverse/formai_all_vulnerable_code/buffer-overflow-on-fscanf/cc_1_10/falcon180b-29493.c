//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 30
#define TRUE 1
#define FALSE 0

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int is_correct;
} Word;

void load_dictionary(Word *dictionary, int num_words, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    int num_loaded_words = 0;
    while (fscanf(file, "%s", dictionary[num_loaded_words].word)!= EOF) {
        dictionary[num_loaded_words].is_correct = TRUE;
        num_loaded_words++;
    }

    fclose(file);
}

int is_word_correct(Word *dictionary, int num_words, char *word) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            return TRUE;
        }
    }
    return FALSE;
}

int main() {
    char text[100000];
    printf("Enter text to check: ");
    fgets(text, sizeof(text), stdin);

    char *words[10000];
    int num_words = 0;
    char *word = strtok(text, " ");
    while (word!= NULL) {
        if (num_words >= 10000) {
            printf("Error: too many words\n");
            exit(1);
        }
        words[num_words++] = word;
        word = strtok(NULL, " ");
    }

    Word dictionary[10000];
    load_dictionary(dictionary, 10000, "dictionary.txt");

    for (int i = 0; i < num_words; i++) {
        if (!is_word_correct(dictionary, 10000, words[i])) {
            printf("%s\n", words[i]);
        }
    }

    return 0;
}