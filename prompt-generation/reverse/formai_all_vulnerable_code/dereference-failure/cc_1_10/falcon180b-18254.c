//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_CHARS 100

typedef struct {
    char word[MAX_CHARS];
    int count;
} WordCount;

int compare(const void* a, const void* b) {
    WordCount* wc1 = (WordCount*)a;
    WordCount* wc2 = (WordCount*)b;
    return strcmp(wc1->word, wc2->word);
}

void read_words(char* filename, WordCount* words) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_CHARS];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < MAX_WORDS - 1 && words[i].word[0]!= '\0'; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == MAX_WORDS - 1) {
            printf("Error: too many unique words in file\n");
            exit(1);
        } else if (words[i].word[0] == '\0') {
            strcpy(words[i].word, word);
            words[i].count = 1;
        }
    }

    fclose(file);

    qsort(words, MAX_WORDS, sizeof(WordCount), compare);
}

void print_words(WordCount* words) {
    for (int i = 0; i < MAX_WORDS && words[i].word[0]!= '\0'; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char filename[MAX_CHARS];
    strcpy(filename, argv[1]);

    WordCount words[MAX_WORDS];
    read_words(filename, words);

    print_words(words);

    return 0;
}