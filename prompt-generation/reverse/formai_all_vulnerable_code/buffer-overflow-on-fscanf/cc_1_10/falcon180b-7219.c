//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

struct word dictionary[MAX_WORDS];
int num_words = 0;

void add_word(char *word) {
    strcpy(dictionary[num_words].word, word);
    dictionary[num_words].count = 0;
    num_words++;
}

void load_dictionary() {
    FILE *fp;
    char word[MAX_WORD_LENGTH];

    fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s", word)!= EOF) {
        add_word(word);
    }

    fclose(fp);
}

void spell_check(char *filename) {
    FILE *fp;
    char line[1000];
    char word[MAX_WORD_LENGTH];
    int i;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",.!?;:");
        while (token!= NULL) {
            int len = strlen(token);
            if (len > MAX_WORD_LENGTH) {
                len = MAX_WORD_LENGTH;
            }
            strncpy(word, token, len);
            word[len] = '\0';

            for (i = 0; i < num_words; i++) {
                if (strcmp(word, dictionary[i].word) == 0) {
                    dictionary[i].count++;
                    break;
                }
            }

            if (i == num_words) {
                printf("Misspelled word: %s\n", word);
            }

            token = strtok(NULL, ",.!?;:");
        }
    }

    fclose(fp);
}

int main() {
    load_dictionary();
    spell_check("example.txt");

    return 0;
}