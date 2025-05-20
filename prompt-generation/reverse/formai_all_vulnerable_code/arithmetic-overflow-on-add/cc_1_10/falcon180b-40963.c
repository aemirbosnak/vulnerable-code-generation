//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void read_file(FILE *file, WordFrequency words[]) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            words[i].word[0] = tolower(ch);
            int j = 1;
            while (isalpha(ch = fgetc(file))) {
                words[i].word[j++] = tolower(ch);
                if (j >= MAX_WORD_LENGTH) {
                    break;
                }
            }
            words[i].word[j] = '\0';
            words[i].count++;
            i++;
        }
    }
}

void print_word_frequency(WordFrequency words[]) {
    for (int i = 0; i < MAX_NUM_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    FILE *file;
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    WordFrequency words[MAX_NUM_WORDS];
    read_file(file, words);

    fclose(file);

    print_word_frequency(words);

    return 0;
}