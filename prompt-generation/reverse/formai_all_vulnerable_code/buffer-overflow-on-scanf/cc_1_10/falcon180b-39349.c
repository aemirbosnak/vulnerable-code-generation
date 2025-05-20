//Falcon-180B DATASET v1.0 Category: Text processing ; Style: minimalist
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *file, WordCount *word_counts, int num_word_counts) {
    char word[MAX_WORD_LENGTH];
    int i;

    while (fscanf(file, "%s", word)!= EOF) {
        for (i = 0; i < num_word_counts; i++) {
            if (strcmp(word, word_counts[i].word) == 0) {
                word_counts[i].count++;
                break;
            }
        }
        if (i == num_word_counts) {
            strcpy(word_counts[i].word, word);
            word_counts[i].count = 1;
            num_word_counts++;
        }
    }
}

void print_word_counts(WordCount *word_counts, int num_word_counts) {
    int i;

    for (i = 0; i < num_word_counts; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    FILE *file;
    char filename[100];
    WordCount word_counts[10];
    int num_word_counts = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    read_file(file, word_counts, num_word_counts);

    fclose(file);

    printf("Word counts:\n");
    print_word_counts(word_counts, num_word_counts);

    return 0;
}