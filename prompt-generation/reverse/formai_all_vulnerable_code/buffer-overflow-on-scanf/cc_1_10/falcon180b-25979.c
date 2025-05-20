//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *input_file, *output_file;
    char input_filename[MAX_WORD_LENGTH], output_filename[MAX_WORD_LENGTH];
    char line[MAX_WORD_LENGTH];
    char *word;
    WordCount words[MAX_WORDS];
    int num_words = 0;

    printf("Enter input filename: ");
    scanf("%s", input_filename);

    printf("Enter output filename: ");
    scanf("%s", output_filename);

    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, input_file)!= NULL) {
        word = strtok(line, ",.!?;:");
        while (word!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == num_words) {
                if (num_words >= MAX_WORDS) {
                    printf("Error: Too many unique words.\n");
                    exit(1);
                }
                strcpy(words[num_words].word, word);
                words[num_words].count = 1;
                num_words++;
            }
            word = strtok(NULL, ",.!?;:");
        }
    }

    fprintf(output_file, "Word count:\n");
    for (int i = 0; i < num_words; i++) {
        fprintf(output_file, "%s: %d\n", words[i].word, words[i].count);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}