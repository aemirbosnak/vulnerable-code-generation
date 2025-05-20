//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    const WordCount *w1 = a;
    const WordCount *w2 = b;
    return strcmp(w1->word, w2->word);
}

int main() {
    char input[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    FILE *dictionary;
    WordCount words[MAX_WORDS];
    int numWords = 0;

    printf("Enter the name of the dictionary file: ");
    scanf("%s", input);
    dictionary = fopen(input, "r");

    if (dictionary == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    while (fscanf(dictionary, "%s", word)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Error: too many words in dictionary.\n");
            exit(1);
        }
        strcpy(words[numWords].word, word);
        words[numWords].count = 0;
        numWords++;
    }

    fclose(dictionary);

    char sentence[MAX_WORD_LENGTH];
    char *token;
    while (fgets(sentence, MAX_WORD_LENGTH, stdin)!= NULL) {
        token = strtok(sentence, ",.!?;:");
        while (token!= NULL) {
            int i;
            for (i = 0; i < numWords; i++) {
                if (strcmp(token, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == numWords) {
                printf("Unknown word: %s\n", token);
            }
            token = strtok(NULL, ",.!?;:");
        }
    }

    qsort(words, numWords, sizeof(WordCount), compareWords);

    printf("Word count:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}