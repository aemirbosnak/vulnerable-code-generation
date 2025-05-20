//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: sophisticated
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 10000

struct Word {
    char word[MAX_WORD_LENGTH];
    int count;
};

int read_words(char *filename, struct Word words[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Cannot open file %s\n", filename);
        exit(1);
    }

    int num_words = 0;
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) == 1) {
        // Convert word to lowercase
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }

        if (num_words == MAX_WORDS) {
            printf("Maximum number of words reached (%d)\n", MAX_WORDS);
            break;
        }

        // Check if word already exists in array
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].count++;
                break;
            }
        }

        // Add new word to array
        if (i == num_words) {
            strcpy(words[num_words].word, word);
            words[num_words].count = 1;
            num_words++;
        }
    }

    fclose(file);
    return num_words;
}

void print_words(struct Word words[], int num_words) {
    printf("Word frequency count:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%10s : %5d\n", words[i].word, words[i].count);
    }
}

int main() {
    char filename[] = "input.txt";
    struct Word words[MAX_WORDS];
    int num_words = read_words(filename, words);
    print_words(words, num_words);
    return 0;
}