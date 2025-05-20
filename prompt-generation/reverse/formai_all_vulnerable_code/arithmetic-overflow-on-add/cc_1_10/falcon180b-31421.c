//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void read_file(FILE *file, WordFrequency words[]) {
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        int i = 0;
        while (isspace(line[i])) {
            i++;
        }
        int j = 0;
        while (line[i]!= '\0' &&!isspace(line[i])) {
            words[j].word[i] = tolower(line[i]);
            i++;
            j++;
        }
        words[j].word[i] = '\0';
        words[j].count++;
    }
}

void print_word_frequency(WordFrequency words[], int num_words) {
    printf("Word\t\tFrequency\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\t\t%d\n", words[i].word, words[i].count);
    }
}

int main() {
    FILE *file;
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    WordFrequency words[MAX_WORDS];
    int num_words = 0;
    read_file(file, words);
    fclose(file);
    print_word_frequency(words, num_words);
    return 0;
}