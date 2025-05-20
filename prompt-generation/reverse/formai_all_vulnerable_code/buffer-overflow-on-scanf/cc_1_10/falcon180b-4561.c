//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} word_frequency;

int compare_words(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void read_file(FILE *file, word_frequency *words, int num_words) {
    char word[MAX_WORD_LENGTH];
    char ch;
    int index = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            word[index] = tolower(ch);
            index++;
        } else if (index > 0) {
            word[index] = '\0';
            for (int i = 0; i < num_words; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
        } else {
            index = 0;
        }
    }
    if (index > 0) {
        word[index] = '\0';
        for (int i = 0; i < num_words; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }
    }
}

void print_word_frequency(word_frequency *words, int num_words) {
    qsort(words, num_words, sizeof(word_frequency), compare_words);
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    char filename[100];
    printf("Enter the name of the file to analyze: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    word_frequency words[MAX_NUM_WORDS];
    int num_words = 0;

    read_file(file, words, MAX_NUM_WORDS);
    fclose(file);

    print_word_frequency(words, num_words);

    return 0;
}