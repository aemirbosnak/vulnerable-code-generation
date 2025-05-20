//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordPair;

void loadWords(WordPair words[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words file.\n");
        exit(1);
    }

    int numWords = 0;
    while (fscanf(file, "%s %s\n", words[numWords].word, words[numWords].translation) == 2) {
        numWords++;
        if (numWords >= MAX_WORDS) {
            printf("Error: Too many words in file.\n");
            exit(1);
        }
    }

    fclose(file);
}

void translate(char input[], WordPair words[]) {
    int numWords = 0;
    char *word = strtok(input, " ");
    while (word!= NULL && numWords < MAX_WORDS) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(word, words[i].word) == 0) {
                printf("%s ", words[i].translation);
                break;
            }
        }

        if (i == numWords) {
            printf("Error: Unknown word '%s'.\n", word);
        }

        word = strtok(NULL, " ");
        numWords++;
    }
}

int main() {
    WordPair words[MAX_WORDS];
    loadWords(words);

    char input[MAX_WORD_LENGTH * 10];
    printf("Enter a sentence to translate:\n");
    fgets(input, sizeof(input), stdin);

    translate(input, words);

    return 0;
}