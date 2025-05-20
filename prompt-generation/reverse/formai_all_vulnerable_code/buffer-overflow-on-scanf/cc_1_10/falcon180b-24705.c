//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *file, WordCount *word_counts, int num_words) {
    char line[1000];
    char *token;
    int i = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            if (i >= num_words) {
                break;
            }
            strcpy(word_counts[i].word, token);
            word_counts[i].count = 1;
            i++;
            token = strtok(NULL, ",.?!;:");
        }
    }
}

void print_word_counts(WordCount *word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        if (word_counts[i].count > 0) {
            printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
        }
    }
}

int main() {
    FILE *file;
    char filename[100];
    WordCount word_counts[MAX_WORDS];
    int num_words = 0;

    printf("Enter file name: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    read_file(file, word_counts, num_words);
    fclose(file);

    printf("Word counts:\n");
    print_word_counts(word_counts, num_words);

    return 0;
}