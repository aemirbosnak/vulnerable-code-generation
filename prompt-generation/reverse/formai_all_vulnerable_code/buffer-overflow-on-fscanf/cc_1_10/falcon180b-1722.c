//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 5000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} Word;

Word dictionary[MAX_WORDS];
int num_words = 0;

void load_dictionary(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error loading dictionary file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Dictionary is full.\n");
            exit(1);
        }
        strcpy(dictionary[num_words].word, word);
        dictionary[num_words].is_correct = true;
        num_words++;
    }

    fclose(file);
}

bool is_word_correct(char *word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(word, dictionary[i].word) == 0) {
            return dictionary[i].is_correct;
        }
    }
    return false;
}

void spell_check(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            if (strlen(token) > MAX_WORD_LENGTH) {
                printf("Error: word too long - %s\n", token);
            } else {
                strcpy(word, token);
                if (!is_word_correct(word)) {
                    printf("Possible spelling error: %s\n", word);
                }
            }
            token = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        exit(1);
    }

    load_dictionary(argv[1]);
    spell_check(argv[2]);

    return 0;
}