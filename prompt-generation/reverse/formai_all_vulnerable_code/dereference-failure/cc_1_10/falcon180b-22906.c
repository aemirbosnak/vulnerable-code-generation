//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char *english;
    char *alien;
} word_pair;

word_pair words[MAX_WORDS];
int num_words = 0;

void add_word(char *english, char *alien) {
    if (num_words >= MAX_WORDS) {
        printf("Error: too many words\n");
        exit(1);
    }
    words[num_words].english = strdup(english);
    words[num_words].alien = strdup(alien);
    num_words++;
}

void load_words(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        char *english = strtok(line, " ");
        char *alien = strtok(NULL, " ");
        if (english == NULL || alien == NULL) {
            printf("Error: invalid line in file %s\n", filename);
            exit(1);
        }
        add_word(english, alien);
    }
    fclose(file);
}

void translate_sentence(char *sentence) {
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        bool found = false;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].english) == 0) {
                printf("%s ", words[i].alien);
                found = true;
                break;
            }
        }
        if (!found) {
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <load_words_file> <sentence_file>\n", argv[0]);
        exit(1);
    }
    load_words(argv[1]);
    FILE *file = fopen(argv[2], "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", argv[2]);
        exit(1);
    }
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        translate_sentence(line);
    }
    fclose(file);
    return 0;
}