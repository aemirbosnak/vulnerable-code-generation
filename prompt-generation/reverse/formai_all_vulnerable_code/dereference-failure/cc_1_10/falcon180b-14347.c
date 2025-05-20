//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE* fp, char* filename, WordCount* word_counts, int num_words) {
    char line[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        char* token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            strcpy(word, token);
            for (int j = 0; j < strlen(word); j++) {
                if (word[j] >= 'a' && word[j] <= 'z') {
                    word[j] -= 'a' - 'A';
                }
            }
            for (int j = 0; j < num_words; j++) {
                if (strcmp(word, word_counts[j].word) == 0) {
                    word_counts[j].count++;
                    break;
                }
            }
            token = strtok(NULL, ",.?!;:");
        }
    }
}

void print_word_counts(WordCount* word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <filename> <num_words>\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];
    int num_words = atoi(argv[2]);

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file '%s'.\n", filename);
        return 1;
    }

    WordCount word_counts[num_words];
    for (int i = 0; i < num_words; i++) {
        strcpy(word_counts[i].word, "");
        word_counts[i].count = 0;
    }

    read_file(fp, filename, word_counts, num_words);

    fclose(fp);
    print_word_counts(word_counts, num_words);

    return 0;
}