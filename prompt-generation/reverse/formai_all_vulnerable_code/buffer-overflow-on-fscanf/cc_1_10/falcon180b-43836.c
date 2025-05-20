//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_words(FILE *file, WordCount *word_counts) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        if (strlen(word) > 0) {
            int j;
            for (j = 0; j < MAX_WORDS; j++) {
                if (strcmp(word, word_counts[j].word) == 0) {
                    word_counts[j].count++;
                    break;
                }
            }
            if (j == MAX_WORDS) {
                if (word_counts[0].word[0] == '\0') {
                    strcpy(word_counts[0].word, word);
                } else {
                    printf("Max number of words reached!\n");
                }
            }
        }
    }
}

void print_word_counts(WordCount *word_counts) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (word_counts[i].word[0]!= '\0') {
            printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
        }
    }
}

int main() {
    FILE *file;
    char filename[100];
    WordCount word_counts[MAX_WORDS];
    int i;

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("Reading words...\n");
    read_words(file, word_counts);

    printf("Printing word counts...\n");
    print_word_counts(word_counts);

    fclose(file);

    return 0;
}