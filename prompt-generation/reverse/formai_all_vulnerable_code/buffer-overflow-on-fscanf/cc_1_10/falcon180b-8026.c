//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} word_pair;

void read_words(word_pair words[], int *num_words) {
    FILE *input_file = fopen("words.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(input_file, "%s %s", words[i].word, words[i].translation)!= EOF) {
        i++;
    }

    *num_words = i;

    fclose(input_file);
}

void translate_text(char *text, word_pair words[], int num_words) {
    char *token = strtok(text, " ");
    while (token!= NULL) {
        int j;
        for (j = 0; j < num_words; j++) {
            if (strcmp(token, words[j].word) == 0) {
                printf("%s ", words[j].translation);
                break;
            }
        }

        if (j == num_words) {
            printf("%s ", token);
        }

        token = strtok(NULL, " ");
    }
}

int main() {
    word_pair words[MAX_WORDS];
    int num_words;

    read_words(words, &num_words);

    char *text = "Hello world! How are you today?";

    translate_text(text, words, num_words);

    return 0;
}