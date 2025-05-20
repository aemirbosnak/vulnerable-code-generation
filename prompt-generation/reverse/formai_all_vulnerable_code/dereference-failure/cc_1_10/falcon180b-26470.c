//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

void read_file(FILE *file, char *filename, struct word_count words[]) {
    char line[1024];
    char *token;
    int i = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            if (strlen(token) > 0) {
                if (i >= MAX_NUM_WORDS) {
                    printf("Error: Maximum number of words reached.\n");
                    exit(1);
                }
                strcpy(words[i].word, token);
                words[i].count = 1;
                i++;
            }
            token = strtok(NULL, ",.?!;:");
        }
    }
}

void display_results(struct word_count words[], int num_words) {
    printf("Word\tCount\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <output_file>\n", argv[0]);
        exit(1);
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Cannot open input file.\n");
        exit(1);
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Cannot open output file.\n");
        exit(1);
    }

    struct word_count words[MAX_NUM_WORDS];
    int num_words = 0;

    read_file(input_file, argv[1], words);
    display_results(words, num_words);

    fprintf(output_file, "Total words: %d\n", num_words);
    for (int i = 0; i < num_words; i++) {
        fprintf(output_file, "%s: %d\n", words[i].word, words[i].count);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}