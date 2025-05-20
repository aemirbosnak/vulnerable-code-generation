//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the maximum number of words that can be stored in memory
#define MAX_WORDS 1000

// Define the structure for each word
typedef struct {
    char word[50];
    int frequency;
} Word;

// Function to compare two words based on their frequency
int compare_words(const void *a, const void *b) {
    const Word *word1 = a;
    const Word *word2 = b;

    if (word1->frequency > word2->frequency) {
        return -1;
    } else if (word1->frequency < word2->frequency) {
        return 1;
    } else {
        return 0;
    }
}

// Function to read words from a file and store them in memory
void read_words_from_file(FILE *file, Word words[]) {
    char word[50];
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Maximum number of words exceeded.\n");
            exit(1);
        }

        strcpy(words[i].word, word);
        words[i].frequency = 1;
        i++;
    }
}

// Function to print the top 10 most frequent words
void print_top_words(Word words[], int n) {
    qsort(words, n, sizeof(Word), compare_words);

    printf("Top 10 most frequent words:\n");
    for (int i = 0; i < 10 && i < n; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    Word words[MAX_WORDS];
    read_words_from_file(file, words);

    print_top_words(words, MAX_WORDS);

    fclose(file);
    return 0;
}