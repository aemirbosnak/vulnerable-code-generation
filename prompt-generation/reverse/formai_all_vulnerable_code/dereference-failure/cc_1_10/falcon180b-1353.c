//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000

typedef struct {
    char *word;
    char *translation;
} Translation;

Translation dictionary[MAX_WORDS];
int num_words = 0;

void load_dictionary(char *filename) {
    FILE *fp;
    char line[1024];
    char *word, *translation;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        word = strtok(line, " ");
        translation = strtok(NULL, " ");

        if (word == NULL || translation == NULL) {
            printf("Error: invalid line in dictionary file.\n");
            exit(1);
        }

        dictionary[num_words].word = strdup(word);
        dictionary[num_words].translation = strdup(translation);
        num_words++;
    }

    fclose(fp);
}

int find_word(char *word) {
    int i;

    for (i = 0; i < num_words; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            return i;
        }
    }

    return -1;
}

void translate_sentence(char *sentence) {
    char *token;
    int i;

    token = strtok(sentence, " ");
    while (token!= NULL) {
        i = find_word(token);
        if (i!= -1) {
            printf("%s -> %s\n", token, dictionary[i].translation);
        } else {
            printf("%s\n", token);
        }
        token = strtok(NULL, " ");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <dictionary_file> <sentence>\n", argv[0]);
        exit(1);
    }

    load_dictionary(argv[1]);
    translate_sentence(argv[2]);

    return 0;
}