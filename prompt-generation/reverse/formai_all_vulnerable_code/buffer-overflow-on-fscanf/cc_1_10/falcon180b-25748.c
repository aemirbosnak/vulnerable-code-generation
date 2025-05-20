//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 20
#define MAX_DICT_SIZE 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} Word;

typedef struct {
    Word words[MAX_DICT_SIZE];
    int num_words;
} Dict;

void load_dict(Dict* dict, const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    int i = 0;
    char line[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", line) == 1) {
        if (i >= MAX_DICT_SIZE) {
            printf("Error: dictionary is too large.\n");
            exit(1);
        }

        strcpy(dict->words[i].word, line);
        dict->words[i].is_correct = true;
        i++;
    }

    dict->num_words = i;
    fclose(fp);
}

bool is_correct(const char* word, Dict* dict) {
    int len = strlen(word);
    if (len > MAX_WORD_LENGTH) {
        return false;
    }

    for (int i = 0; i < dict->num_words; i++) {
        if (strcmp(dict->words[i].word, word) == 0) {
            return dict->words[i].is_correct;
        }
    }

    return false;
}

int main() {
    Dict dict;
    load_dict(&dict, "dictionary.txt");

    char text[100000];
    printf("Enter text to check spelling:\n");
    fgets(text, sizeof(text), stdin);

    char* word = strtok(text, ",.?!;:");
    while (word!= NULL) {
        if (!is_correct(word, &dict)) {
            printf("%s is not a valid word.\n", word);
        }

        word = strtok(NULL, ",.?!;:");
    }

    return 0;
}