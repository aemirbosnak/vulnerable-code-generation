//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000 // maximum number of words in the dictionary
#define MAX_WORD_LENGTH 20 // maximum length of a word in the dictionary

typedef struct {
    char *word;
    int length;
} word_t;

word_t dictionary[MAX_WORDS];
int num_words = 0;

void load_dictionary(char *filename) {
    FILE *file = fopen(filename, "r");
    char word[MAX_WORD_LENGTH + 1];
    while (fscanf(file, "%s", word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Error: dictionary is full.\n");
            exit(1);
        }
        dictionary[num_words].word = strdup(word);
        dictionary[num_words].length = strlen(word);
        num_words++;
    }
    fclose(file);
}

int is_word_in_dictionary(char *word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcasecmp(dictionary[i].word, word) == 0) {
            return 1; // word is in dictionary
        }
    }
    return 0; // word is not in dictionary
}

void print_misspelled_words(char *filename) {
    FILE *file = fopen(filename, "r");
    char word[MAX_WORD_LENGTH + 1];
    while (fscanf(file, "%s", word)!= EOF) {
        int is_misspelled = 1;
        int i;
        for (i = 0; i < num_words && is_misspelled; i++) {
            if (strcasecmp(dictionary[i].word, word) == 0) {
                is_misspelled = 0;
            }
        }
        if (is_misspelled) {
            printf("%s\n", word);
        }
    }
    fclose(file);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return 1;
    }
    load_dictionary(argv[1]);
    print_misspelled_words(argv[2]);
    return 0;
}