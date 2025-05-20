//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int frequency;
} WordFrequency;

void read_file(FILE *file, char *word) {
    char ch;
    int i = 0;
    bool in_word = false;

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            if (!in_word) {
                strcpy(word, "");
                in_word = true;
            }
            strcat(word, tolower(ch));
        } else {
            if (in_word) {
                word[i] = '\0';
                in_word = false;
            }
        }
    }

    if (in_word) {
        word[i] = '\0';
    }
}

int compare_words(const void *a, const void *b) {
    const WordFrequency *w1 = a;
    const WordFrequency *w2 = b;

    return strcmp(w1->word, w2->word);
}

int main() {
    FILE *file;
    char word[MAX_WORD_LENGTH + 1];
    WordFrequency words[MAX_WORDS];
    int num_words = 0;
    int i;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        read_file(file, word);
        for (i = 0; i < num_words; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].frequency++;
                break;
            }
        }
        if (i == num_words) {
            strcpy(words[num_words].word, word);
            words[num_words].frequency = 1;
            num_words++;
        }
    }

    fclose(file);

    qsort(words, num_words, sizeof(WordFrequency), compare_words);

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }

    return 0;
}