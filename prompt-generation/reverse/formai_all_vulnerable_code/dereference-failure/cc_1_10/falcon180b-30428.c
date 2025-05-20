//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char *word;
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *w1 = (WordFrequency *)a;
    WordFrequency *w2 = (WordFrequency *)b;
    return strcmp(w1->word, w2->word);
}

void translate(char *text) {
    char *word = strtok(text, " ");
    while (word!= NULL) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            if (isalpha(word[i])) {
                word[i] = tolower(word[i]);
            }
        }
        printf("%s ", word);
        word = strtok(NULL, " ");
    }
}

int main() {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while ((read = getline(&line, &len, file))!= -1) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            int i;
            for (i = 0; i < strlen(word); i++) {
                if (isalpha(word[i])) {
                    word[i] = tolower(word[i]);
                }
            }
            int index = 0;
            while (index < numWords && strcmp(words[index].word, word)!= 0) {
                index++;
            }
            if (index == numWords) {
                if (numWords == MAX_WORDS) {
                    printf("Error: Too many unique words.\n");
                    return 1;
                }
                strncpy(words[numWords].word, word, MAX_WORD_LENGTH);
                words[numWords].count = 1;
                numWords++;
            } else {
                words[index].count++;
            }
            word = strtok(NULL, " ");
        }
    }

    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}