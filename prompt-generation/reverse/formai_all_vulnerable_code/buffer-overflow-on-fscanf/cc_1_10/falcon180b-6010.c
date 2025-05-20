//Falcon-180B DATASET v1.0 Category: Data mining ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void read_words(char* filename, WordFrequency* word_frequencies) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word_frequencies[i].word, word) == 0) {
                word_frequencies[i].frequency++;
                break;
            }
        }
        if (i == MAX_WORDS) {
            printf("Maximum number of words reached\n");
            break;
        }
    }

    fclose(file);
}

void sort_word_frequencies(WordFrequency* word_frequencies) {
    int i, j;
    for (i = 0; i < MAX_WORDS - 1; i++) {
        for (j = i + 1; j < MAX_WORDS; j++) {
            if (word_frequencies[j].frequency > word_frequencies[i].frequency) {
                WordFrequency temp = word_frequencies[i];
                word_frequencies[i] = word_frequencies[j];
                word_frequencies[j] = temp;
            }
        }
    }
}

void print_top_n_words(int n, WordFrequency* word_frequencies) {
    printf("Top %d most frequent words:\n", n);
    for (int i = 0; i < n && i < MAX_WORDS; i++) {
        printf("%s: %d\n", word_frequencies[i].word, word_frequencies[i].frequency);
    }
}

int main() {
    char filename[50];
    printf("Enter filename: ");
    scanf("%s", filename);

    WordFrequency word_frequencies[MAX_WORDS];
    read_words(filename, word_frequencies);

    sort_word_frequencies(word_frequencies);

    int n;
    printf("Enter number of top words to print: ");
    scanf("%d", &n);

    print_top_n_words(n, word_frequencies);

    return 0;
}