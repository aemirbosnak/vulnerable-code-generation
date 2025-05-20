//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 1024
#define MAX_WORDS 10000

typedef struct {
    char word[MAX_WORD_SIZE];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    const WordCount* w1 = (const WordCount*) a;
    const WordCount* w2 = (const WordCount*) b;
    return strcmp(w1->word, w2->word);
}

int main(int argc, char* argv[]) {
    FILE* file;
    char line[1024];
    char* word = malloc(MAX_WORD_SIZE);
    WordCount words[MAX_WORDS];
    int numWords = 0;

    if (argc < 2) {
        printf("Usage: %s file\n", argv[0]);
        exit(1);
    }

    file = fopen(argv[1], "r");
    if (!file) {
        printf("Error: could not open file\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        char* p = line;
        while ((word = strtok_r(p, " \t\r\n\f\v", &p))!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Error: too many words\n");
                exit(1);
            }
            WordCount* wc = &words[numWords++];
            strcpy(wc->word, word);
            wc->count = 1;
        }
    }

    qsort(words, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    free(word);
    fclose(file);
    return 0;
}