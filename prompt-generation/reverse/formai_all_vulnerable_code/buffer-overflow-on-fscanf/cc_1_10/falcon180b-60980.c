//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    char translation[MAX_WORD_LEN];
} WordTranslation;

void loadWords(WordTranslation *words) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    int numWords = 0;
    while (fscanf(file, "%s %s\n", words[numWords].word, words[numWords].translation)!= EOF) {
        numWords++;
        if (numWords >= MAX_WORDS) {
            printf("Error: too many words in words.txt\n");
            exit(1);
        }
    }

    fclose(file);
}

void translate(const char *text, WordTranslation *words) {
    char *token = strtok(text, " ");
    while (token!= NULL) {
        int i = 0;
        while (i < MAX_WORDS && strcmp(words[i].word, token)!= 0) {
            i++;
        }

        if (i < MAX_WORDS) {
            printf("%s -> %s\n", token, words[i].translation);
        } else {
            printf("%s not found\n", token);
        }

        token = strtok(NULL, " ");
    }
}

int main() {
    WordTranslation words[MAX_WORDS];
    loadWords(words);

    char text[1000];
    printf("Enter some text to translate:\n");
    fgets(text, sizeof(text), stdin);

    translate(text, words);

    return 0;
}