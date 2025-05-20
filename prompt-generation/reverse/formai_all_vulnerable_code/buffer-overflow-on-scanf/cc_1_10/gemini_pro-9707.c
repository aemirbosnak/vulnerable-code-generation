//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    long long int count;
    char* word;
} WordFreq;

typedef struct {
    size_t size;
    WordFreq* words;
} WordFreqList;

int compareWordFreq(const void* a, const void* b) {
    WordFreq* wfa = (WordFreq*)a;
    WordFreq* wfb = (WordFreq*)b;
    return (wfa->count < wfb->count) - (wfa->count > wfb->count);
}

WordFreqList* newWordFreqList(size_t size) {
    WordFreqList* wfl = malloc(sizeof(WordFreqList));
    wfl->size = size;
    wfl->words = malloc(sizeof(WordFreq) * size);
    return wfl;
}

void freeWordFreqList(WordFreqList* wfl) {
    for (size_t i = 0; i < wfl->size; i++) {
        free(wfl->words[i].word);
    }
    free(wfl->words);
    free(wfl);
}

void addWordToWordFreqList(WordFreqList* wfl, char* word) {
    int found = 0;
    for (size_t i = 0; i < wfl->size; i++) {
        if (strcmp(wfl->words[i].word, word) == 0) {
            wfl->words[i].count++;
            found = 1;
            break;
        }
    }
    if (!found) {
        size_t newSize = wfl->size + 1;
        wfl->words = realloc(wfl->words, sizeof(WordFreq) * newSize);
        wfl->words[wfl->size].count = 1;
        wfl->words[wfl->size].word = strdup(word);
        wfl->size = newSize;
    }
}

void printWordFreqList(WordFreqList* wfl) {
    qsort(wfl->words, wfl->size, sizeof(WordFreq), compareWordFreq);
    for (size_t i = 0; i < wfl->size; i++) {
        printf("%s: %lld\n", wfl->words[i].word, wfl->words[i].count);
    }
}

int main() {
    WordFreqList* wfl = newWordFreqList(0);
    char word[1024];
    while (scanf("%s", word) != EOF) {
        char* p = word;
        while (*p) {
            *p = tolower(*p);
            p++;
        }
        addWordToWordFreqList(wfl, word);
    }
    printWordFreqList(wfl);
    freeWordFreqList(wfl);
    return 0;
}