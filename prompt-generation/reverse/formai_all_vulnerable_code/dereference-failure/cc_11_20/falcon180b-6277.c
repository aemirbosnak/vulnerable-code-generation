//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000 // maximum number of words to store

typedef struct {
    char word[50];
    int count;
} word_t;

int main() {
    FILE *input_file, *output_file;
    char input_filename[100], output_filename[100];
    word_t words[MAX_WORDS];
    int num_words = 0;

    printf("Enter input file name: ");
    scanf("%s", input_filename);

    printf("Enter output file name: ");
    scanf("%s", output_filename);

    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    char line[100];
    while (fgets(line, 100, input_file)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            for (int i = 0; i < num_words; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (num_words >= MAX_WORDS) {
                printf("Error: maximum number of words reached.\n");
                exit(1);
            }
            strcpy(words[num_words].word, word);
            words[num_words].count = 1;
            num_words++;
            word = strtok(NULL, " ");
        }
    }

    printf("Enter the number of words to display in the summary: ");
    int num_summary_words;
    scanf("%d", &num_summary_words);

    printf("Enter the minimum frequency of words to include in the summary: ");
    int min_frequency;
    scanf("%d", &min_frequency);

    for (int i = 0; i < num_words; i++) {
        if (words[i].count >= min_frequency) {
            fprintf(output_file, "%s %d\n", words[i].word, words[i].count);
        }
    }

    for (int i = 0; i < num_summary_words && i < num_words; i++) {
        fprintf(stdout, "%s %d\n", words[i].word, words[i].count);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}