//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 10

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordPair;

void loadWords(WordPair words[], int numWords) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, "%s %s\n", words[i].word, words[i].translation)!= EOF) {
        i++;
        if (i >= numWords) {
            printf("Too many words in file\n");
            exit(1);
        }
    }

    fclose(file);
}

int main() {
    char input[1000];
    char *token;
    WordPair words[MAX_WORDS];

    loadWords(words, MAX_WORDS);

    printf("Enter a sentence to translate:\n");
    fgets(input, sizeof(input), stdin);

    token = strtok(input, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(token, words[i].word) == 0) {
                printf("%s ", words[i].translation);
                break;
            }
        }
        if (i == MAX_WORDS) {
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }
    printf("\n");

    return 0;
}