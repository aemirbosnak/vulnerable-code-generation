//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *file, WordCount *word_counts, int num_word_counts) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        word[strcspn(word, "\n")] = '\0'; // remove newline character
        int i;
        for (i = 0; i < num_word_counts; i++) {
            if (strcmp(word, word_counts[i].word) == 0) {
                word_counts[i].count++;
                break;
            }
        }
        if (i == num_word_counts) { // new word
            WordCount new_word_count;
            strcpy(new_word_count.word, word);
            new_word_count.count = 1;
            word_counts[i] = new_word_count;
            num_word_counts++;
        }
    }
}

void write_file(FILE *file, WordCount *word_counts, int num_word_counts) {
    for (int i = 0; i < num_word_counts; i++) {
        fprintf(file, "%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    FILE *input_file, *output_file;
    WordCount word_counts[MAX_WORDS];
    int num_word_counts = 0;

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    num_word_counts = 0;
    while (fscanf(input_file, "%s", word_counts[num_word_counts].word)!= EOF) {
        word_counts[num_word_counts].count = 0;
        num_word_counts++;
    }

    read_file(input_file, word_counts, num_word_counts);

    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    write_file(output_file, word_counts, num_word_counts);

    fclose(input_file);
    fclose(output_file);

    return 0;
}