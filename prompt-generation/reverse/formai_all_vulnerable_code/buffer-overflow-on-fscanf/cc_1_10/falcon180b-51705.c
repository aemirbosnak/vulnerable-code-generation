//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    char translation[MAX_WORD_LEN];
} WordPair;

void loadWords(WordPair *wordPairs) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    int numWords = 0;
    while (fscanf(file, "%s %s", wordPairs[numWords].word, wordPairs[numWords].translation)!= EOF) {
        numWords++;
    }

    fclose(file);
}

int main() {
    WordPair wordPairs[MAX_WORDS];
    loadWords(wordPairs);

    char sentence[MAX_WORD_LEN * 10];
    printf("Enter a sentence to translate:\n");
    fgets(sentence, sizeof(sentence), stdin);

    char *tokens[MAX_WORD_LEN * 10];
    int numTokens = 0;
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < MAX_WORD_LEN * 10; i++) {
            if (i == MAX_WORD_LEN * 10 - 1) {
                printf("Error: sentence too long\n");
                exit(1);
            }
            if (strncmp(token, wordPairs[i].word, strlen(token)) == 0) {
                strcpy(tokens[numTokens++], wordPairs[i].translation);
                break;
            }
        }
        if (i == MAX_WORD_LEN * 10 - 1) {
            printf("Error: unknown word '%s'\n", token);
            exit(1);
        }
        token = strtok(NULL, " ");
    }

    printf("Translated sentence: ");
    for (int i = 0; i < numTokens; i++) {
        printf("%s ", tokens[i]);
    }
    printf("\n");

    return 0;
}