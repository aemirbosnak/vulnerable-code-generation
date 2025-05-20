//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

typedef struct {
    char word[WORD_LENGTH];
    int count;
} Word;

void count_words(char *input, Word words[]) {
    int current_word = 0;
    int length = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (isspace(input[i])) {
            if (length > 0) {
                words[current_word].count++;
                current_word++;
                if (current_word >= MAX_WORDS) {
                    printf("Error: too many words\n");
                    exit(1);
                }
                length = 0;
            }
        } else {
            if (length >= WORD_LENGTH - 1) {
                printf("Error: word too long\n");
                exit(1);
            }
            words[current_word].word[length] = input[i];
            length++;
        }
    }

    if (length > 0) {
        words[current_word].count++;
        current_word++;
    }
}

void print_words(Word words[], int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    char input[1024];
    Word words[MAX_WORDS];

    printf("Enter text: ");
    fgets(input, sizeof(input), stdin);

    count_words(input, words);

    int num_words = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            num_words++;
        }
    }

    printf("\nWord count:\n");
    print_words(words, num_words);

    return 0;
}