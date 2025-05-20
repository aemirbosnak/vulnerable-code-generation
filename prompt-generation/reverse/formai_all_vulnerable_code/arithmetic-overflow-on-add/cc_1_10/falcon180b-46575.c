//Falcon-180B DATASET v1.0 Category: Data mining ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compare_frequency(const void *a, const void *b) {
    const WordFrequency *w1 = a;
    const WordFrequency *w2 = b;
    if (w1->frequency > w2->frequency) {
        return -1;
    } else if (w1->frequency < w2->frequency) {
        return 1;
    } else {
        return 0;
    }
}

void read_words(FILE *file, WordFrequency words[MAX_WORDS]) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < MAX_WORDS - 1 && words[i].frequency > 0; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].frequency++;
                break;
            }
        }
        if (i == MAX_WORDS - 1) {
            printf("Too many unique words.\n");
            exit(1);
        } else if (strcmp(word, "")!= 0) {
            strcpy(words[i].word, word);
            words[i].frequency = 1;
        }
    }
}

void write_words(const WordFrequency words[MAX_WORDS]) {
    qsort(words, MAX_WORDS, sizeof(WordFrequency), compare_frequency);
    printf("Word frequencies:\n");
    for (int i = 0; i < MAX_WORDS && words[i].frequency > 0; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    WordFrequency words[MAX_WORDS];
    read_words(file, words);
    fclose(file);
    write_words(words);
    return 0;
}