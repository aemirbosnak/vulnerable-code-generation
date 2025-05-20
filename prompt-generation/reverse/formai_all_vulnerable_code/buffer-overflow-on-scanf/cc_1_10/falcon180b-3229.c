//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;

    return strcasecmp(wc1->word, wc2->word);
}

int main() {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    char *word;
    WordCount words[MAX_WORDS];
    int numWords = 0;

    printf("Enter file name: ");
    scanf("%s", line);

    file = fopen(line, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        word = strtok(line, ",.?!;:");

        while (word!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                break;
            }

            int len = strlen(word);

            if (len > MAX_WORD_LENGTH) {
                printf("Word too long: %s\n", word);
                continue;
            }

            strcpy(words[numWords].word, word);
            words[numWords].count = 1;

            numWords++;

            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);

    qsort(words, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}