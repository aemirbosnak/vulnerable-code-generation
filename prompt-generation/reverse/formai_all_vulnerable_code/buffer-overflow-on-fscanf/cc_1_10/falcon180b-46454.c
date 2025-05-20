//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    char translation[MAX_WORD_LEN];
} WordTranslation;

int main() {
    FILE *dictFile;
    WordTranslation dict[MAX_WORDS];
    int dictSize = 0;

    dictFile = fopen("dictionary.txt", "r");
    if (dictFile == NULL) {
        printf("Error: Could not open dictionary file.\n");
        return 1;
    }

    char line[MAX_WORD_LEN];
    while (fscanf(dictFile, "%s %s\n", line, dict[dictSize].word)!= EOF) {
        strcpy(dict[dictSize].translation, line);
        dictSize++;
    }

    fclose(dictFile);

    char sentence[MAX_WORD_LEN * 10];
    printf("Enter a sentence to translate:\n");
    fgets(sentence, sizeof(sentence), stdin);

    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < dictSize; i++) {
            if (strcmp(dict[i].word, token) == 0) {
                printf("%s ", dict[i].translation);
                break;
            }
        }
        if (i == dictSize) {
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }

    return 0;
}