//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void read_words(const char *filename, WordCount words[]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int found = 0;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(words[i].word, word);
            words[i].count = 1;
            i++;
            if (i >= MAX_WORDS) {
                printf("Error: too many unique words in file\n");
                exit(1);
            }
        }
    }

    fclose(file);
}

void print_misspelled_words(const char *filename, const WordCount words[]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int found = 0;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word, words[i].word) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("%s\n", word);
        }
    }

    fclose(file);
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <dictionary_file> <input_file>\n", argv[0]);
        exit(1);
    }

    WordCount words[MAX_WORDS];
    read_words(argv[1], words);

    print_misspelled_words(argv[2], words);

    return 0;
}