//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void read_file(FILE *file, WordFrequency words[], int *word_count) {
    char ch;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            char word[MAX_WORD_LENGTH];
            int length = 0;
            while (isalpha(ch)) {
                word[length++] = tolower(ch);
                ch = fgetc(file);
            }
            word[length] = '\0';

            for (int i = 0; i < *word_count; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].frequency++;
                    break;
                }
            }
        }
    }
}

void sort_words(WordFrequency words[], int word_count) {
    for (int i = 0; i < word_count - 1; i++) {
        for (int j = i + 1; j < word_count; j++) {
            if (words[j].frequency > words[i].frequency) {
                WordFrequency temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void print_words(WordFrequency words[], int word_count) {
    for (int i = 0; i < word_count; i++) {
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
        printf("Error: Could not open file.\n");
        return 1;
    }

    int word_count = 0;
    WordFrequency words[MAX_WORDS];
    while (word_count < MAX_WORDS && fscanf(file, "%s", words[word_count].word)!= EOF) {
        word_count++;
    }

    fclose(file);

    read_file(file, words, &word_count);

    sort_words(words, word_count);

    print_words(words, word_count);

    return 0;
}