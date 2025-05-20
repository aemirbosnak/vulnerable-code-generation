//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: real-life
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

bool is_word(char *word) {
    int i;
    for (i = 0; word[i]!= '\0'; i++) {
        if (!isalpha(word[i])) {
            return false;
        }
    }
    return true;
}

bool is_abbreviation(char *word) {
    int i;
    for (i = 0; word[i]!= '\0'; i++) {
        if (!isalpha(word[i])) {
            return false;
        }
    }
    return strlen(word) < 5;
}

bool is_number(char *word) {
    int i;
    for (i = 0; word[i]!= '\0'; i++) {
        if (!isdigit(word[i])) {
            return false;
        }
    }
    return true;
}

int compare_words(const void *a, const void *b) {
    Word *word1 = (Word *)a;
    Word *word2 = (Word *)b;
    return strcmp(word1->word, word2->word);
}

int main() {
    FILE *dictionary = fopen("dictionary.txt", "r");
    if (dictionary == NULL) {
        printf("Error: cannot open dictionary file.\n");
        exit(1);
    }

    Word words[MAX_WORDS];
    int num_words = 0;
    char word[MAX_WORD_LENGTH];

    while (fscanf(dictionary, "%s", word)!= EOF) {
        if (is_word(word)) {
            if (is_abbreviation(word)) {
                printf("Abbreviation: %s\n", word);
            } else if (is_number(word)) {
                printf("Number: %s\n", word);
            } else {
                printf("Word: %s\n", word);
            }
        } else {
            printf("Invalid character: %c\n", word[0]);
        }
        num_words++;
        if (num_words >= MAX_WORDS) {
            printf("Maximum number of words reached.\n");
            break;
        }
    }

    fclose(dictionary);
    qsort(words, num_words, sizeof(Word), compare_words);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}