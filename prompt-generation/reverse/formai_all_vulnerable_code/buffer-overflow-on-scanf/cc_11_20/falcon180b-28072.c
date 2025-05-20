//Falcon-180B DATASET v1.0 Category: Data mining ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int main() {
    char input_file[MAX_WORD_LENGTH];
    char output_file[MAX_WORD_LENGTH];
    char line[MAX_WORD_LENGTH];
    FILE *input_fp, *output_fp;
    WordFrequency words[MAX_WORDS];
    int num_words = 0;
    int i;

    // Get input file name from user
    printf("Enter input file name: ");
    scanf("%s", input_file);

    // Open input file for reading
    input_fp = fopen(input_file, "r");
    if (input_fp == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Count frequency of each word in input file
    while (fgets(line, MAX_WORD_LENGTH, input_fp)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            for (i = 0; i < num_words; i++) {
                if (strcmp(words[i].word, word) == 0) {
                    words[i].frequency++;
                    break;
                }
            }
            if (i == num_words) {
                // Add new word to array
                strcpy(words[num_words].word, word);
                words[num_words].frequency = 1;
                num_words++;
            }
            word = strtok(NULL, " ");
        }
    }

    // Sort words by frequency
    for (i = 0; i < num_words - 1; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (words[j].frequency > words[i].frequency) {
                WordFrequency temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Get output file name from user
    printf("Enter output file name: ");
    scanf("%s", output_file);

    // Open output file for writing
    output_fp = fopen(output_file, "w");
    if (output_fp == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Write word frequencies to output file
    for (i = 0; i < num_words; i++) {
        fprintf(output_fp, "%s %d\n", words[i].word, words[i].frequency);
    }

    // Close files
    fclose(input_fp);
    fclose(output_fp);

    return 0;
}