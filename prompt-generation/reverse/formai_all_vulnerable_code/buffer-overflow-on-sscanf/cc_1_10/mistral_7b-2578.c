//MISTRAL-7B DATASET v1.0 Category: Cat Language Translator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define WORD_LENGTH 20

typedef struct Word {
    char catWord[WORD_LENGTH];
    char englishWord[WORD_LENGTH];
} Word;

Word dictionary[MAX_WORDS];
int numWords = 0;

void loadDictionary() {
    FILE *fp;
    char line[100];

    fp = fopen("cat_english.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        sscanf(line, "%s %s", dictionary[numWords].catWord, dictionary[numWords].englishWord);
        numWords++;
    }

    fclose(fp);
}

int findWordIndex(char *catWord) {
    int i;

    for (i = 0; i < numWords; i++) {
        if (strcmp(catWord, dictionary[i].catWord) == 0) {
            return i;
        }
    }

    return -1;
}

void translate(char *catPhrase) {
    char words[5][WORD_LENGTH];
    int i, j, index;
    char *token;

    strcpy(words[0], catPhrase);

    for (i = 1; i < 5; i++) {
        token = strtok(NULL, " ");
        strcpy(words[i], token);
    }

    for (i = 0; i < 5; i++) {
        for (j = 0; j < numWords; j++) {
            if (strcmp(words[i], dictionary[j].catWord) == 0) {
                printf("%s : %s\n", words[i], dictionary[j].englishWord);
                index = j;
                break;
            }
        }

        if (j == numWords) {
            printf("Error: Unknown CAT word '%s'.\n", words[i]);
            return;
        }

        memset(words[i], 0, strlen(words[i]));
        strcpy(words[i], dictionary[index].englishWord);
    }

    printf("Translated phrase: ");
    for (i = 0; i < 5; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    char catPhrase[100];

    if (argc != 2) {
        printf("Usage: %s <CAT phrase>\n", argv[0]);
        exit(1);
    }

    loadDictionary();
    strcpy(catPhrase, argv[1]);

    translate(catPhrase);

    return 0;
}