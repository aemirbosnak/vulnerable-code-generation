//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

typedef struct {
    char filename[100];
    int num_words;
    WordFrequency words[MAX_WORDS];
} Ebook;

Ebook load_ebook(char* filename) {
    Ebook ebook;
    strcpy(ebook.filename, filename);
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error loading ebook: %s\n", filename);
        exit(1);
    }
    char word[MAX_WORD_LENGTH];
    int num_words = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Error: too many words in ebook\n");
            exit(1);
        }
        strcpy(ebook.words[num_words].word, word);
        ebook.words[num_words].frequency = 1;
        num_words++;
    }
    fclose(file);
    ebook.num_words = num_words;
    return ebook;
}

void print_word_frequency(WordFrequency* words, int num_words) {
    printf("Word\t\tFrequency\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\t\t%d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    char filename[100];
    printf("Enter ebook filename: ");
    scanf("%s", filename);
    Ebook ebook = load_ebook(filename);
    print_word_frequency(ebook.words, ebook.num_words);
    return 0;
}