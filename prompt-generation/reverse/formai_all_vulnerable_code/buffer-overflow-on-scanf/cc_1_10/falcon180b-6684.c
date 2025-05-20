//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *input_file, *output_file;
    char input_filename[MAX_WORD_LENGTH], output_filename[MAX_WORD_LENGTH];
    char line[MAX_WORD_LENGTH];
    WordCount words[MAX_WORDS];
    int num_words = 0;
    int i;

    printf("Enter the input file name: ");
    scanf("%s", input_filename);

    printf("Enter the output file name: ");
    scanf("%s", output_filename);

    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, input_file)!= NULL) {
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            for (i = 0; i < num_words; i++) {
                if (strcmp(words[i].word, word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == num_words) {
                if (num_words >= MAX_WORDS) {
                    printf("Error: Maximum number of words reached.\n");
                    fclose(input_file);
                    fclose(output_file);
                    exit(1);
                }
                strcpy(words[num_words].word, word);
                words[num_words].count = 1;
                num_words++;
            }
            word = strtok(NULL, ",.?!;:");
        }
    }

    for (i = 0; i < num_words; i++) {
        fprintf(output_file, "%s: %d\n", words[i].word, words[i].count);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}