//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char *english;
    char *cat;
} WordPair;

int loadWords(WordPair words[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words file.\n");
        return -1;
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", words[count].english, words[count].cat)!= EOF) {
        count++;
        if (count >= MAX_WORDS) {
            printf("Too many words in file.\n");
            return -1;
        }
    }

    fclose(file);
    return count;
}

char *translate(char *text, WordPair words[], int numWords) {
    char *result = malloc(strlen(text) + 1);
    strcpy(result, text);

    for (int i = 0; i < numWords; i++) {
        char *english = words[i].english;
        char *cat = words[i].cat;

        char *token = strtok(result, " ");
        while (token!= NULL) {
            if (strcmp(token, english) == 0) {
                strcpy(token, cat);
            }
            token = strtok(NULL, " ");
        }
    }

    return result;
}

int main() {
    WordPair words[MAX_WORDS];
    int numWords = loadWords(words);

    if (numWords <= 0) {
        return 1;
    }

    char inputText[MAX_WORD_LENGTH];
    printf("Enter text to translate:\n");
    fgets(inputText, sizeof(inputText), stdin);

    char *translatedText = translate(inputText, words, numWords);
    printf("Translated text: %s\n", translatedText);

    free(translatedText);
    return 0;
}