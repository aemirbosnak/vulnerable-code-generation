//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 64

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(char *filename, WordCount *word_counts, int num_words) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(word_counts[i].word, word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }
            if (i == num_words) {
                if (num_words >= MAX_WORD_LENGTH) {
                    printf("Maximum number of words reached.\n");
                    exit(1);
                }
                strcpy(word_counts[num_words].word, word);
                word_counts[num_words].count = 1;
                num_words++;
            }
            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);
}

void print_word_counts(WordCount *word_counts, int num_words) {
    printf("Word counts:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    char filename[1024];
    printf("Enter filename: ");
    scanf("%s", filename);

    int num_words = 0;
    WordCount word_counts[MAX_WORD_LENGTH];

    read_file(filename, word_counts, num_words);
    print_word_counts(word_counts, num_words);

    return 0;
}