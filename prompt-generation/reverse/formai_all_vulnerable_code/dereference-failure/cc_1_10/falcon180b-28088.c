//Falcon-180B DATASET v1.0 Category: Text processing ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORDS 100

struct word_count {
    char *word;
    int count;
};

int main() {
    FILE *input_file;
    char line[MAX_LINE_LENGTH];
    char *word;
    struct word_count *word_counts = calloc(MAX_WORDS, sizeof(struct word_count));
    int num_words = 0;

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        word = strtok(line, " \t\n\r\f\v");
        while (word!= NULL) {
            if (num_words >= MAX_WORDS) {
                printf("Error: too many words in input file.\n");
                fclose(input_file);
                exit(1);
            }
            word_counts[num_words].word = strdup(word);
            word_counts[num_words].count = 1;
            num_words++;
            word = strtok(NULL, " \t\n\r\f\v");
        }
    }

    fclose(input_file);

    printf("Word\tCount\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", word_counts[i].word, word_counts[i].count);
    }

    for (int i = 0; i < num_words; i++) {
        free(word_counts[i].word);
    }
    free(word_counts);

    return 0;
}