//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int frequency;
} WordFrequency;

void read_file(FILE* file, WordFrequency* words) {
    char ch;
    int in_word = 0;
    int word_len = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            if (!in_word) {
                in_word = 1;
                word_len = 0;
            }
            words[word_len++].word[word_len - 1] = tolower(ch);
        } else {
            in_word = 0;
            word_len = 0;
        }
    }
}

void count_words(WordFrequency* words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        words[i].frequency = 0;
    }

    for (int i = 0; i < num_words; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].frequency += words[j].frequency;
                words[j].frequency = 0;
            }
        }
    }
}

void print_word_frequencies(WordFrequency* words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        if (words[i].frequency > 0) {
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }
}

int main() {
    FILE* file = fopen("example.txt", "r");
    WordFrequency words[MAX_WORDS];

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int num_words = 0;
    while (fscanf(file, "%s", words[num_words].word)!= EOF) {
        num_words++;
    }

    read_file(file, words);
    count_words(words, num_words);
    print_word_frequencies(words, num_words);

    fclose(file);
    return 0;
}