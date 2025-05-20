//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int main() {
    FILE *input_file, *output_file;
    char input_filename[100], output_filename[100];
    char line[MAX_WORD_LEN];
    char *word;
    WordCount words[MAX_WORDS];
    int num_words = 0;

    // Get input and output file names from user
    printf("Enter input file name: ");
    scanf("%s", input_filename);
    printf("Enter output file name: ");
    scanf("%s", output_filename);

    // Open input and output files
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

    // Read input file and count word frequencies
    while (fgets(line, MAX_WORD_LEN, input_file)!= NULL) {
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            for (int i = 0; i < num_words; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (num_words == MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                exit(1);
            }
            strcpy(words[num_words].word, word);
            words[num_words].count = 1;
            num_words++;
            word = strtok(NULL, ",.?!;:");
        }
    }

    // Sort words by frequency
    for (int i = 0; i < num_words - 1; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (words[j].count > words[i].count) {
                WordCount temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Write output file
    for (int i = 0; i < num_words; i++) {
        fprintf(output_file, "%s %d\n", words[i].word, words[i].count);
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}