//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    int count;
} WordFrequency;

void read_words(FILE *file, char *words[], int *num_words) {
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= *num_words - 1) {
            *num_words += 10;
            words = realloc(words, sizeof(char *) * *num_words);
        }

        words[i] = strdup(word);
        i++;
    }
}

void count_words(char *text, WordFrequency *frequencies, int num_words) {
    int i, j;
    char word[MAX_WORD_LENGTH];

    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            word[0] = text[i];
            j = 1;

            while (isalnum(text[i + j])) {
                word[j] = text[i + j];
                j++;
            }

            word[j] = '\0';

            for (int k = 0; k < num_words; k++) {
                if (strcmp(word, frequencies[k].word) == 0) {
                    frequencies[k].count++;
                    break;
                }
            }
        }
    }
}

void print_frequencies(WordFrequency *frequencies, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", frequencies[i].word, frequencies[i].count);
    }
}

int main() {
    char *words[MAX_WORDS];
    int num_words = 0;

    FILE *dictionary = fopen("dictionary.txt", "r");
    if (dictionary == NULL) {
        printf("Error: could not open dictionary file.\n");
        return 1;
    }

    read_words(dictionary, words, &num_words);
    fclose(dictionary);

    char *text;
    printf("Enter text to check spelling:\n");
    if (fgets(text, MAX_WORD_LENGTH, stdin) == NULL) {
        printf("Error: could not read input text.\n");
        return 1;
    }

    WordFrequency frequencies[num_words];
    count_words(text, frequencies, num_words);

    printf("Word frequencies:\n");
    print_frequencies(frequencies, num_words);

    return 0;
}