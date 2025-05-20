//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void read_file(FILE* file, WordFrequency* words, int* num_words) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        for (int i = 0; i < *num_words; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].frequency++;
                return;
            }
        }
        if (*num_words >= MAX_WORDS) {
            printf("Error: Maximum number of words reached.\n");
            exit(1);
        }
        strcpy(words[*num_words].word, word);
        words[*num_words].frequency = 1;
        (*num_words)++;
    }
}

void sort_words(WordFrequency* words, int num_words) {
    for (int i = 0; i < num_words - 1; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (words[j].frequency > words[i].frequency) {
                WordFrequency temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void print_words(WordFrequency* words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    WordFrequency words[MAX_WORDS];
    int num_words = 0;
    read_file(file, words, &num_words);
    fclose(file);
    sort_words(words, num_words);
    print_words(words, num_words);
    return 0;
}