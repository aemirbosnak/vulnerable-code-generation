//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void read_file(FILE* fp, WordCount words[], int* num_words) {
    char line[MAX_WORD_LEN];
    char* word;
    int i = 0;

    while (fgets(line, MAX_WORD_LEN, fp)) {
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            if (i >= *num_words) {
                printf("Error: Maximum number of words reached.\n");
                exit(1);
            }
            strcpy(words[i].word, word);
            words[i].count = 1;
            i++;
            word = strtok(NULL, ",.?!;:");
        }
    }
}

void write_file(FILE* fp, WordCount words[], int num_words) {
    int i;

    for (i = 0; i < num_words; i++) {
        if (words[i].count > 0) {
            fprintf(fp, "%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    FILE* input_file;
    FILE* output_file;
    WordCount words[MAX_WORDS];
    int num_words = 0;

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Input file not found.\n");
        exit(1);
    }

    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error: Output file could not be created.\n");
        exit(1);
    }

    read_file(input_file, words, &num_words);

    write_file(output_file, words, num_words);

    fclose(input_file);
    fclose(output_file);

    return 0;
}