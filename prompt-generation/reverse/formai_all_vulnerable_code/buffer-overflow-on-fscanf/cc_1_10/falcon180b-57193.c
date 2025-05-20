//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 50000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;
    return strcmp(wc1->word, wc2->word);
}

int main() {
    FILE *dictionary = fopen("dictionary.txt", "r");
    if (dictionary == NULL) {
        printf("Error opening dictionary file.\n");
        exit(1);
    }

    WordCount words[MAX_WORDS];
    int numWords = 0;

    char word[MAX_WORD_LEN];
    while (fscanf(dictionary, "%s", word)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Dictionary is too large.\n");
            exit(1);
        }
        strcpy(words[numWords].word, word);
        words[numWords].count = 0;
        numWords++;
    }

    fclose(dictionary);

    char input[MAX_WORD_LEN];
    while (fgets(input, MAX_WORD_LEN, stdin)!= NULL) {
        char *token = strtok(input, ",.?!;:");
        while (token!= NULL) {
            int i;
            for (i = 0; i < numWords; i++) {
                if (strcmp(token, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == numWords) {
                printf("%s is not in the dictionary.\n", token);
            }
            token = strtok(NULL, ",.?!;:");
        }
    }

    qsort(words, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}