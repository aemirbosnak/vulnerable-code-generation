//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void read_file(FILE *file, WordFrequency *word_frequency) {
    char line[MAX_WORD_LENGTH];
    char *word = strtok(line, ",.?!;:");
    while (word!= NULL) {
        word = strtok(NULL, ",.?!;:");
        if (word!= NULL) {
            char *temp_word = strtok(word, "-");
            while (temp_word!= NULL) {
                temp_word = strtok(NULL, "-");
                if (temp_word!= NULL) {
                    strcpy(word_frequency->word, temp_word);
                    word_frequency->count++;
                }
            }
        }
    }
}

void write_file(FILE *file, WordFrequency *word_frequency) {
    fprintf(file, "Word\tCount\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        if (word_frequency[i].count > 0) {
            fprintf(file, "%s\t%d\n", word_frequency[i].word, word_frequency[i].count);
        }
    }
}

int main() {
    FILE *input_file, *output_file;
    WordFrequency word_frequency[MAX_WORDS];
    int num_words = 0;
    char input_file_name[MAX_WORD_LENGTH], output_file_name[MAX_WORD_LENGTH];

    // Get input file name from user
    printf("Enter input file name: ");
    scanf("%s", input_file_name);

    // Open input file
    input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Error: Input file not found.\n");
        return 1;
    }

    // Read input file and store word frequencies
    read_file(input_file, word_frequency);

    // Get output file name from user
    printf("Enter output file name: ");
    scanf("%s", output_file_name);

    // Open output file
    output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Error: Output file not found.\n");
        return 1;
    }

    // Write word frequencies to output file
    write_file(output_file, word_frequency);

    // Close files
    fclose(input_file);
    fclose(output_file);

    return 0;
}