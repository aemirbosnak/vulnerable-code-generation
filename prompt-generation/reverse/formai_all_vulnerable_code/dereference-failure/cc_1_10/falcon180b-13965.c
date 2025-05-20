//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: complex
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct Word {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

void read_file(FILE* file, Word words[]);
void count_words(Word words[], int num_words);
void print_word_counts(Word words[], int num_words);

int main() {
    FILE* file;
    Word words[MAX_WORDS];
    int num_words = 0;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    read_file(file, words);
    count_words(words, num_words);
    print_word_counts(words, num_words);

    fclose(file);
    return 0;
}

void read_file(FILE* file, Word words[]) {
    char ch;
    int i = 0;
    Word* curr_word = &words[i];

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            curr_word->word[0] = tolower(ch);
            curr_word->count = 1;
            curr_word->word[1] = '\0';
        } else if (isalnum(ch)) {
            strcat(curr_word->word, &ch);
            curr_word->count++;
        } else if (curr_word->word[0]!= '\0') {
            i++;
            curr_word = &words[i];
            curr_word->word[0] = tolower(ch);
            curr_word->count = 1;
            curr_word->word[1] = '\0';
        }
    }
}

void count_words(Word words[], int num_words) {
    int i;

    for (i = 0; i < num_words; i++) {
        if (words[i].word[0]!= '\0') {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

void print_word_counts(Word words[], int num_words) {
    int i;

    for (i = 0; i < num_words; i++) {
        if (words[i].word[0]!= '\0') {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}