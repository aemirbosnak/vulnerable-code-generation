//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char *word;
    char *translation;
} WordTranslation;

WordTranslation words[] = {
    {"cat", "gato"},
    {"dog", "perro"},
    {"hello", "hola"},
    {"world", "mundo"}
};

int numWords = sizeof(words) / sizeof(WordTranslation);

void translate(char *sentence) {
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(token, words[i].word) == 0) {
                printf("%s ", words[i].translation);
                break;
            }
        }
        if (i == numWords) {
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <sentence>\n", argv[0]);
        return 1;
    }

    char *sentence = argv[1];
    translate(sentence);

    return 0;
}