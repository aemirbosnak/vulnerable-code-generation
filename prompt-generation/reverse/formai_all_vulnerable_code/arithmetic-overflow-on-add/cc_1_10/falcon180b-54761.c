//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int frequency;
} WordFrequency;

void read_words(char *filename, WordFrequency *words) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LEN];
    while (fscanf(fp, "%s", word)!= EOF) {
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int index = 0;
        while (index < MAX_WORDS && words[index].frequency!= 0) {
            if (strcmp(words[index].word, word) == 0) {
                words[index].frequency++;
                break;
            }
            index++;
        }
        if (index == MAX_WORDS) {
            printf("Error: maximum number of words reached\n");
            exit(1);
        } else if (strcmp(words[index].word, word)!= 0) {
            strcpy(words[index].word, word);
            words[index].frequency = 1;
        }
    }

    fclose(fp);
}

void sort_words(WordFrequency *words) {
    for (int i = 0; i < MAX_WORDS; i++) {
        for (int j = i + 1; j < MAX_WORDS; j++) {
            if (words[i].frequency < words[j].frequency) {
                WordFrequency temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void print_word_frequencies(WordFrequency *words) {
    printf("Word\tFrequency\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].frequency!= 0) {
            printf("%s\t%d\n", words[i].word, words[i].frequency);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    WordFrequency words[MAX_WORDS];
    read_words(argv[1], words);
    sort_words(words);
    print_word_frequencies(words);

    return 0;
}