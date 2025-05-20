//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char *english;
    char *cat;
} word_pair;

void load_words(word_pair words[]) {
    FILE *file = fopen("cat_english_dictionary.txt", "r");
    if (file == NULL) {
        printf("Error loading dictionary file\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", words[count].english, words[count].cat)!= EOF) {
        count++;
    }

    fclose(file);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <sentence>\n", argv[0]);
        return 1;
    }

    char input_sentence[MAX_WORD_LENGTH * 50];
    strcpy(input_sentence, argv[1]);

    // Convert input sentence to lowercase
    int i = 0;
    while (input_sentence[i]!= '\0') {
        input_sentence[i] = tolower(input_sentence[i]);
        i++;
    }

    // Split input sentence into words
    char *token = strtok(input_sentence, " ");
    int num_words = 0;
    while (token!= NULL) {
        num_words++;
        token = strtok(NULL, " ");
    }

    // Load dictionary words
    word_pair words[MAX_WORDS];
    load_words(words);

    // Translate input sentence
    char output_sentence[MAX_WORD_LENGTH * 50];
    strcpy(output_sentence, "");
    token = strtok(input_sentence, " ");
    while (token!= NULL) {
        int i = 0;
        while (words[i].english!= NULL && strcmp(token, words[i].english)!= 0) {
            i++;
        }
        if (words[i].cat!= NULL) {
            strcat(output_sentence, words[i].cat);
            strcat(output_sentence, " ");
        }
        token = strtok(NULL, " ");
    }

    printf("%s\n", output_sentence);

    return 0;
}