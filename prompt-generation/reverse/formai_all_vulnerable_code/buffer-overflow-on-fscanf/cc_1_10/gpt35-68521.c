//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 1000
#define MAX_WORDS 10000

typedef struct {
    char word[MAX_WORD_SIZE];
    int count;
} WordCount;

WordCount* createWordCount(char *word, int count) {
    WordCount* wc = malloc(sizeof(WordCount));
    
    if (wc) {
        strncpy(wc->word, word, MAX_WORD_SIZE-1);
        wc->word[MAX_WORD_SIZE-1] = '\0';
        wc->count = count;
    }
    
    return wc;
}

void destroyWordCount(WordCount* wc) {
    if (wc) {
        free(wc);
    }
}

int compareWordCount(const void* a, const void* b) {
    const WordCount* wc1 = *(const WordCount**)a;
    const WordCount* wc2 = *(const WordCount**)b;
    
    return wc2->count - wc1->count;
}

int sanitizeWord(char *word) {
    int i = 0;
    int j = 0;
    
    while (word[i]) {
        if (isalpha(word[i])) {
            word[j++] = tolower(word[i]);
        }
        
        i++;
    }
    
    word[j] = '\0';
    
    return j > 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    FILE *fp = fopen(argv[1], "r");
    
    if (!fp) {
        printf("error: could not open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }
    
    WordCount *counts[MAX_WORDS];
    int wordCount = 0;
    
    char word[MAX_WORD_SIZE];
    
    while (fscanf(fp, "%s", word) == 1 && wordCount < MAX_WORDS) {
        if (sanitizeWord(word)) {
            int i;
            for (i = 0; i < wordCount; i++) {
                if (strcmp(counts[i]->word, word) == 0) {
                    counts[i]->count++;
                    break;
                }
            }
            
            if (i == wordCount) {
                counts[wordCount++] = createWordCount(word, 1);
            }
        }
    }
    
    fclose(fp);
    
    qsort(counts, wordCount, sizeof(WordCount*), compareWordCount);
    
    int i;
    for (i = 0; i < wordCount; i++) {
        printf("%s: %d\n", counts[i]->word, counts[i]->count);
        destroyWordCount(counts[i]);
    }
    
    return EXIT_SUCCESS;
}