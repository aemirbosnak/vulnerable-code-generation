//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void read_words(FILE *input_file, WordFrequency words[]) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(input_file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            if (!isalpha(word[i])) {
                word[i] = '\0';
            }
        }
        int j;
        for (j = 0; j < MAX_WORDS; j++) {
            if (strcmp(word, words[j].word) == 0) {
                words[j].frequency++;
                break;
            }
        }
        if (j == MAX_WORDS) {
            strcpy(words[j].word, word);
            words[j].frequency = 1;
        }
    }
}

void sort_words(WordFrequency words[]) {
    int i, j;
    for (i = 0; i < MAX_WORDS - 1; i++) {
        for (j = i + 1; j < MAX_WORDS; j++) {
            if (words[j].frequency > words[i].frequency) {
                WordFrequency temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void print_words(WordFrequency words[]) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, "")!= 0) {
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening file '%s'.\n", argv[1]);
        return 1;
    }
    WordFrequency words[MAX_WORDS];
    read_words(input_file, words);
    sort_words(words);
    print_words(words);
    fclose(input_file);
    return 0;
}