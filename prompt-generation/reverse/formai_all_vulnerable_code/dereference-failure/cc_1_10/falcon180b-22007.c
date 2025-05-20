//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordPair;

void loadDictionary(WordPair *dictionary) {
    FILE *fp;
    char line[MAX_WORD_LENGTH];
    char *word, *translation;

    fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error loading dictionary\n");
        exit(1);
    }

    int count = 0;
    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        if (count >= MAX_WORDS) {
            printf("Dictionary is full\n");
            break;
        }

        word = strtok(line, " ");
        translation = strtok(NULL, " ");

        strcpy(dictionary[count].word, word);
        strcpy(dictionary[count].translation, translation);

        count++;
    }

    fclose(fp);
}

void translateSentence(char *sentence, WordPair *dictionary) {
    char *token;
    int i;

    token = strtok(sentence, " ");
    while (token!= NULL) {
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(token, dictionary[i].word) == 0) {
                printf("%s -> %s\n", token, dictionary[i].translation);
                break;
            }
        }

        if (i == MAX_WORDS) {
            printf("Unknown word: %s\n", token);
        }

        token = strtok(NULL, " ");
    }
}

int main() {
    WordPair dictionary[MAX_WORDS];

    loadDictionary(dictionary);

    char sentence[100];
    printf("Enter a sentence to translate: ");
    fgets(sentence, 100, stdin);

    translateSentence(sentence, dictionary);

    return 0;
}