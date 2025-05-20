//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void read_words(FILE *file, WordFrequency *word_frequency) {
    char word[MAX_WORD_LENGTH];
    int i = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Maximum number of words reached.\n");
            exit(1);
        }
        strcpy(word_frequency[i].word, word);
        word_frequency[i].frequency = 1;
        i++;
    }
}

void count_words(WordFrequency *word_frequency) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (word_frequency[i].frequency > 0) {
            printf("%s: %d\n", word_frequency[i].word, word_frequency[i].frequency);
        }
    }
}

int main() {
    FILE *file;
    char filename[MAX_WORD_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }
    WordFrequency word_frequency[MAX_WORDS];
    read_words(file, word_frequency);
    count_words(word_frequency);
    fclose(file);
    return 0;
}