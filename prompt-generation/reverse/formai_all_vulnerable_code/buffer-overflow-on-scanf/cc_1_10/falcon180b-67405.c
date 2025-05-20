//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int compare(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;
    if (wc1->count > wc2->count) {
        return -1;
    } else if (wc1->count < wc2->count) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char input[1000];
    char word[MAX_WORD_LEN];
    char *token;
    FILE *fp;
    WordCount words[MAX_WORDS];
    int numWords = 0;
    int i;

    printf("Enter the name of the input file: ");
    scanf("%s", input);

    fp = fopen(input, "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", input);
        exit(1);
    }

    while (fgets(input, 1000, fp)!= NULL) {
        numWords = 0;
        token = strtok(input, ",.!?;:\"'");
        while (token!= NULL) {
            strcpy(word, token);
            for (i = 0; i < strlen(word); i++) {
                if (!isalpha(word[i])) {
                    word[i] = '\0';
                }
            }
            if (strlen(word) > 0) {
                int found = 0;
                for (i = 0; i < numWords; i++) {
                    if (strcmp(words[i].word, word) == 0) {
                        words[i].count++;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    strcpy(words[numWords].word, word);
                    words[numWords].count = 1;
                    numWords++;
                }
            }
            token = strtok(NULL, ",.!?;:\"'");
        }
    }

    qsort(words, numWords, sizeof(WordCount), compare);

    printf("Top 10 most frequent words:\n");
    for (i = 0; i < 10 && i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    fclose(fp);
    return 0;
}