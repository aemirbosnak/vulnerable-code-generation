//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    char *translation;
} WordPair;

typedef struct {
    WordPair *wordPairs;
    int numPairs;
} Dictionary;

void loadDictionary(Dictionary *dict, char *filename);
int findWord(Dictionary *dict, char *word);
int findTranslation(Dictionary *dict, char *word);

int main() {
    char input[MAX_WORD_LENGTH];
    char output[MAX_WORD_LENGTH];
    char filename[MAX_WORD_LENGTH];
    int i;
    int numWords;
    int wordLength;
    Dictionary dict;

    printf("Enter the name of the dictionary file: ");
    scanf("%s", filename);

    loadDictionary(&dict, filename);

    printf("Enter the number of words to translate: ");
    scanf("%d", &numWords);

    for (i = 0; i < numWords; i++) {
        printf("Enter the word to translate: ");
        scanf("%s", input);
        wordLength = strlen(input);
        if (wordLength > MAX_WORD_LENGTH) {
            printf("Word is too long.\n");
            continue;
        }
        strcpy(output, input);
        if (findWord(&dict, input)) {
            printf("%s -> %s\n", input, dict.wordPairs[findWord(&dict, input)].translation);
        } else {
            printf("No translation found.\n");
        }
    }

    return 0;
}

void loadDictionary(Dictionary *dict, char *filename) {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    char *word;
    char *translation;
    int numPairs = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening dictionary file.\n");
        exit(1);
    }

    dict->wordPairs = (WordPair *)malloc(MAX_WORDS * sizeof(WordPair));
    dict->numPairs = 0;

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        word = strtok(line, " ");
        translation = strtok(NULL, " ");
        if (word!= NULL && translation!= NULL) {
            dict->wordPairs[dict->numPairs].word = strdup(word);
            dict->wordPairs[dict->numPairs].translation = strdup(translation);
            dict->numPairs++;
        }
    }

    fclose(file);
}

int findWord(Dictionary *dict, char *word) {
    int i;

    for (i = 0; i < dict->numPairs; i++) {
        if (strcmp(dict->wordPairs[i].word, word) == 0) {
            return i;
        }
    }

    return -1;
}

int findTranslation(Dictionary *dict, char *word) {
    int i;

    i = findWord(dict, word);
    if (i == -1) {
        return -1;
    }

    return dict->numPairs - 1 - i;
}