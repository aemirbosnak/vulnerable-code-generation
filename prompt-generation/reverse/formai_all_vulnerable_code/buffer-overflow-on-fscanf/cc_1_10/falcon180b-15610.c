//Falcon-180B DATASET v1.0 Category: Educational ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

struct word_count {
    char word[50];
    int count;
};

void read_file(FILE *fp, struct word_count *word_counts, int *num_words) {
    char word[50];
    while (fscanf(fp, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < *num_words; i++) {
            if (strcmp(word_counts[i].word, word) == 0) {
                word_counts[i].count++;
                break;
            }
        }
        if (i == *num_words) {
            strcpy(word_counts[*num_words].word, word);
            word_counts[*num_words].count = 1;
            (*num_words)++;
        }
    }
}

void write_file(FILE *fp, struct word_count *word_counts, int num_words) {
    fprintf(fp, "Word\tCount\n");
    for (int i = 0; i < num_words; i++) {
        fprintf(fp, "%s\t%d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    FILE *input_file, *output_file;
    char input_filename[100], output_filename[100];
    struct word_count word_counts[MAX_WORDS];
    int num_words = 0;

    printf("Enter input file name: ");
    scanf("%s", input_filename);
    printf("Enter output file name: ");
    scanf("%s", output_filename);

    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file\n");
        fclose(input_file);
        exit(1);
    }

    read_file(input_file, word_counts, &num_words);

    fclose(input_file);
    fclose(output_file);

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    write_file(output_file, word_counts, num_words);

    fclose(output_file);

    return 0;
}