//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_LINE_LEN 1000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

typedef struct {
    WordCount words[MAX_WORD_LEN];
    int numWords;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;
    return strcmp(wc1->word, wc2->word);
}

void printWordFrequency(WordFrequency *wf) {
    printf("Word\tFrequency\n");
    for (int i = 0; i < wf->numWords; i++) {
        WordCount *wc = &wf->words[i];
        printf("%s\t%d\n", wc->word, wc->count);
    }
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LEN];
    WordFrequency wf = {0};

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        int len = strlen(line);
        for (int i = 0; i < len; i++) {
            char c = tolower(line[i]);
            if (isalpha(c)) {
                char word[MAX_WORD_LEN];
                int j = 0;
                while (isalpha(c)) {
                    word[j++] = c;
                    i++;
                    if (i >= len) {
                        break;
                    }
                    c = tolower(line[i]);
                }
                word[j] = '\0';
                WordCount *wc = bsearch(word, wf.words, wf.numWords, sizeof(WordCount), compareWords);
                if (wc == NULL) {
                    wf.words[wf.numWords] = (WordCount){.word = strdup(word),.count = 1};
                    wf.numWords++;
                } else {
                    wc->count++;
                }
            }
        }
    }

    fclose(fp);
    qsort(wf.words, wf.numWords, sizeof(WordCount), compareWords);
    printWordFrequency(&wf);

    return 0;
}