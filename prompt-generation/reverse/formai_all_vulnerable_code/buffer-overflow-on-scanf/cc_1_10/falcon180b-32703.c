//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void read_file(FILE *file, char *filename) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            if (i < MAX_WORD_LENGTH) {
                filename[i++] = tolower(ch);
            }
        } else {
            filename[i] = '\0';
            i = 0;
        }
    }
}

void count_words(char *filename, WordFrequency *word_freq, int num_words) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }
    int i = 0;
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= num_words) {
            break;
        }
        word[strcspn(word, "\n")] = '\0';
        strcpy(word_freq[i].word, word);
        word_freq[i].count = 1;
        i++;
    }
    fclose(file);
}

void display_frequencies(WordFrequency *word_freq, int num_words) {
    for (int i = 0; i < num_words; i++) {
        if (word_freq[i].count > 0) {
            printf("%s: %d\n", word_freq[i].word, word_freq[i].count);
        }
    }
}

int main() {
    char filename[MAX_WORD_LENGTH];
    printf("Enter the filename: ");
    scanf("%s", filename);
    int num_words = 0;
    while (num_words < MAX_WORDS && scanf("%s", filename + strlen(filename))!= EOF) {
        num_words++;
    }
    WordFrequency word_freq[MAX_WORDS];
    count_words(filename, word_freq, num_words);
    display_frequencies(word_freq, num_words);
    return 0;
}