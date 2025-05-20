//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char *word;
    char *translation;
} WordPair;

WordPair dictionary[MAX_WORDS];
int numWords = 0;

void loadDictionary(char *filename) {
    FILE *fp;
    char line[MAX_WORD_LENGTH];
    char *word, *translation;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        word = strtok(line, " ");
        translation = strtok(NULL, " ");

        if (word == NULL || translation == NULL) {
            printf("Error: invalid entry in dictionary file.\n");
            exit(1);
        }

        dictionary[numWords].word = strdup(word);
        dictionary[numWords].translation = strdup(translation);

        numWords++;
    }

    fclose(fp);
}

void translate(char *text) {
    char *word, *translation;
    char buffer[MAX_WORD_LENGTH];
    int i, j;

    i = 0;
    while (text[i]!= '\0') {
        if (isalpha(text[i])) {
            j = 0;
            while (isalpha(text[i]) && j < MAX_WORD_LENGTH - 1) {
                buffer[j] = tolower(text[i]);
                i++;
                j++;
            }
            buffer[j] = '\0';

            word = strdup(buffer);
            translation = strdup("meow");

            for (int k = 0; k < numWords; k++) {
                if (strcmp(dictionary[k].word, word) == 0) {
                    printf("%s -> %s\n", word, dictionary[k].translation);
                    free(word);
                    free(translation);
                    return;
                }
            }

            printf("%s -> %s\n", word, translation);
            free(word);
            free(translation);
        } else {
            printf("%c", text[i]);
        }
        i++;
    }
}

int main() {
    char text[MAX_WORD_LENGTH];
    printf("Enter text to translate:\n");
    fgets(text, MAX_WORD_LENGTH, stdin);

    loadDictionary("dictionary.txt");
    translate(text);

    return 0;
}