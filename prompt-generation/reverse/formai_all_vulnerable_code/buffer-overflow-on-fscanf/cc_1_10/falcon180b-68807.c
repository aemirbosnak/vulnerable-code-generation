//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int compare(const void* a, const void* b) {
    WordCount* w1 = (WordCount*)a;
    WordCount* w2 = (WordCount*)b;
    return strcmp(w1->word, w2->word);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char word[MAX_WORD_LEN];
    WordCount words[MAX_WORDS];
    int num_words = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Max number of words reached.\n");
            exit(1);
        }
        int len = strlen(word);
        if (len >= MAX_WORD_LEN) {
            printf("Word too long: %s\n", word);
            exit(1);
        }
        strcpy(words[num_words].word, word);
        words[num_words].count = 1;
        num_words++;
    }

    fclose(file);

    qsort(words, num_words, sizeof(WordCount), compare);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}